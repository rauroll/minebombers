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
#include <iostream>

#include "ShopScene.h"
#include "Game.h"
#include "ResourceManager.h"

ShopScene::ShopScene() {
}

ShopScene::ShopScene(const ShopScene& orig) {
}

ShopScene::~ShopScene() {
}

void ShopScene::onChangedTo() {
    clock.restart();
}


void ShopScene::onEvent(sf::Event& event) {
    if (event.type == sf::Event::KeyPressed) {
        switch (event.key.code) {
            case sf::Keyboard::W: {
                ResourceManager::getInstance().playSound("plip");
                playerSelections[1]--;
                break;
            }
            case sf::Keyboard::S: {
                ResourceManager::getInstance().playSound("plip");
                playerSelections[1]++;
                break;
            }
            case sf::Keyboard::Up: {
                ResourceManager::getInstance().playSound("plop");
                playerSelections[0]--;
                break;
            }
            case sf::Keyboard::Down: {
                ResourceManager::getInstance().playSound("plop");
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

void ShopScene::update(sf::Time dt) {
    if (clock.getElapsedTime().asSeconds() > 15) {
        Game::getInstance().setScene(GAMESCENE);
    }
}

void ShopScene::draw(sf::RenderWindow& window) {
    sf::Font font = ResourceManager::getInstance().getFont();
    
    Game& game = Game::getInstance();
    sf::Vector2u size = game.getCanvasSize();
    
    sf::Text text("Shop", font, 100);
    text.setPosition(50, 50);
    window.draw(text);
    
    int i = 0;
    for(auto w : weapons) {
        sf::Text text(w, font, 72);
        text.setPosition(200, 200 + i++ * 80);
        window.draw(text);
        // draw players ammo for each weapon if the player has it
        // HAUENLEUKAPIHDEILLÄ WEAPON MANAGER TÄHÄ!
        sf::Text player1Ammo("23", font, 28);
        player1Ammo.setColor(sf::Color(255, 0, 0));
        player1Ammo.setPosition(text.getPosition().x + text.getGlobalBounds().width + 20, text.getPosition().y + 12);
        window.draw(player1Ammo);
        sf::Text player2Ammo("15", font, 28);
        player2Ammo.setColor(sf::Color(0, 255, 0));
        player2Ammo.setPosition(text.getPosition().x + text.getGlobalBounds().width + 20, text.getPosition().y + 48);
        window.draw(player2Ammo);
        
    }
    
    for(int i = 0; i < playerSelections.size(); i++) {
        int s = playerSelections[i];
        sf::CircleShape circle(25);
        circle.setPosition(50 + i * 25 * 3, 220 + s * 80);
        circle.setFillColor(i ? sf::Color(0, 255, 0) : sf::Color(255, 0, 0));
        window.draw(circle);
    }
    
    sf::Text nextRound("Next round starts in " + std::to_string((int) ceil(15 - clock.getElapsedTime().asSeconds())) + "...", font, 60);
    sf::FloatRect bounds = nextRound.getLocalBounds();
    nextRound.setPosition(size.x / 2 - bounds.width / 2, size.y - bounds.height - 50);
    window.draw(nextRound);
}


