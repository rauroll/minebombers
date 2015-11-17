/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Tile.cpp
 * Author: henrinurmi
 * 
 * Created on November 17, 2015, 5:53 PM
 */

#include "Tile.h"

Tile::Tile(int level, sf::Texture& texture) {
    this->level = level;
    this->texture = texture
}

Tile::Tile(const Tile& orig) {
}

Tile::~Tile() {
}

