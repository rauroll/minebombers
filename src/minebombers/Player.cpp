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

void Player::nextWeapon() {
    ++activeWeapon;
    if (activeWeapon == weaponsMap.end()) {
        activeWeapon = weaponsMap.begin();
    }
}

void Player::removeAllWeapons() {
    this->weaponsMap.clear();
}

void Player::addWeapon(Weapon& weapon) {
    weaponsMap[weapon.getName()] = 10;
    this->activeWeapon = weaponsMap.begin();
}

int Player::getMoney() const {
    return this->money;
}

Weapon& Player::getActiveWeapon() {
    return WeaponManager::getInstance().getWeapon(activeWeapon->first);
}

unsigned int Player::getAmmo() {
    return activeWeapon->second;
}

// This method isn't responsible for checking for ammo
Projectile Player::useWeapon() {
    Weapon& wep = this->getActiveWeapon();
    if (activeWeapon->second < 999) activeWeapon->second--;
    return wep.use(this->getPos(), this->getDir());
}

bool Player::hasAmmo() {
    return activeWeapon->second > 0;
}
