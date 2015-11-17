/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MenuScene.cpp
 * Author: Max
 * 
 * Created on November 17, 2015, 2:23 PM
 */

#include "MenuScene.h"

MenuScene::~MenuScene() {
}

void MenuScene::onEvent(sf::Event& event) {
    
}

void MenuScene::update(sf::RenderWindow& window) {
    sf::CircleShape shape(50);
    shape.setFillColor(sf::Color(asd++, 250, 50));
    window.draw(shape);
}

