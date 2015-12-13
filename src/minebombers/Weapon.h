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

#include <SFML/Graphics.hpp>
#include <string>

#include "Map.h"
#include "Projectile.h"

class Weapon {
public:
    Weapon(std::string name, std::string shotAudioName, int price, Projectile projectile);
    Weapon(const Weapon& orig);
    virtual ~Weapon();
    
    Projectile use(sf::Vector2u loc, sf::Vector2u dir);
    
    const Projectile& getProjectile();
    
    void addAmmo(int amount);
    int getAmmoCount() const;
    int getPrice() const;
    
    std::string getName();
    
protected:
    std::string shotAudioName;
    std::string name;
    int ammoCount;
    int price;
    Projectile projectile;
    
};

#endif /* WEAPON_H */

