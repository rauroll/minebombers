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
//                           ProjectileType projectileType,
//                           ExplosionType explosionType,
//                           sf::Vector2u radius = sf::Vector2u(0, 0),
//                           sf::Time timer = sf::milliseconds(5000)),
//                           uint range = 0; (default to unlimited range)

    
    // Projectiles
    Projectile proj = Projectile("jonnemissile", "assets/projectile.png", "explosion", 30, explosion, PROJECTILE, CIRCLE, sf::Vector2u(2, 2));

    Projectile basicBomb = Projectile("sbomb", "assets/bomb.png", "boom", 30, explosion, EXPLOSIVE, CIRCLE, sf::Vector2u(5, 5), sf::milliseconds(2000));
    Projectile atomicBomb = Projectile("abomb", "assets/bomb.png", "boom", 50, explosion, EXPLOSIVE, CROSS, sf::Vector2u(100, 100), sf::milliseconds(4000));
    Projectile pick = Projectile("pick", "assets/projectile.png", "explosion", 10, explosion, PICK, CROSS, sf::Vector2u(0, 0), sf::milliseconds(0), 1);
    
    //Weapons
    this->addWeapon(Weapon("jonnegun", "lazer", 49, proj));
    this->addWeapon(Weapon("small bomb", "shot", 99, basicBomb));
    this->addWeapon(Weapon("atomic bomb", "shot", 200, atomicBomb));
    this->addWeapon(Weapon("pick", "pick", 0, pick));
    
}

void WeaponManager::addWeaponsToPlayer(Player& player) {
    player.removeAllWeapons();
    for (auto& w : weapons) {
        player.addWeapon(w);
    }
    // Add unlimited ammo to default weapon
    player.addAmmo("jonnegun", 999);
    player.addAmmo("bomb", 3);
    player.addAmmo("pick", 999);
    player.nextWeapon();
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

