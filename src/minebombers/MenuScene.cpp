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
#include <cmath>
#include <cstdlib>

MenuScene::~MenuScene() {
}

void MenuScene::onEvent(sf::Event& event) {
    
}

void MenuScene::update() {
    asd++;
}

void MenuScene::draw(sf::RenderWindow& window) {
    sf::CircleShape shape(50);
    shape.setPosition(400 + 200*sin(asd*2*3.1415/360), 200 + 200*cos(asd*2*3.1415/360));
    shape.setFillColor(sf::Color(asd, 250, 50));
    window.draw(shape);    
}


