/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GameScene.cpp
 * Author: henrinurmi
 * 
 * Created on November 18, 2015, 4:49 PM
 */

#include <iostream>
#include <math.h>

#include "GameScene.h"
#include "ResourceManager.h"
#include "Player.h"
#include "ButtonReactionFactory.h"

GameScene::GameScene() {
    
}

GameScene::GameScene(const GameScene& orig) {
    
}

GameScene::~GameScene() {
    
}

void GameScene::onChangedTo() {
    Game& game = Game::game();
    game.startRound();
    
    reloadButtons();
}


void GameScene::draw(sf::RenderWindow& window) {
    Game& game = Game::game();
    window.draw(game.getMap());
    
    std::vector<Treasure>& treasures = game.getTreasures();
    for(auto &i : treasures) {
        window.draw(i.getSprite());
    }
    
    std::vector<Player>& players = game.getPlayers();
    for(auto &i : players) {
        window.draw(i.getSprite());
    }
    
    std::vector<Projectile>& projectiles = game.getProjectiles();
    for (auto &i : projectiles) {
        window.draw(i.getSprite());
    }
    
    std::vector<Effect>& effects = game.getEffects();
    for (auto &i : effects) {
        window.draw(i.getSprite());
    }
    
    // statusbar
    sf::Vector2u windowSize = game.getCanvasSize();
    int statusBarHeight = 100;
    sf::RectangleShape background(sf::Vector2f(windowSize.x, statusBarHeight));
    background.setPosition(0, windowSize.y - statusBarHeight);
    background.setFillColor(sf::Color(230, 230, 230));
    window.draw(background);
    
    sf::Font font = ResourceManager::getInstance().getFont();

    // Draw player data for each player
    int playerFontSize = 20;
    int playerX = 20;
    int playerY = windowSize.y - statusBarHeight / 2 + playerFontSize / 2;
    sf::Color statusBarColor = sf::Color(0, 0, 0);
    
    for(auto &p : players) {
        sf::Text name = sf::Text(p.getName(), font, playerFontSize * 1.2);
        name.setPosition(playerX, playerY - playerFontSize * 1.2 * 2);
        name.setColor(statusBarColor);
        window.draw(name);
        
        sf::Text hp = sf::Text("HP" + std::to_string(p.getHealth()) + "/100", font, playerFontSize);
        hp.setPosition(playerX, playerY - playerFontSize);
        hp.setColor(sf::Color(200 - p.getHealth() * 200 / 100, p.getHealth() * 200 / 100, 50));
        window.draw(hp);
        
        sf::Text mohlay = sf::Text("Money: " + std::to_string(p.getMoney()), font, playerFontSize);
        mohlay.setPosition(playerX, playerY);
        mohlay.setColor(sf::Color(100, 100, 100));
        window.draw(mohlay);
        
        playerX += name.getLocalBounds().width + 75;
    }
    
    sf::Text roundStatus("Round " + std::to_string(game.getRound()) + " / " + std::to_string(game.getTotalRounds()), font, 60);
    roundStatus.setColor(statusBarColor);
    roundStatus.setPosition(windowSize.x / 2 - roundStatus.getLocalBounds().width / 2, windowSize.y - statusBarHeight / 2 - 38);
    window.draw(roundStatus);
    
    // draw map overlay
    sf::Texture overlayTexture;
    overlayTexture.loadFromImage(game.getOverlayImage());
    sf::Sprite overlay;
    overlay.setTexture(overlayTexture);
    window.draw(overlay);
    
    // draw round end overlay
    if (game.roundHasEnded()) {
        sf::RectangleShape rect(sf::Vector2f(windowSize.x, windowSize.y));
        rect.setFillColor(sf::Color(0, 0, 0, 150));
        window.draw(rect);
        
        sf::Text roundEnded("The round has ended!", font, 100);
        roundEnded.setPosition(windowSize.x / 2 - roundEnded.getLocalBounds().width / 2, 200);
        window.draw(roundEnded);
    } else {
        sf::Text roundClock = sf::Text("Time left: " + std::to_string((int) ceil(game.getRoundRemainingTime().asSeconds())), font, 40);
        roundClock.setPosition(windowSize.x - roundClock.getLocalBounds().width - 40, windowSize.y - statusBarHeight / 2 - 23);
        roundClock.setColor(statusBarColor);
        window.draw(roundClock);
    }
}

void GameScene::onEvent(sf::Event& event) {
    Game& game = Game::game();
    switch (event.type)
    {
        case sf::Event::KeyPressed: {
            sf::Vector2u& v = keyboard[event.key.code];
            if(!v.x) {
                v.x = 1; //on/off
                v.y = 0; //time
            }
            break;
        }
        case sf::Event::KeyReleased:
            //std::cout << "release" << std::endl;
            keyboard[event.key.code] = sf::Vector2u(0, 0);
            break;
        default:
            break;
    }
}

void GameScene::update(sf::Time dt) {
    Game& game = Game::game();
    
    if (!game.roundHasEnded()) {    
        //Update button presstime
        for(auto& i : keyboard) {
            if(i.second.x) {
                i.second.y++;
            }
        }
        
        checkKeys();
    }
    
    game.update();
}

void GameScene::reloadButtons() {
    Game& game = Game::game();
    ButtonReactionFactory factory;
    
    playerButtons.clear();
    for(size_t i = 0; i < game.getPlayers().size(); i++) {
        playerButtons.push_back(factory.getPlayerButtons(i));
    }
}

void GameScene::checkKeys() {
    Game& game = Game::game();
    
    for(size_t i = 0; i < playerButtons.size(); i++) {
        auto buttons = playerButtons[i];
        
        for(auto button = buttons.begin(); button != buttons.end(); button++) {
            sf::Keyboard::Key key = button->first;
            ButtonReaction reaction = button->second;
            
            if (keyboard.find(key) != keyboard.end()) {
                sf::Vector2u b = keyboard[key]; // x = state, y = time;
                
                if (b.x) {
                    switch(reaction) {
                        case MOVE_UP:
                            if(b.y % 5 == 1)
                                game.movePlayer(i, sf::Vector2u(0, -1));
                            break;
                        case MOVE_DOWN:
                            if(b.y % 5 == 1)
                                game.movePlayer(i, sf::Vector2u(0, 1));
                            break;
                        case MOVE_LEFT:
                            if(b.y % 5 == 1)
                                game.movePlayer(i, sf::Vector2u(-1, 0));
                            break;
                        case MOVE_RIGHT:
                            if(b.y % 5 == 1)
                                game.movePlayer(i, sf::Vector2u(1, 0));
                            break;
                        case SHOOT: {
                            Player& player = game.getPlayers()[i];
                            Projectile p = player.useWeapon();
                            game.addProjectile(p);
                            
                            keyboard[key] = sf::Vector2u(0, 0);
                            break;
                        }
                        case CHANGE_WEAPON: {
                            Player& player = game.getPlayers()[i];
                            player.nextWeapon();
                            
                            keyboard[key] = sf::Vector2u(0, 0);
                            break;                            
                        }
                        default:
                            break;
                    }
                }
            }
        }
    }
}

