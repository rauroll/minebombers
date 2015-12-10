/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ShopScene.cpp
 * Author: Max
 * 
 * Created on December 10, 2015, 6:23 PM
 */

#include <math.h>

#include "ShopScene.h"

ShopScene::ShopScene() {

}

ShopScene::ShopScene(const ShopScene& orig) {
}

ShopScene::~ShopScene() {
}

void ShopScene::onEvent(sf::Event& event) {
    if (event.type == sf::Event::KeyPressed) {
        switch (event.key.code) {
            case sf::Keyboard::W: {
                playerSelections[1]--;
                break;
            }
            case sf::Keyboard::S: {
                playerSelections[1]++;
                break;
            }
            case sf::Keyboard::Up: {
                playerSelections[0]--;
                break;
            }
            case sf::Keyboard::Down: {
                playerSelections[0]++;
                break;
            }
            default:
                break;
        }
        playerSelections[0] = fmin(weapons.size() - 1, fmax(0, playerSelections[0]));
        playerSelections[1] = fmin(weapons.size() - 1, fmax(0, playerSelections[1]));
    }
}

void ShopScene::update() {

}

void ShopScene::draw(sf::RenderWindow& window) {
    sf::Font font;
    font.loadFromFile("assets/BebasNeue.otf");
    
    sf::Text text("Shop", font, 100);
    text.setPosition(50, 50);
    window.draw(text);
    
    int i = 0;
    for(auto w : weapons) {
        sf::Text text(w, font, 72);
        text.setPosition(200, 200 + i++ * 80);
        window.draw(text);
        
        
    }
    
    for(int i = 0; i < playerSelections.size(); i++) {
        int s = playerSelections[i];
        sf::CircleShape circle(25);
        circle.setPosition(50 + i * 25 * 3, 220 + s * 80);
        circle.setFillColor(i ? sf::Color(0, 255, 0) : sf::Color(255, 0, 0));
        window.draw(circle);
    }
}


