/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Entity.cpp
 * Author: Olli
 * 
 * Created on December 4, 2015, 2:13 PM
 */

#include "Entity.h"
#include "MyDrawable.h"

Entity::Entity() {
    
}

Entity::Entity(const std::string texturefile, int x, int y, int hp, const std::string& name) : MyDrawable(texturefile, x, y, name) {
    this->health = hp;
}

Entity::Entity(const Entity& orig) /* inherit mydrawable here */{
    this->health = orig.health;
}

Entity::~Entity() {
}

