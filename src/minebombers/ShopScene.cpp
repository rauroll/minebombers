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
    }
}

void ShopScene::update() {

}

void ShopScene::draw(sf::RenderWindow& window) {
    sf::Font font;
    font.loadFromFile("assets/BebasNeue.otf");
    sf::Text text(std::to_string(playerSelections[0]), font, 20);
    window.draw(text);
}


