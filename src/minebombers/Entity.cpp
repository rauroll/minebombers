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
#include <algorithm>
#include "ResourceManager.h"
#include "Game.h"

Entity::Entity() {
    
}

Entity::Entity(const std::string texturefile, int x, int y, int hp, const std::string& name) : MyDrawable(texturefile, x, y, name) {
    this->health = hp;
}

Entity::Entity(const Entity& orig) : MyDrawable(orig) {
    this->health = orig.health;
}

Entity::~Entity() {
}

int Entity::getHealth() {
    return this->health;
}

void Entity::reduceHealth(int damage) {
    bool wasAlive = this->isAlive();
    Game& game = Game::game();
    this->health = std::max(0, this->health - damage);
    if (wasAlive && this->isAlive()) {
        ResourceManager::getInstance().playSound("hurt1");
    } else if (wasAlive) {
        game.onPlayerDead();
        ResourceManager::getInstance().playSound("death2");
    }
}

bool Entity::isAlive() {
    return this->health > 0;
}
