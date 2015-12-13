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

#include <SFML/System.hpp>

#include "Scene.h"
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
    int selectedMap = 0;
    
    std::vector<std::string> options{"2 players", "3 players", "4 players"};
    std::vector<std::string> maps{"generated map", "map1.asd", "map2.asd"};
};

#endif /* MENUSCENE_H */

