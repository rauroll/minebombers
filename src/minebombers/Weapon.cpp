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

Weapon::Weapon(std::string name, int price, int damage) {
    this->name = name;
    this->price = price;
    this->damage = damage;
}

Weapon::Weapon(const Weapon& orig) {
}

Weapon::~Weapon() {
}

void Weapon::use(Game& game, sf::Vector2u loc, sf::Vector2u dir) {
    
}

