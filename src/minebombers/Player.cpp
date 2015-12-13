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
#include <stdlib.h>

Player::Player() : money(0), score(0), Entity() {
    calculateColor();
}


Player::Player(const std::string& texturefile, int x, int y, const std::string& name) : Entity(texturefile, x, y, 100, name) {
    money = 0;
    score = 0;
    calculateColor();
}

Player::Player(const Player& orig) : Entity(orig){
    money = orig.money;
    score = orig.score;
    weaponsMap = std::map<std::string, unsigned int>(orig.weaponsMap);
    activeWeapon = orig.activeWeapon;
    calculateColor();
}

Player::~Player() {
}

const sf::Color& Player::getColor() {
    return color;
}


void Player::calculateColor() {
    int c = 0;
    for (int i = 0; i < name.size(); i++)
        c += (int) name[i];
    srand(c);
    color = sf::Color(50 +rand() % 150, 50 + rand() % 150, 50 + rand() % 150);
}


void Player::incrementMoney(uint32_t amount) {
    money += amount;
}

void Player::setMoney(uint32_t money) {
    this->money = money;
}


int Player::getScore() const {
    return score;
}

void Player::incrementScore(int amount) {
    score += amount;
}


void Player::nextWeapon() {
    while (true) {
        ++activeWeapon;
        if (activeWeapon == weaponsMap.end()) {
            activeWeapon = weaponsMap.begin();
        }
        if (activeWeapon->second > 0) break;
    }
    
}

void Player::removeAllWeapons() {
    this->weaponsMap.clear();
}

void Player::addWeapon(Weapon& weapon) {
    weaponsMap[weapon.getName()] = 0;
    this->activeWeapon = weaponsMap.begin();
}

uint32_t Player::getMoney() const {
    return this->money;
}

Weapon& Player::getActiveWeapon() {
    return WeaponManager::getInstance().getWeapon(activeWeapon->first);
}

unsigned int Player::getActiveWeaponAmmo() {
    return activeWeapon->second;
}

void Player::buyAmmo(std::string weaponName, unsigned int amount, int price) {
    if (weaponsMap.find(weaponName) == weaponsMap.end()) {
    } else {
        this->money -= price;
        weaponsMap[weaponName] += amount;
    }
}

unsigned int Player::getAmmo(std::string weaponName) {
    if (weaponsMap.find(weaponName) == weaponsMap.end()) {
        std::cout << "Weapon didn't exist" << std::endl;
        return 0;
    } else {
        int asd = weaponsMap[weaponName];
        return asd;
    }
}

// This method isn't responsible for checking for ammo
Projectile Player::useWeapon() {
    Weapon& wep = this->getActiveWeapon();
    if (activeWeapon->second < 999) activeWeapon->second--;
    return wep.use(this->name, this->getPos(), this->getDir());
}

bool Player::hasAmmo() {
    return activeWeapon->second > 0;
}
