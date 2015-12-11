/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MenuScene.h
 * Author: Max
 *
 * Created on November 17, 2015, 2:23 PM
 */

#ifndef MENUSCENE_H
#define MENUSCENE_H

#include "Scene.h"
#include <SFML/System.hpp>
#include "Game.h"

class MenuScene: public Scene {
public:
    MenuScene();
    virtual ~MenuScene();
    void update(sf::Time dt);
    void onEvent(sf::Event& event);
    void onChangedTo();
    void draw(sf::RenderWindow& window);

private:
    int logoPhase = 0;
    int selected = 0;
    
    float twoPlayerScale = 0.9;
    float campaignScale = 0.9;
};

#endif /* MENUSCENE_H */

