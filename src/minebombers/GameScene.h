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

#include "Game.h"

class GameScene : public Scene {
public:
    GameScene(Game& game);
    GameScene(const GameScene& orig);
    virtual ~GameScene();
    
    void update();
    void onEvent(sf::Event& event);
    void draw(sf::RenderWindow& window);
private:
    Game& game;
};

#endif /* GAMESCENE_H */
