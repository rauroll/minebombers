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

Weapon::Weapon(Map& map) {
    this->map = map;
}

Weapon::Weapon(const Weapon& orig) {
}

Weapon::~Weapon() {
}

