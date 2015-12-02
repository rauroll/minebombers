/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Treasure.cpp
 * Author: Jere
 * 
 * Created on 17. marraskuuta 2015, 17:59
 */

#include "Treasure.h"

Treasure::Treasure(sf::Sprite& sprite, uint32_t value, sf::Vector2u pos) {
    this->sprite = sprite;
    this->value = value;
    this->position = pos;
}

Treasure::Treasure(const Treasure& orig) {
    sprite = orig.sprite;
    value = orig.value;
    position = orig.position;
}

Treasure::~Treasure() {
}

uint32_t Treasure::getValue() const {
    return value;
}

sf::Vector2u Treasure::getPosition() const {
    return position;
}


