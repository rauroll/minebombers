/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Projectile.cpp
 * Author: Olli
 * 
 * Created on December 3, 2015, 12:56 PM
 */

#include "Projectile.h"

Projectile::Projectile(const std::string& texturefile, sf::Vector2u loc, sf::Vector2u dir) : MyDrawable(texturefile, loc.x, loc.y, name) {
    
}

Projectile::Projectile(const Projectile& orig) {
}

Projectile::~Projectile() {
}

