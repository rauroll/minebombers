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
    Effect explosion = Effect("Explosion", "assets/explosion.png", sf::Vector2u(0, 0));
    


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
    Projectile nuclearMissile = Projectile("nuc", "assets/nuclear_missile.png", "explosion", 50, explosion, PROJECTILE, CIRCLE, sf::Vector2u(12, 12));

    Projectile basicBomb = Projectile("sbomb", "assets/bomb.png", "boom", 30, explosion, EXPLOSIVE, CIRCLE, sf::Vector2u(4, 4), sf::milliseconds(1500));
    Projectile atomicBomb = Projectile("abomb", "assets/atomic_bomb.png", "boom", 70, explosion, EXPLOSIVE, CROSS, sf::Vector2u(100, 100), sf::milliseconds(4000));
    Projectile smallDynamite = Projectile("small dynamite", "assets/dynamite_small.png", "boom", 70, explosion, EXPLOSIVE, CROSS, sf::Vector2u(3, 3), sf::milliseconds(2000));
    Projectile bigDynamite = Projectile("big dynamite", "assets/dynamite_big.png", "boom", 70, explosion, EXPLOSIVE, CROSS, sf::Vector2u(10, 10), sf::milliseconds(3000));
    Projectile pick = Projectile("pick", "assets/projectile.png", "explosion", 20, explosion, PICK, CROSS, sf::Vector2u(0, 0), sf::milliseconds(0), 1);
    
    Projectile holybomb = Projectile("holybomb", "assets/teddy.png", "hugeboom", 120, explosion, EXPLOSIVE, CIRCLE, sf::Vector2u(50, 50), sf::milliseconds(4000));
    
    Projectile mineBomb = Projectile("landmine", "assets/mine.png", "boom", 100, explosion, MINE, CIRCLE, sf::Vector2u(5, 5), sf::milliseconds(5000));
    //Weapons
    this->addWeapon(Weapon("jonnegun", "lazer", 49, proj));
    this->addWeapon(Weapon("nuclear missile", "lazer", 1000, nuclearMissile));
    this->addWeapon(Weapon("small bomb", "shot", 300, basicBomb));
    this->addWeapon(Weapon("small dynamite", "ignite", 100, smallDynamite));
    this->addWeapon(Weapon("big dynamite", "ignite", 200, bigDynamite));
    this->addWeapon(Weapon("atomic bomb", "shot", 800, atomicBomb));
    this->addWeapon(Weapon("holy bomb", "allahuakbar", 5000, holybomb));
    this->addWeapon(Weapon("mine", "shot", 500, mineBomb));
    this->pick = Weapon("pick", "pick", 0, pick);
    
}

std::vector<Weapon> WeaponManager::getWeapons() {
    return this->weapons;
}

void WeaponManager::addWeaponsToPlayer(Player& player) {
    player.removeAllWeapons();
    for (auto& w : weapons) {
        player.addWeapon(w);
    }
    // starting ammo
    player.buyAmmo("jonnegun", 20, 0);
    player.buyAmmo("small bomb", 5, 0);
    player.buyAmmo("nuclear missile", 5, 0);
    player.buyAmmo("atomic bomb", 5, 0);
    player.buyAmmo("small dynamite", 5, 0);
    player.buyAmmo("big dynamite", 5, 0);
    player.buyAmmo("mine", 5, 0);
    player.buyAmmo("holy bomb", 1, 0);
    // Add unlimited ammo to default weapon
    player.buyAmmo("pick", 999, 0);
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

Weapon& WeaponManager::getPick() {
    return pick;
} 

