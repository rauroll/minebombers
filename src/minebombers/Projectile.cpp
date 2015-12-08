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
#include <iostream>

Projectile::Projectile(const std::string& name, const std::string& texturefile, int damage, sf::Vector2u radius, sf::Time timer) : MyDrawable(texturefile, 0, 0, name) {
    this->damage = damage;
    this->dir = dir;
    this->radius = radius;
    this->timer = timer;
}

Projectile::Projectile(const Projectile& orig) : MyDrawable(orig) {
    this->dir = orig.dir;
    this->position = orig.position;
    this->radius = orig.radius;
    this->timer = orig.timer;
}

Projectile::~Projectile() {
}

void Projectile::setDirection(sf::Vector2u dir) {
    this->dir = dir;
}

void Projectile::update() {
    this->move(this->dir);
}

void Projectile::explode() {
    
}

