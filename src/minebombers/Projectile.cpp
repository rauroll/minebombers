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

Projectile::Projectile(const std::string& name, const std::string& texturefile, int damage, sf::Vector2u radius, sf::Time timer) : MyDrawable(texturefile, 0, 0, name) {
    this->damage = damage;
    this->dir = dir;
    this->radius = radius;
    this->timer = timer;
}

Projectile::Projectile(const Projectile& orig) {
    
}

Projectile::Projectile(const Projectile& orig, sf::Vector2u loc, sf::Vector2u dir) : Projectile(orig) {
    this->dir = dir;
    this->position = loc;
}

Projectile::~Projectile() {
    
}

void Projectile::update() {
    this->position += this->dir;
}

void Projectile::explode() {
    
}

