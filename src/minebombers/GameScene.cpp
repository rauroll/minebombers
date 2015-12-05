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
    
    const std::vector<Player>& players = game.getPlayers();
    for(auto i : players) {
        window.draw(i.getSprite());
        i.updateSpritePosition();
    }
}

void GameScene::onEvent(sf::Event& event) {
    switch (event.type) {
          case sf::Event::KeyPressed:
              if (event.key.code == sf::Keyboard::Up)
                  game.movePlayer(0, sf::Vector2u(0, -1));
              if (event.key.code == sf::Keyboard::Right)
                  game.movePlayer(0, sf::Vector2u(1, 0));
              if (event.key.code == sf::Keyboard::Down)
                  game.movePlayer(0, sf::Vector2u(0, 1));
              if (event.key.code == sf::Keyboard::Left)
                  game.movePlayer(0, sf::Vector2u(-1, 0));
              
              break;
          default:
              break;
    }
}

void GameScene::update() {
    Map& map = game.getMap();
    int tile = rand() % 50;
    
    //map.setTileId(rand() % map.getWidth(), rand() % map.getHeight(), tile);
}



