/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Player.h
 * Author: Jere
 *
 * Created on 24. marraskuuta 2015, 14:34
 */

#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>

#include "Weapon.h"
#include "Entity.h"
#include "Projectile.h"


class Player: public Entity {
public:
    Player();
    Player(const std::string& texturefile, int x, int y, const std::string& name);
    Player(const Player& orig);
    virtual ~Player();
    
    void addWeapon(Weapon& weapon);
    void nextWeapon();
    void removeAllWeapons();
    Projectile useWeapon();
    unsigned int getAmmo();
    void addAmmo(std::string weaponName, unsigned int amount);
    bool hasAmmo();
    void incrementMoney(uint32_t amount);
    int getMoney() const;
private:
    Weapon& getActiveWeapon();
    std::map<std::string, unsigned int> weaponsMap;
    typedef std::map<std::string, unsigned int>::iterator weapon_iterator;
    weapon_iterator activeWeapon;
    uint32_t money;
};

#endif /* PLAYER_H */

