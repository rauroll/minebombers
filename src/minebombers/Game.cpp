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

Game::Game() {
}

Game::Game(const Game& orig) {
}

Game::~Game() {
}

Scene* Game::getScene() {
    return currentScene;
}

void Game::setScene(Scene* scene) {
    currentScene = scene;
}
