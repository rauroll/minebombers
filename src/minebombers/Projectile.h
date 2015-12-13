/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Projectile.h
 * Author: Olli
 *
 * Created on December 3, 2015, 12:56 PM
 */

#ifndef PROJECTILE_H
#define PROJECTILE_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include "MyDrawable.h"
#include "Effect.h"
#include "ProjectileType.h"
#include "ExplosionType.h"

class Projectile : public MyDrawable {
public:
    Projectile(const std::string& name, const std::string& texturefile, const std::string& audioName, int damage, Effect& effect, ProjectileType projectileType, ExplosionType explosionType, sf::Vector2u radius = sf::Vector2u(0, 0), sf::Time timer = sf::milliseconds(5000), unsigned int range = 0);
    Projectile(const Projectile& orig);
    
    void setDirection(sf::Vector2u dir);
    
    Effect& getEffect();
    sf::Vector2u getRadius();
    int getDamage();
    std::string getExplosionAudioName();
    ExplosionType getExplosionType();
    
    void setUser(std::string playerName);
    void getUser();
    
    
    bool update(sf::Time dt);
    bool updateProjectile();
    bool updateBomb(sf::Time dt);
    bool updatePick();
    bool reachedMaxRange();
    void move(sf::Vector2u dir);
    virtual ~Projectile();
    void explode();
private:
    std::string explosionAudioName;
    int damage;
    sf::Vector2u dir;
    sf::Vector2u radius;
    bool state;
    sf::Time timer;
    Effect effect;
    int stepper = 0;
    ProjectileType projectileType;
    ExplosionType explosionType;
    unsigned int range;
    unsigned int moved = 0;
    std::string userName = "default";
};

#endif /* BULLET_H */

