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
#include <SFML/System.hpp>

class Projectile : public MyDrawable {
public:
    Projectile(const std::string& name, const std::string& texturefile, int damage, sf::Vector2u radius = sf::Vector2u(1, 1), sf::Time timer = sf::milliseconds(5000));
    Projectile(const Projectile& orig);
    
    void setDirection(sf::Vector2u dir);
    
    void update();
    virtual ~Projectile();
    void explode();
private:
    int damage;
    sf::Vector2u dir;
    sf::Vector2u radius;
    bool state;
    sf::Time timer;
};

#endif /* BULLET_H */

