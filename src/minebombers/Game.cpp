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

#include <SFML/Graphics.hpp>

#include <iostream>
#include <cstdio>

Game::Game() {
    MapGenerator gen = MapGenerator();
    MapLoader loader = MapLoader();
    
    player = Player("assets/mq1.jpg", 0, 0, "JORMA");
    //map = loader.fromFile("maps/map.mb");
    map = gen.generate();
}

Game::~Game() {
}

Player& Game::getPlayer() {
    return player;
}

Scene* Game::getScene() {
    return currentScene;
}

void Game::setScene(Scene* scene) {
    currentScene = scene;
}

Map& Game::getMap() {
    return map;
}

bool Game::isEmpty(sf::Vector2u pos) {
    if(map.getTile(pos).getType() != FLOOR) {
        return false;
    }
    
    return player.getPos() != pos;
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

void Game::movePlayer(uint8_t player, sf::Vector2u d) {
    Player& p = this->player;
    
    p.move(d);
}

