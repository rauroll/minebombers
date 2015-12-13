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

#include <SFML/System.hpp>

#include "Scene.h"
#include "WeaponManager.h"
#include "Weapon.h"
#include "Player.h"

class ShopScene : public Scene {
public:
    ShopScene();
    ShopScene(const ShopScene& orig);
    virtual ~ShopScene();
    
    void update(sf::Time dt);
    void onEvent(sf::Event& event);
    void onChangedTo();
    void draw(sf::RenderWindow& window);
private:
    int shopTime;
    void buyAmmo(int playerId, Weapon weapon);
    std::vector<int> playerSelections;
    std::vector<Weapon> weapons;
    sf::Clock clock;
};

#endif /* SHOPSCENE_H */

