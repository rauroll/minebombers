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

#include "Game.h"
#include "Player.h"
#include "ResourceManager.h"
#include "GameScene.h"
#include "MenuScene.h"
#include "ShopScene.h"

#include <SFML/Graphics.hpp>

#include <iostream>
#include <cstdio>
#include <time.h>
#include <cmath>

Game::Game() {
    srand(time(NULL));
    this->gen = MapGenerator();
    this->loader = MapLoader();
     
    scenes[MENUSCENE] = new MenuScene();
    scenes[GAMESCENE] = new GameScene();
    scenes[SHOPSCENE] = new ShopScene();
    
    map = loader.fromFile("maps/map.mb");
    
    //this->startRound();
}

void Game::startRound() {    
    this->roundClock.restart();
    this->roundTime = sf::seconds(10);
    map = loader.fromFile("maps/map.mb");
    //map = gen.generate();
     
    sf::Vector2u windowSize = map.getSize();
    overlayImage.create(windowSize.x * 16, windowSize.y * 16, sf::Color(0, 0, 0, 255));
    
    this->setRandomTreasures(50);
    this->addPlayer("JERE");
    this->addPlayer("JERE2");
    
    Effect explosion = Effect("Explosion", "assets/explosion.png", sf::Vector2u(0, 0), true);
    Projectile proj = Projectile("jonnemissile", "assets/projectile.png", 10, explosion);
    Weapon onlyWeapon = Weapon("jonnegun", 99, proj);
        
    this->getPlayers()[0].addWeapon(onlyWeapon);
    
}

void Game::endRound() {
    this->setScene(SHOPSCENE);
    this->players.clear();
    this->treasures.clear();
    this->effects.clear();
    this->projectiles.clear();

}

Game::~Game() {
}

sf::Vector2u Game::getCanvasSize() {
    sf::Vector2u s = map.getSize();
    return sf::Vector2u(s.x * 16, s.y * 16 + 100);
}


std::vector<Player>& Game::getPlayers() {
    return players;
}

Scene* Game::getScene() {
    return currentScene;
}

sf::Time Game::getRoundRemainingTime() const {
    return (this->roundTime - this->roundClock.getElapsedTime());
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
        sf::Vector2u pos(rand() % map.getSize().x, rand() % map.getSize().y);
        
        if(isEmpty(pos)) {
            sf::Sprite sprite = sf::Sprite(ResourceManager::getInstance().loadTexture("assets/my_doc.png"));
            treasures.push_back(Treasure(sprite, 300, pos));
            
            amount--;
        }
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
        
        if(map.floorAt(newPosition) && !this->isEntityAtPos(newPosition)) {
            players[player].move(d);
        }
        
        for(auto i = treasures.begin(); i != treasures.end(); i++) {
            Treasure& tres = *i;
            if(tres.getPosition() == players[player].getPos()) {
                players[player].incrementMoney(tres.getValue());
                treasures.erase(i);
                break;
            }
        }
        this->revealMapAt(players[player].getPos());
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
    sf::Vector2u pos;
    sf::Vector2u mapSize = map.getSize();
    while (true) {
        pos = sf::Vector2u(rand() % mapSize.x, rand() % mapSize.y);
        if (map.floorAt(pos) && !this->isEntityAtPos(pos))
            break;
    }
    return pos;
}

void Game::addPlayer(const std::string& name) {
    sf::Vector2u pos = this->getRandomEmptyPos();
    
    Player p("assets/playersprite.png", pos.x, pos.y, name);
    players.push_back(p);
    this->revealMapAt(p.getPos());
}

void Game::addProjectile(Projectile projectile) {
    projectiles.push_back(projectile);
}

std::vector<Projectile>& Game::getProjectiles() {
    return this->projectiles;
}

void Game::addEffect(Effect effect) {
    this->effects.push_back(effect);
}

std::vector<Effect>& Game::getEffects() {
    return this->effects;
}

void Game::update() {
    if (this->getRoundRemainingTime() <= sf::seconds(0)) {
        this->endRound();
    }
    
    std::vector<Projectile>& projectiles = this->getProjectiles();
    for (auto i = 0; i < projectiles.size(); i++) {
        Projectile& p = projectiles[i];
        bool exploded = p.update();
        ///if (exploded) {
            // erase here
            //projectiles.erase(projectiles.at(i));
        //}
    }
    
    /*
    std::vector<Effect>& effects = this->getEffects();
    
    for (auto i = 0; i < effects.size(); i++) {
        Effect& e = effects[i];
        bool animationComplete = e.update();
        if (animationComplete && !e.isPermanent()) {
            //should be removed here
        }
    }*/

}