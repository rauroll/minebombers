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

const sf::Sprite& Entity::getSprite() {
    return sprite;
} 

std::tuple<int, int> Entity::getPos() {
    return std::tuple<int, int>(x, y);
}

void Entity::setPos(int newX, int newY) {
    x = newX;
    y = newY;
}


