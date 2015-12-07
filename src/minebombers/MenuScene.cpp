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
#include "GameScene.h"
#include "TextureManager.h"

MenuScene::MenuScene(Game& game) : game(game) {
    font.loadFromFile("assets/BebasNeue.otf");
}

MenuScene::~MenuScene() {
}

void MenuScene::onEvent(sf::Event& event) {
    if(event.type == sf::Event::KeyPressed) {
        switch (event.key.code) {
            case sf::Keyboard::Down: selected++; break;
            case sf::Keyboard::Up: selected--; break;
            case sf::Keyboard::Return: {
                if (selected == 0) {
                    GameScene gameScene = GameScene(game);
                    game.setScene("game");
                }
            }
            default:
                break;
        }
        selected = fmin(1, fmax(0, selected));
    }
}

void MenuScene::update() {
    logoPhase++;
    
    if (selected == 0) {
        if (twoPlayerScale < 1)
            twoPlayerScale += 0.05;
        if (campaignScale > 0.9)
            campaignScale -= 0.05;
    } else if (selected == 1) {
        if (twoPlayerScale > 0.9)
            twoPlayerScale -= 0.05;
        if (campaignScale < 1)
            campaignScale += 0.05;
    }
}

void MenuScene::draw(sf::RenderWindow& window) {
    int width = 800;
    int height = 800;
    
    sf::Sprite background;
    background.setTexture(TextureManager::getInstance().load("assets/background.jpg"));
    background.setScale(width / background.getLocalBounds().width, height / background.getLocalBounds().height);
    
    sf::Text minebombers = sf::Text("minebombers", font, 110);
    sf::Text twoPlayer = sf::Text("2 players", font, 85);
    sf::Text campaign = sf::Text("campaign", font, 85);
       
    float logoScale = (sin(logoPhase / 20.0) + 20) * 0.05;
    minebombers.setScale(logoScale, logoScale);
    minebombers.setOrigin(minebombers.getLocalBounds().width / 2, minebombers.getLocalBounds().height / 2);
    
    twoPlayer.setOrigin(twoPlayer.getLocalBounds().width / 2, twoPlayer.getLocalBounds().height / 2);
    campaign.setOrigin(campaign.getLocalBounds().width / 2, campaign.getLocalBounds().height / 2);
    
    sf::Color dimmed = sf::Color(255, 255, 255, 150);
    if (selected == 1)
        twoPlayer.setColor(dimmed);
    else if (selected == 0)
        campaign.setColor(dimmed);
    
    twoPlayer.setScale(twoPlayerScale, twoPlayerScale);
    campaign.setScale(campaignScale, campaignScale);
    
    minebombers.setPosition(width / 2, 100);    
    twoPlayer.setPosition(width / 2, minebombers.getPosition().y + 210);
    campaign.setPosition(width / 2, twoPlayer.getPosition().y + 120);
    
    window.draw(background);
    window.draw(minebombers);
    window.draw(twoPlayer);
    window.draw(campaign);
}


