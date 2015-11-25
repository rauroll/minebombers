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
#include <iostream>

Game::Game() {
    MapGenerator gen = MapGenerator();
    MapLoader loader = MapLoader();
    
    player = Player("assets/mq1.jpg", 25, 25, "JORMA");
    //map = loader.fromFile("maps/map.mb");
    map = gen.generate();
}

Game::~Game() {
}

const Player& Game::getPlayer() const {
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

