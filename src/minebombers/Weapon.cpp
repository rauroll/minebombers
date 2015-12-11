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
#include "ResourceManager.h"

Weapon::Weapon(std::string name, std::string shotAudioName, int price, Projectile projectile) : projectile(projectile) {
    this->name = name;
    this->price = price;
    this->shotAudioName = shotAudioName;
}

Weapon::Weapon(const Weapon& orig) : projectile(orig.projectile) {
    this->name = orig.name;
    this->price = orig.price;
    this->shotAudioName = orig.shotAudioName;
}

Weapon::~Weapon() {
}

int Weapon::getAmmoCount() const {
    return this->ammoCount;
}

void Weapon::addAmmo(int amount) {
    this->ammoCount += amount;
}

std::string Weapon::getName() {
    return name;
}


Projectile Weapon::use(sf::Vector2u loc, sf::Vector2u dir) {
    Projectile p = Projectile(this->projectile);
    ResourceManager::getInstance().playSound(this->shotAudioName);
    p.setPos(loc.x, loc.y);
    p.setDirection(dir);
    return p;
}

