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
#include "WeaponManager.h"

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

void Player::nextWeapon() {
    activeWeapon++;
    if (activeWeapon == weapons_map.end()) {
        activeWeapon = weapons_map.begin();
    }
}

void Player::addWeapon(Weapon& weapon) {
    weapons_map[weapon.getName()] = 10;
}

int Player::getMoney() const {
    return this->money;
}

Weapon& Player::getActiveWeapon() {
    WeaponManager::getInstance().getWeapon(activeWeapon->first);
}

Projectile Player::useWeapon() {
    Weapon& wep = this->getActiveWeapon();
    return wep.use(this->getPos(), this->getDir());
}
