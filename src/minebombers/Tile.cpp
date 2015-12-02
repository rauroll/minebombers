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

Tile::Tile(int level, int id, TileType type) {
    this->level = level;
    this->id = id;
    this->type = type;
}

Tile::Tile(const Tile& orig) {
    level = orig.level;
    id = orig.id;
    type = orig.type;
}

Tile::~Tile() {
}

int Tile::getId() const {
    return id;
}

void Tile::setId(int id) {
    this->id = id;
}

int Tile::getLevel() const {
    return level;
}

void Tile::setLevel(int level) {
    this->level = level;
}

TileType Tile::getType() const {
    return type;
}

