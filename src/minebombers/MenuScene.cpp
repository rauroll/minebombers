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

#include <cmath>
#include <cstdlib>
#include <iostream>
#include <string>

#include "MenuScene.h"
#include "Game.h"
#include "GameScene.h"
#include "ResourceManager.h"
#include "ConfigManager.h"

MenuScene::MenuScene() {
}

MenuScene::~MenuScene() {
}

void MenuScene::onChangedTo() {

}

void MenuScene::onEvent(sf::Event& event) {
    Game& game = Game::getInstance();
    ConfigManager& config = ConfigManager::getInstance();
    
    if(event.type == sf::Event::KeyPressed) {
        switch (event.key.code) {
            case sf::Keyboard::Left: selectedMap--; break;
            case sf::Keyboard::Right: selectedMap++; break;
            case sf::Keyboard::Down: selected++; break;
            case sf::Keyboard::Up: selected--; break;
            case sf::Keyboard::Return: {
                game.initGame();
                for (int i = 0; i < selected + 2; i++) {
                    std::string key = "player" + std::to_string(i + 1) + "_name";
                    std::string defaultName = "Player " + std::to_string(i + 1);
                    std::string playerName = config.getString(key, defaultName);
                    
                    std::string spritePath = "assets/playersprite" + std::to_string(i + 1) + ".png";
                    
                    game.addPlayer(playerName, spritePath);
                }
                game.setScene(GAMESCENE);
            }
            default:
                break;
        }
        selected = fmin(options.size() - 1, fmax(0, selected));
        selectedMap = fmin(maps.size() - 1, fmax(0, selectedMap));
    }
}

void MenuScene::update(sf::Time dt) {
    logoPhase++;
}

void MenuScene::draw(sf::RenderWindow& window) {
    sf::Font font = ResourceManager::getInstance().getFont();
    sf::Vector2u size = Game::getInstance().getCanvasSize();
    int width = size.x;
    int height = size.y;
    
    sf::Sprite background;
    background.setTexture(ResourceManager::getInstance().loadTexture("assets/background.jpg"));
    background.setScale(width / background.getLocalBounds().width, height / background.getLocalBounds().height);
    window.draw(background);
    
    sf::Text minebombers = sf::Text("minebombers", font, 175);
    float logoScale = (sin(logoPhase / 20.0) + 20) * 0.05;
    minebombers.setScale(logoScale, logoScale);
    minebombers.setOrigin(minebombers.getLocalBounds().width / 2, minebombers.getLocalBounds().height / 2);
    minebombers.setPosition(width / 2, 100);    
    window.draw(minebombers);
    
    int positionY = 300;
    for (int i = 0; i < options.size(); i++) {
        auto option = options[i];
        sf::Text optionText(option, font, 90);
        optionText.setPosition(size.x / 2, positionY);
        optionText.setOrigin(optionText.getLocalBounds().width / 2, optionText.getLocalBounds().height / 2);
        optionText.setColor(sf::Color(255, 255, 255, selected == i ? 255 : 175));
        window.draw(optionText);
        positionY += 100;
    }
    
    sf::Text mt(maps[selectedMap], font, 70);
    mt.setPosition(size.x / 2 - mt.getLocalBounds().width / 2, size.y - 100);
    mt.setColor(sf::Color(255, 255, 255));
    window.draw(mt);
    
    if (selectedMap > 0) {
        sf::CircleShape leftArrow(16, 3);
        leftArrow.setFillColor(sf::Color(255, 255, 255));
        leftArrow.setPosition(mt.getPosition().x - 50, mt.getPosition().y + 60);
        leftArrow.setRotation(-90);
        window.draw(leftArrow);
    }
    
    if (selectedMap < maps.size() - 1) {
        sf::CircleShape rightArrow(16, 3);
        rightArrow.setFillColor(sf::Color(255, 255, 255));
        rightArrow.setPosition(mt.getPosition().x + mt.getLocalBounds().width + 50, mt.getPosition().y + 30);
        rightArrow.setRotation(90);
        window.draw(rightArrow);
    }
}
