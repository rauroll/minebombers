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
    Player player = game.getPlayer();
    
    //std::cout << "Player: " << player.getName() << std::endl;
    
    const sf::Sprite& sprite = player.getSprite();
    
    //sf::Sprite sprite = sf::Sprite(texture);   
 
    window.draw(sprite);
}

void GameScene::onEvent(sf::Event& event) {

}

void GameScene::update() {
    Map& map = game.getMap();
    int tile = rand() % 50;
    //map.setTileId(rand() % map.getWidth(), rand() % map.getHeight(), tile);
}



