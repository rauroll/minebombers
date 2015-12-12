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

GameScene::GameScene() {
    
}

GameScene::GameScene(const GameScene& orig) {
    
}

GameScene::~GameScene() {
    
}

void GameScene::onChangedTo() {
    Game& game = Game::game();
    game.startRound();
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
        //i.updateSpritePosition();
    }
    
    
    std::vector<Projectile>& projectiles = game.getProjectiles();
    for (auto &i : projectiles) {
        window.draw(i.getSprite());
        //i.updateSpritePosition();
    }
    
    std::vector<Effect>& effects = game.getEffects();
    for (auto &i : effects) {
        window.draw(i.getSprite());
        //i.updateSpritePosition();
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
        hp.setColor(sf::Color(100, 100, 100));
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
            //std::cout << "painettiin:" << event.key.code << ", " << v.x << ", " << v.y << std::endl;
            if(!v.x) {
                v.x = 1; //on/off
                v.y = 0; //time
            }
            
            switch (event.key.code) {
                case sf::Keyboard::LControl: {
                    Player& player = game.getPlayers()[0];
                    Projectile p = player.useWeapon();
                    game.addProjectile(p);
                    break;
                }
                case sf::Keyboard::LShift: {
                    Player& player = game.getPlayers()[0];
                    player.nextWeapon();
                    break;
                }
                default:
                    break;
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
        for(auto& i : keyboard) {
            if(i.second.x) {
                i.second.y ++;

                if(i.second.y % 5 == 1) {

                    //Player 1
                    if(i.first == sf::Keyboard::Up)
                        game.movePlayer(0, sf::Vector2u(0, -1));
                    if(i.first == sf::Keyboard::Down)
                        game.movePlayer(0, sf::Vector2u(0, 1));
                    if(i.first == sf::Keyboard::Right)
                        game.movePlayer(0, sf::Vector2u(1, 0));
                    if(i.first == sf::Keyboard::Left)
                        game.movePlayer(0, sf::Vector2u(-1, 0));

                    //Player 2
                    if(i.first == sf::Keyboard::W)
                        game.movePlayer(1, sf::Vector2u(0, -1));
                    if(i.first == sf::Keyboard::S)
                        game.movePlayer(1, sf::Vector2u(0, 1));
                    if(i.first == sf::Keyboard::D)
                        game.movePlayer(1, sf::Vector2u(1, 0));
                    if(i.first == sf::Keyboard::A)
                        game.movePlayer(1, sf::Vector2u(-1, 0));
                }
            }
        }
    }
    
    game.update();
    
}



