/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Entity.cpp
 * Author: Jere
 * 
 * Created on 17. marraskuuta 2015, 18:00
 */

#include "Entity.h"
#include "TextureManager.h"
#include <iostream>

Entity::Entity() : sprite(), x(0), y(0), health(0), name() {
}

Entity::Entity(const std::string texturefile, int x, int y, int hp, const std::string& name) {
    this->x = x;
    this->y = y;
    this->health = hp;
    this->name = name;

    sprite = sf::Sprite(TextureManager::getInstance().load(texturefile));
}

Entity::Entity(const Entity& orig) : sprite(orig.sprite) {
    x = orig.x;
    y = orig.y;
    health = orig.health;
    name = orig.name;
    
}

Entity::~Entity() {

}

const sf::Sprite& Entity::getSprite() const {
    return sprite;
} 

sf::Vector2u Entity::getPos() const {
    return sf::Vector2u(x, y);
}

std::string Entity::getName() const {
    return name;
}

void Entity::setPos(int newX, int newY) {
    x = newX;
    y = newY;
}

