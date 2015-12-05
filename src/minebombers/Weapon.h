/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Weapon.h
 * Author: Olli
 *
 * Created on December 2, 2015, 1:29 PM
 */


#ifndef WEAPON_H
#define WEAPON_H

#include "Map.h"
#include "Game.h"
#include <SFML/Graphics.hpp>
#include <string.h>


class Weapon {
public:
    Weapon(std::string name, int price);
    Weapon(const Weapon& orig);
    virtual ~Weapon();
    
    void use(Game& game, sf::Vector2u loc, sf::Vector2u dir);
    
protected:
    std::string name;
    int price;
    
};

#endif /* WEAPON_H */

