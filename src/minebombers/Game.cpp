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

Game::Game() {
    MapGenerator gen = MapGenerator();
    MapLoader loader = MapLoader();
    
    map = loader.fromFile("maps/map.mb");
    //map = gen.generate();
    
    scenes["menu"] = new MenuScene(*this);
    scenes["game"] = new GameScene(*this);
}

Game::~Game() {
}

std::vector<Player>& Game::getPlayers() {
    return players;
}

Scene* Game::getScene() {
    return currentScene;
}

void Game::setScene(std::string sceneName) {
    currentScene = scenes.at(sceneName);
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
        
        if(map.canMoveTo(newPosition) && !this->isEntityAtPos(newPosition))
            players[player].move(d);
    }
}

void Game::addPlayer(const std::string& name) {
    sf::Vector2u pos(rand() % 20, rand() % 20);
    
    Player p("assets/playersprite.png", pos.x, pos.y, name);
    players.push_back(p);
}

void Game::addProjectile(Projectile& projectile) {
    projectiles.push_back(projectile);
}

std::vector<Projectile>& Game::getProjectiles() {
    return this->projectiles;
}
    
    
