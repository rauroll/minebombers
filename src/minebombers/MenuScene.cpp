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
    
}

void MenuScene::draw(sf::RenderWindow& window) {
    int width = 800;
    int height = 800;
    
    sf::Font font;
    font.loadFromFile("assets/BebasNeue.otf");
    
    sf::Text minebombers = sf::Text("minebombers", font, 100);
    minebombers.setPosition(width / 2 - minebombers.getLocalBounds().width / 2, 100);
    
    sf::Text twoPlayer = sf::Text("2 players", font, 70);
    twoPlayer.setPosition(width / 2 - twoPlayer.getLocalBounds().width / 2, minebombers.getPosition().y + 200);
    
    sf::Text campaign = sf::Text("Campaign", font, 70);
    campaign.setPosition(width / 2 - campaign.getLocalBounds().width / 2, twoPlayer.getPosition().y + 90);
       
    window.draw(minebombers);
    window.draw(twoPlayer);
    window.draw(campaign);
}


