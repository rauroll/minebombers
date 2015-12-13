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

Treasure::Treasure(sf::Sprite& sprite, uint32_t score, uint32_t value, sf::Vector2u pos) : sprite(sprite), value(value), position(pos), score(score) {
    sprite.setPosition(pos.x * 16, pos.y * 16);
}

Treasure::Treasure(const Treasure& orig) {
    sprite = orig.sprite;
    value = orig.value;
    score = orig.score;
    position = orig.position;
    sprite.setPosition(position.x * 16, position.y * 16);
}

Treasure::~Treasure() {
}

uint32_t Treasure::getScore() const {
    return score;
}


uint32_t Treasure::getValue() const {
    return value;
}

sf::Vector2u Treasure::getPosition() const {
    return position;
}

sf::Sprite& Treasure::getSprite() {
    return sprite;
}
