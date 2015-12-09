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
#include "MapGenerator.h"
#include "MapLoader.h"
#include "Player.h"
#include "TextureManager.h"
#include "GameScene.h"
#include "MenuScene.h"

#include <SFML/Graphics.hpp>

#include <iostream>
#include <cstdio>
#include <time.h>
#include <cmath>

Game::Game() {
    srand(time(NULL));
    MapGenerator gen = MapGenerator();
    MapLoader loader = MapLoader();
    
    map = loader.fromFile("maps/map.mb");
    //map = gen.generate();
    
    scenes[MENUSCENE] = new MenuScene(*this);
    scenes[GAMESCENE] = new GameScene(*this);
    
    sf::Vector2u windowSize = map.getSize();
    overlayImage.create(windowSize.x * 16, windowSize.y * 16, sf::Color(0, 0, 0, 255));
}

Game::~Game() {
}

std::vector<Player>& Game::getPlayers() {
    return players;
}

Scene* Game::getScene() {
    return currentScene;
}

void Game::setScene(SceneType scene) {
    currentScene = scenes.at(scene);
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
            sf::Sprite sprite = sf::Sprite(TextureManager::getInstance().load("assets/my_doc.png"));
            treasures.push_back(Treasure(sprite, 300, pos));
            
            amount--;
        }
    }
}

std::vector<Treasure>& Game::getTreasures() {
    return treasures;
}

bool Game::isEntityAtPos(sf::Vector2u pos) {
    for (auto player : players) {
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
            map.setTileAsVisible(newPosition);
        }
        
        for(auto i = treasures.begin(); i != treasures.end(); i++) {
            Treasure& asd = *i;
            if(asd.getPosition() == players[player].getPos()) {
                players[player].incrementMoney(asd.getValue());
                treasures.erase(i);
                break;
            }
        }
        //this->revealMapAt(players[player].getPos());
    }
}

/*sf::Image& Game::getOverlayImage() {
    return overlayImage;
}

/*void Game::revealMapAt(sf::Vector2u pos, int radius) {
    pos.x = 16 * pos.x + 8;
    pos.y = 16 * pos.y + 8;
    for(int x = pos.x - radius; x < pos.x + radius; x++) {
        for(int y = pos.y - radius; y < pos.y + radius; y++) {
            int Dx = x - (int) pos.x;
            int Dy = y - (int) pos.y;
            if (sqrt(Dx * Dx + Dy * Dy) < radius && x >= 0 && y >= 0 && x < overlayImage.getSize().x && y < overlayImage.getSize().y)
                overlayImage.setPixel(x, y, sf::Color(0, 0, 0, 0));
        }
    }
}
*/

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
    this->map.setTileAsVisible(pos);
    //this->revealMapAt(p.getPos());
}

void Game::addProjectile(Projectile projectile) {
    projectiles.push_back(projectile);
}

std::vector<Projectile>& Game::getProjectiles() {
    return this->projectiles;
}