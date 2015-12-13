/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Game.cpp
 * Author: Max
 * 
 * Created on November 17, 2015, 2:21 PM
 */

#include <SFML/Graphics.hpp>

#include <iostream>
#include <cstdio>
#include <time.h>
#include <cmath>
#include <algorithm> 

#include "Game.h"
#include "Player.h"
#include "ResourceManager.h"
#include "WeaponManager.h"
#include "GameScene.h"
#include "MenuScene.h"
#include "ShopScene.h"

Game::Game() {
    srand(time(NULL));
    gen = MapGenerator();
    loader = MapLoader();
     
    scenes[MENUSCENE] = new MenuScene();
    scenes[GAMESCENE] = new GameScene();
    scenes[SHOPSCENE] = new ShopScene();
    
    map = loader.fromFile("maps/map.mb");
    
    addPlayer("JERE");
    addPlayer("JERE2");
    
    WeaponManager& wepMan = WeaponManager::getInstance();
    wepMan.createWeapons();
    for (auto& p : players) {
        // Giev some start money to buy first weapons with
        p.incrementMoney(500);
        wepMan.addWeaponsToPlayer(p); 
    }
    //this->startRound();
}

void Game::startRound() {
    round++;
    roundEnded = false;
    roundClock.restart();
    roundTime = sf::seconds(100);
    //map = loader.fromFile("maps/map.mb");
    map = gen.generate();
    
    startPositions.clear();
    startPositions.push_back(sf::Vector2u(1, 1));
    startPositions.push_back(sf::Vector2u(1, map.getSize().y - 2));
    startPositions.push_back(sf::Vector2u(map.getSize().x - 2, map.getSize().y - 2));
    startPositions.push_back(sf::Vector2u(map.getSize().x - 2, 1));
     
    sf::Vector2u windowSize = map.getSize();
    overlayImage.create(windowSize.x * 16, windowSize.y * 16, sf::Color(0, 0, 0, 255));
    
    setRandomTreasures(50);
    
    ResourceManager::getInstance().playMusic("game");
}

void Game::endRound(bool switchToShop) {
    if (switchToShop) {
        setScene(SHOPSCENE);
        players.clear();
        treasures.clear();
        effects.clear();
        //projectiles.clear();
    } else {
        roundEndClock.restart();
        roundEnded = true;
    }
}

bool Game::roundHasEnded() {
    return roundEnded;
}

Game::~Game() {
}

sf::Vector2u Game::getCanvasSize() {
    sf::Vector2u s = map.getSize();
    return sf::Vector2u(s.x * 16, s.y * 16 + 100);
}

void Game::onPlayerDead() {
    endRound();
}

std::vector<Player>& Game::getPlayers() {
    return players;
}

bool sortPlayersByScore (Player a, Player b) {
    return a.getScore() > b.getScore();
}

std::vector<Player> Game::getPlayersSortedByScore() {
    std::vector<Player> players = this->players;
    std::sort(players.begin(), players.end(), sortPlayersByScore);
    return players;
}


Scene* Game::getScene() {
    return currentScene;
}

sf::Time Game::getRoundRemainingTime() const {
    return (roundTime - roundClock.getElapsedTime());
}

int Game::getRound() {
    return round;
}

int Game::getTotalRounds() {
    return totalRounds;
}


void Game::setScene(SceneType scene) {
    currentScene = scenes.at(scene);
    currentScene->onChangedTo();
}

Map& Game::getMap() {
    return map;
}

bool Game::isEmpty(sf::Vector2u pos) {
    if(map.getTile(pos).getType() != FLOOR) {
        return false;
    }
    
    for(auto& i : players) {
        if(i.getPos() == pos)
            return false;
    }
    
    return true;
}

bool Game::addTreasure(Treasure& treasure) {
    if(isEmpty(treasure.getPosition())) {
        treasures.push_back(treasure);
        return true;
    }
    return false;
}

void Game::clearTreasures() {
    treasures.clear();
}

void Game::setRandomTreasures(uint16_t amount) {
    while(amount) {
        sf::Vector2u pos(rand() % (map.getSize().x - 2) + 1, rand() % (map.getSize().y - 2) + 1);
        sf::Sprite sprite = sf::Sprite(ResourceManager::getInstance().loadTexture("assets/my_doc.png"));
        treasures.push_back(Treasure(sprite, 1, (rand() % 8) * 100 + 100, pos));
        Tile tile(0, 0, FLOOR);
        map.setTile(pos, tile);
        amount--;
    }
}

std::vector<Treasure>& Game::getTreasures() {
    return treasures;
}

bool Game::isEntityAtPos(sf::Vector2u pos) {
    for (auto& player : players) {
        if (player.getPos() == pos)
            return true;
    }
    return false;
}

void Game::movePlayer(uint8_t player, sf::Vector2u d) {
    if(player < players.size()) {
        sf::Vector2u newPosition = players[player].getPos() + d;
        
        if(map.floorAt(newPosition) && !isEntityAtPos(newPosition)) {
            players[player].move(d);
        }
        else {
            players[player].setDirection(d);
        }
        
        for(auto i = treasures.begin(); i != treasures.end(); i++) {
            Treasure& tres = *i;
            if(tres.getPosition() == players[player].getPos()) {
                // TREASURE FOUND :)
                ResourceManager::getInstance().playKling(tres.getValue());
                players[player].incrementMoney(tres.getValue());
                players[player].incrementScore(tres.getScore());
                treasures.erase(i);
                break;
            }
        }
        
        revealMapAt(players[player].getPos());
    }
}

sf::Image& Game::getOverlayImage() {
    return overlayImage;
}

void Game::revealMapAt(sf::Vector2u pos, int radius) {
    int posX = pos.x = 16 * pos.x + 8;
    int posY = 16 * pos.y + 8;
    
    sf::Vector2u overlaySize = overlayImage.getSize();
    int overlayWidth = overlaySize.x;
    int overlayHeight = overlaySize.y;
    
    sf::Color transparent = sf::Color(0, 0, 0, 0);
    
    for(int x = fmax(0, posX - radius); x < posX + radius; x++) {
        int Dx = x - posX;
        int DxPow = Dx * Dx;
        
        for(int y = fmax(0, posY - radius); y < posY + radius; y++) {
            int Dy = y - posY;
            int distance = sqrt(DxPow + Dy * Dy);
            
            if (distance < radius && x < overlayWidth && y < overlayHeight)
                overlayImage.setPixel(x, y, transparent);
        }
    }
}

sf::Vector2u Game::getRandomEmptyPos() {
    auto element = startPositions.begin() + rand() % startPositions.size();
    
    sf::Vector2u pos = *element;
    startPositions.erase(element);
    return pos;
}

void Game::addPlayer(const std::string& name) {
    sf::Vector2u pos = sf::Vector2u(rand() % (map.getSize().x - 2) + 1, rand() % (map.getSize().y - 2) + 2);
    
    Player p("assets/playersprite.png", pos.x, pos.y, name);
    players.push_back(p);
    map.makeFloorAround(pos);
    revealMapAt(p.getPos());
}

void Game::addProjectile(Projectile projectile) {
    projectiles.push_back(projectile);
}

std::vector<Projectile>& Game::getProjectiles() {
    return projectiles;
}

void Game::addEffect(Effect effect) {
    effects.push_back(effect);
}

std::vector<Effect>& Game::getEffects() {
    return effects;
}

bool Game::toggleSound() {
    sound = !sound;
    ResourceManager::getInstance().enableMusic(sound);
    return sound;
}

bool Game::soundEnabled() {
    return sound;
}

void Game::update(sf::Time dt) {
    if (getRoundRemainingTime() <= sf::seconds(0)) {
        endRound();
    }
    
    if (roundEndClock.getElapsedTime().asSeconds() > 5 && roundEnded)
        endRound(true);
    
    for(auto &i : players) {
        i.updateSpritePosition(4);
    }

    for (auto &i : effects) {
        i.updateSpritePosition(4);
    }

    for (auto i = 0; i < projectiles.size(); i++) {
        Projectile& p = projectiles[i];
        p.updateSpritePosition(8);
        
        bool exploded = p.update(dt);
        if (exploded) {
            projectiles.erase(projectiles.begin() + i);
            i--;
        }
    }
    
    for (auto i = 0; i < effects.size(); i++) {
        Effect& e = effects[i];
        
        bool animationComplete = e.update();
        if (animationComplete && !e.isPermanent()) {
            effects.erase(effects.begin() + i);
            i--;
        }
    }

}