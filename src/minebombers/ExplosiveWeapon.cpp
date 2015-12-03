/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ExplosiveWeapon.cpp
 * Author: Olli
 * 
 * Created on December 2, 2015, 1:55 PM
 */

#include "ExplosiveWeapon.h"

ExplosiveWeapon::ExplosiveWeapon(Map& map, Explosive& explosive) : Weapon(map) {
    this->explosive = explosive;
}

ExplosiveWeapon::ExplosiveWeapon(const ExplosiveWeapon& orig) : Weapon(orig) {
}

ExplosiveWeapon::~ExplosiveWeapon() {
}

void ExplosiveWeapon::use(sf::Vector2u loc, sf::Vector2u, Game) {
    Explosive expl = explosive.use(loc);
}
