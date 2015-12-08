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

GameScene::GameScene(Game& game) : game(game) {
    
}

GameScene::GameScene(const GameScene& orig) : game(orig.game) {
    
}

GameScene::~GameScene() {
}

void GameScene::draw(sf::RenderWindow& window) {
    window.draw(game.getMap());
    
    const std::vector<Treasure>& treasures = game.getTreasures();
    for(auto i : treasures) {
        window.draw(i.getSprite());
    }
    
    std::vector<Player>& players = game.getPlayers();
    for(auto& i : players) {
        window.draw(i.getSprite());
        i.updateSpritePosition();
    }
    
    std::vector<Projectile>& projectiles = game.getProjectiles();
    for (auto i : projectiles) {
        window.draw(i.getSprite());
        i.updateSpritePosition();
    }
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
                Player& player = game.getPlayers()[0];
                Projectile p = player.useWeapon(sf::Vector2u(0, 1));
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
    for (auto i : projectiles) {
        i.update();
    }
    
}



