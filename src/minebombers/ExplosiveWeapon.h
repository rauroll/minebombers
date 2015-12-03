/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ExplosiveWeapon.h
 * Author: Olli
 *
 * Created on December 2, 2015, 1:55 PM
 */



#ifndef EXPLOSIVEWEAPON_H
#define EXPLOSIVEWEAPON_H

#include "Weapon.h"
#include "Map.h"

#include <SFML/Graphics.hpp>

class ExplosiveWeapon : public Weapon {
public:
    ExplosiveWeapon(Map& map, Explosive& explosive);
    ExplosiveWeapon(const ExplosiveWeapon& orig);
    virtual ~ExplosiveWeapon();
    
    void use(sf::Vector2u loc, sf::Vector2u dir);
    
private:
    
    Explosive &explosive;
    
    

};

#endif /* EXPLOSIVEWEAPON_H */

