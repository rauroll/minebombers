/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Projectile.h
 * Author: Olli
 *
 * Created on December 3, 2015, 12:56 PM
 */

#ifndef PROJECTILE_H
#define PROJECTILE_H

#include <SFML/Graphics.hpp>
#include "MyDrawable.h"

class Projectile : public MyDrawable {
public:
    Projectile(const std::string& name, const std::string& texturefile, int damage, sf::Vector2u loc, sf::Vector2u dir);
    Projectile(const Projectile& orig);
    virtual ~Projectile();
    
private:
    int damage;
    sf::Vector2u dir;
    
};

#endif /* BULLET_H */

