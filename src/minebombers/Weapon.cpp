/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Weapon.cpp
 * Author: Olli
 * 
 * Created on December 2, 2015, 1:29 PM
 */

#include "Weapon.h"

Weapon::Weapon(std::string name, int price, Projectile& projectile) : projectile(projectile) {
    this->name = name;
    this->price = price;
}

Weapon::Weapon(const Weapon& orig) : projectile(orig.projectile) {
    this->name = orig.name;
    this->price = orig.price;
}

Weapon::~Weapon() {
}

Projectile Weapon::use(sf::Vector2u loc, sf::Vector2u dir) {
    Projectile p = Projectile(this->projectile);
    p.setPos(loc.x, loc.y);
    p.setDirection(dir);
    return p;
}

