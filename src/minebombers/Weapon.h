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
#include <SFML/Graphics.hpp>


class Weapon {
public:
    Weapon(Map& map);
    Weapon(const Weapon& orig);
    virtual ~Weapon();
    
    virtual void use(sf::Vector2u loc, sf::Vector2u dir) = 0;
    
protected:
    Map &map;

};

#endif /* WEAPON_H */

