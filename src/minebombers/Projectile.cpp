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
#include <algorithm>
#include "Game.h"

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

bool Projectile::update() {
    this->move(this->dir);
    bool collided = Game::game().isEntityAtPos(this->getPos()) || !Game::game().getMap().floorAt(this->getPos());
    if (collided) {
        this->explode();
    }
    return false;
    
}

void Projectile::explode() {
    Map& map = Game::game().getMap();
    sf::Vector2u loc = this->getPos();
    //for (auto i = std::max(loc.x - radius, 0); i < std::min(loc.x + radius, map.getSize().x); i++) {
    //    std::cout << "Explosion on: " << i << ", 0" << std::endl;
        // Cause damage to all affected entities and obstacles
                
    //}
    //for (auto i = std::max(loc.y - radius, 0); i < std::min(loc.y + radius, map.getSize().y); i++) {
    //    std::cout << "Explosion on: 0, " << i << std::endl;
        // Cause damage to all affected entities and obstacles
    //}
    
}

