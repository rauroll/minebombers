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
#include <iostream>
#include "Game.h"

MenuScene::MenuScene(Game& game) : game(game) {
    sf::Font font;
    font.loadFromFile("assets/BebasNeue.otf");
    
    minebombers = sf::Text("minebombers", font, 100);
    twoPlayer = sf::Text("2 players", font, 70);
    campaign = sf::Text("campaign", font, 70);
}

MenuScene::MenuScene(const MenuScene& scene) : game(scene.game) {
    
}

MenuScene::~MenuScene() {
}

void MenuScene::onEvent(sf::Event& event) {
    if (event.type == sf::Event::MouseMoved) {
    }
    else if(event.type == sf::Event::MouseButtonPressed) {
        std::cout << "asd" << std::endl;
    }
}

void MenuScene::update() {
    
}

void MenuScene::draw(sf::RenderWindow& window) {
    int width = 800;
    int height = 800;
    
    minebombers.setPosition(width / 2 - minebombers.getLocalBounds().width / 2, 100);    
    twoPlayer.setPosition(width / 2 - twoPlayer.getLocalBounds().width / 2, minebombers.getPosition().y + 200);
    campaign.setPosition(width / 2 - campaign.getLocalBounds().width / 2, twoPlayer.getPosition().y + 90);
    
    window.draw(minebombers);
    window.draw(twoPlayer);
    window.draw(campaign);
}


