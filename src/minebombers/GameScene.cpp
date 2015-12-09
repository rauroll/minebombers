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

#include "GameScene.h"
#include "TextureManager.h"
#include "Player.h"
#include "AudioManager.h"

#include <iostream>
#include <math.h>

GameScene::GameScene(Game& game) : game(game) {
    
}

GameScene::GameScene(const GameScene& orig) : game(orig.game) {
    
}

GameScene::~GameScene() {
    
}

void GameScene::draw(sf::RenderWindow& window) {
    window.draw(game.getMap());
    
    std::vector<Treasure>& treasures = game.getTreasures();
    for(auto &i : treasures) {
        if (game.getMap().getTile(i.getPosition()).isVisible())
            window.draw(i.getSprite());
    }
    
    std::vector<Player>& players = game.getPlayers();
    for(auto &i : players) {
        window.draw(i.getSprite());
        i.updateSpritePosition();
    }
    
    std::vector<Projectile>& projectiles = game.getProjectiles();
    for (auto &i : projectiles) {
        window.draw(i.getSprite());
        i.updateSpritePosition();
    }
    
    // statusbar
    sf::Vector2u windowSize = window.getSize();
    int statusBarHeight = 100;
    sf::RectangleShape background(sf::Vector2f(windowSize.x, statusBarHeight));
    background.setPosition(0, windowSize.y - statusBarHeight);
    background.setFillColor(sf::Color(150, 0, 0, 155));
    window.draw(background);
    
    sf::Font font;
    font.loadFromFile("assets/BebasNeue.otf");
    
    // Draw player data for each player
    int i = 0;
    for(auto &p : players) {
        int box_x = 10 + i * 100;
        int box_baseline_y = windowSize.y - 32;
        sf::Text name = sf::Text(p.getName(), font, 16);
        name.setPosition(box_x, box_baseline_y - 16);
        sf::Text hp = sf::Text("HP" + std::to_string(p.getHealth()) + "/100", font, 16);
        hp.setPosition(box_x, box_baseline_y);
        window.draw(name);
        window.draw(hp);
        i++;
    }
    
    sf::Texture overlayTexture;
    overlayTexture.loadFromImage(game.getOverlayImage());
    sf::Sprite overlay;
    overlay.setTexture(overlayTexture);
    window.draw(overlay);
}

void GameScene::onEvent(sf::Event& event) {
    switch (event.type)
    {
        case sf::Event::KeyPressed: {
            sf::Vector2u& v = keyboard[event.key.code];
            //std::cout << "painettiin:" << event.key.code << ", " << v.x << ", " << v.y << std::endl;
            if(!v.x) {
                v.x = 1; //on/off
                v.y = 0; //time
            }
            
            if (event.key.code == sf::Keyboard::LControl) {
                AudioManager::getInstance().playSound("lazer");
                Player& player = game.getPlayers()[0];
                Projectile p = player.useWeapon();
                game.addProjectile(p);
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

void GameScene::update() {
    for(auto& i : keyboard) {
        if(i.second.x) {
            i.second.y ++;
            
            //std::cout << i.second.y << std::endl;
            
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
    
    std::vector<Projectile>& projectiles = game.getProjectiles();
    for (auto &i : projectiles) {
        i.update();
    }
}



