/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   WeaponManager.h
 * Author: Olli
 *
 * Created on December 12, 2015, 1:04 PM
 */

#ifndef WEAPONMANAGER_H
#define WEAPONMANAGER_H

#include "Weapon.h"
#include "Player.h"

class WeaponManager {
public:
    WeaponManager();
    virtual ~WeaponManager();
    
    static WeaponManager& getInstance() {
        static WeaponManager instance;
        return instance;
    }
    
    void createWeapons();
    void addWeaponsToPlayer(Player& player);
    void addWeapon(Weapon weapon);
    Weapon& getWeapon(std::string name);
    
    
    
    

private:
    std::vector<Weapon> weapons;
};

#endif /* WEAPONMANAGER_H */

