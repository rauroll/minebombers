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

#include <cmath>
#include <iostream>
#include <map>

#include "ShopScene.h"
#include "Game.h"
#include "ResourceManager.h"
#include "ConfigManager.h"
#include "ButtonReaction.h"
#include "ButtonReactionFactory.h"

ShopScene::ShopScene() {
    ConfigManager& config = ConfigManager::getInstance();
    shopTime = config.getInt("shopTime", 25);
}

ShopScene::ShopScene(const ShopScene& orig) {
}

ShopScene::~ShopScene() {
}

void ShopScene::onChangedTo() {
    weapons = WeaponManager::getInstance().getWeapons();
    playerSelections.clear();
    for (auto p : Game::getInstance().getPlayers())
        playerSelections.push_back(0);
    clock.restart();
}


void ShopScene::onEvent(sf::Event& event) {
    Game& game = Game::getInstance();
    
    if (event.type == sf::Event::KeyPressed) {
        if(event.type == sf::Event::KeyPressed) {
            for(size_t i = 0; i < game.getPlayers().size(); i++) {
                ButtonReactionFactory buttonFactory;
                std::map<sf::Keyboard::Key, ButtonReaction> buttons = buttonFactory.getPlayerButtons(i);
 
                if(buttons.find(event.key.code) != buttons.end()) {
                    ButtonReaction button = buttons[event.key.code];
                    
                    switch(button) {
                        case MOVE_UP:
                            if(i % 2)
                                ResourceManager::getInstance().playSound("plip");
                            else
                                ResourceManager::getInstance().playSound("plop");
                            playerSelections[i]--;
                            break;
                        case MOVE_DOWN:
                            if(i % 2)
                                ResourceManager::getInstance().playSound("plip");
                            else
                                ResourceManager::getInstance().playSound("plop");
                            playerSelections[i]++;
                            break;
                        case SHOOT:
                            this->buyAmmo(i, this->weapons[playerSelections[i]]);
                        default:
                            break;
                    }
                }
            }
        }
        
        for (int i = 0; i < playerSelections.size(); i++)
            playerSelections[i] = fmin(weapons.size() - 1, fmax(0, playerSelections[i]));
    }
}

void ShopScene::update(sf::Time dt) {
    if (clock.getElapsedTime().asSeconds() > this->shopTime) {
        Game::getInstance().setScene(GAMESCENE);
    }
}

void ShopScene::buyAmmo(int playerId, Weapon weapon) {
    auto& p = Game::getInstance().getPlayers()[playerId];
    if (p.getMoney() >= weapon.getPrice()) {
        p.buyAmmo(weapon.getName(), 1, weapon.getPrice());
    }
}

void ShopScene::draw(sf::RenderWindow& window) {
    sf::Font font = ResourceManager::getInstance().getFont();
    
    Game& game = Game::getInstance();
    sf::Vector2u size = game.getCanvasSize();
    
    sf::Text text("Shop", font, 100);
    text.setPosition(50, 50);
    window.draw(text);
    
    std::vector<Player>& players = game.getPlayers();
    
    int xPosition = 24;
    for(int i = 0; i < playerSelections.size(); i++) {
        int s = playerSelections[i];
        sf::CircleShape circle(16);
        circle.setPosition(50 + xPosition, 220 + s * 54);
        circle.setFillColor(players[i].getColor());
        window.draw(circle);
        xPosition += 16 * 3;
    }
    
    int i = 0;
    for(auto& w : weapons) {
        sf::Text text(w.getName() + ", $" + std::to_string(w.getPrice()), font, 50);
        text.setPosition(xPosition + 50, 200 + i++ * 55);
        window.draw(text);
    }

    int moneyY = 12;
    for(auto& p : players) {
        sf::Text playerMoney(p.getName() + " money $" + std::to_string(p.getMoney()), font, 36);
        playerMoney.setPosition(800, moneyY);
        playerMoney.setColor(p.getColor());
        window.draw(playerMoney);
        moneyY += 42;
    }

    
    sf::Text nextRound("Next round starts in " + std::to_string((int) ceil(this->shopTime - clock.getElapsedTime().asSeconds())) + "...", font, 60);
    sf::FloatRect bounds = nextRound.getLocalBounds();
    nextRound.setPosition(size.x / 2 - bounds.width / 2, size.y - bounds.height - 50);
    window.draw(nextRound);
}