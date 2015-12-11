/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GameScene.h
 * Author: henrinurmi
 *
 * Created on November 18, 2015, 4:49 PM
 */

#ifndef GAMESCENE_H
#define GAMESCENE_H

#include <map>
#include <tuple>
#include <SFML/System.hpp>

#include "Game.h"

class GameScene : public Scene {
public:
    GameScene();
    GameScene(const GameScene& orig);
    virtual ~GameScene();
    
    void update(sf::Time dt);
    void onEvent(sf::Event& event);
    void onChangedTo();
    void draw(sf::RenderWindow& window);
private:
    std::map<sf::Keyboard::Key, sf::Vector2u> keyboard;
};

#endif /* GAMESCENE_H */

