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

class MenuScene: public Scene {
public:
    MenuScene() {};
    MenuScene(const MenuScene& orig) {};
    virtual ~MenuScene();
    void update();
    void onEvent(sf::Event& event);
    void draw(sf::RenderWindow& window);

private:
    
};

#endif /* MENUSCENE_H */

