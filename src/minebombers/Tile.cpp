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

#include <algorithm>
#include <iostream>
#include "Tile.h"

Tile::Tile(int level, int id, TileType type) {
    this->level = level;
    this->startLevel = level;
    this->id = id;
    this->maxHp = 100;
    this->hp = this->maxHp;
    this->type = type;
    this->visible = false;
}

Tile::Tile(const Tile& orig) {
    level = orig.level;
    startLevel = orig.startLevel;
    id = orig.id;
    this->maxHp = orig.maxHp;
    this->hp = this->maxHp;
    type = orig.type;
    visible = orig.visible;
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

int Tile::getStartLevel() const {
    return startLevel;
}

void Tile::setVisible() {
    this->visible = true;
}

bool Tile::isVisible() const {
    return visible;
}

void Tile::setLevel(int level) {
    this->level = level;
}

void Tile::setHp(int hp) {
    this->hp = hp;
}

void Tile::reduceLevel(int dmg) {
    this->hp = std::max(0, this->hp - dmg);
    this->level = ((float) this->hp / this->maxHp) * this->startLevel;
}

TileType Tile::getType() const {
    return type;
}

