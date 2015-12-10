/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ShopScene.h
 * Author: Max
 *
 * Created on December 10, 2015, 6:23 PM
 */

#ifndef SHOPSCENE_H
#define SHOPSCENE_H

#include "Scene.h"

class ShopScene : public Scene {
public:
    ShopScene();
    ShopScene(const ShopScene& orig);
    virtual ~ShopScene();
    
    void update();
    void onEvent(sf::Event& event);
    void draw(sf::RenderWindow& window);
private:
    std::vector<int> playerSelections{0,0};
    std::vector<std::string> weapons{"ase 1", "ase 2", "ase 3", "sun mutsi"};
    sf::Clock clock;
};

#endif /* SHOPSCENE_H */

