/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   WeaponManager.cpp
 * Author: Olli
 * 
 * Created on December 12, 2015, 1:04 PM
 */

#include "WeaponManager.h"
#include <iostream>

WeaponManager::WeaponManager() {
    this->createWeapons();
}

WeaponManager::~WeaponManager() {
}

void WeaponManager::createWeapons() {
    this->weapons.clear();
    
    // Effects
    Effect explosion = Effect("Explosion", "assets/explosion.png", sf::Vector2u(0, 0), true);
    


// The current constructor for projectiles ===============================    
//                Projectile(const std::string& name,
//                           const std::string& texturefile,
//                           const std::string& audioName,
//                           int damage,
//                           Effect& effect,
//                           sf::Vector2u radius = sf::Vector2u(1, 1),
//                           sf::Time timer = sf::milliseconds(5000))

    
    // Projectiles
    Projectile proj = Projectile("jonnemissile", "assets/projectile.png", "explosion", 30, explosion, sf::Vector2u(5, 5));
    Projectile bomb = Projectile("keilapommi", "assets/bomb.png", "boom", 50, explosion, sf::Vector2u(100, 100));
    
    
    //Weapons
    this->addWeapon(Weapon("jonnegun", "lazer", 99, proj));
    this->addWeapon(Weapon("bomb", "shot", 99, bomb));
    
}

void WeaponManager::addWeaponsToPlayer(Player& player) {
    player.removeAllWeapons();
    for (auto& w : weapons) {
        player.addWeapon(w);
    }
}

void WeaponManager::addWeapon(Weapon weapon) {
    this->weapons.push_back(weapon);
}

Weapon& WeaponManager::getWeapon(std::string name) {
    for (auto& w : weapons) {
        if (w.getName() == name) {
            return w;
        }
    }
    
    // Default weapon is the first one - the weapons vector is expected to never be empty.
    return weapons[0];
}

