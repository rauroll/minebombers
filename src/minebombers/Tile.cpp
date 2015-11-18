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

Tile::Tile(int level, int id) {
    this->level = level;
    this->id = id;
}

Tile::Tile(const Tile& orig) {
    level = orig.level;
    id = orig.id;
}

Tile::~Tile() {
}

int Tile::getId() {
    return id;
}

int Tile::getLevel() {
    return level;
}
