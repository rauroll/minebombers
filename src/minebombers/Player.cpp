/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Player.cpp
 * Author: Jere
 * 
 * Created on 24. marraskuuta 2015, 14:34
 */

#include "Player.h"
#include <iostream>

Player::Player() : Entity() {
    money = 0;
}


Player::Player(const std::string& texturefile, int x, int y, const std::string& name) : Entity(texturefile, x, y, 100, name) {
    money = 0;
}

Player::Player(const Player& orig) : Entity(orig){
    money = 0;
}

Player::~Player() {
}

void Player::incrementMoney(uint32_t amount) {
    money += amount;
}
