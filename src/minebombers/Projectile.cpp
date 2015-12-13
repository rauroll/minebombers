/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Projectile.cpp
 * Author: Olli
 * 
 * Created on December 3, 2015, 12:56 PM
 */

#include <iostream>
#include <algorithm>

#include "Projectile.h"
#include "Game.h"
#include "ResourceManager.h"
#include "ExplosionManager.h"


Projectile::Projectile(const std::string& name, const std::string& texturefile, const std::string& audioName, int damage, Effect& effect, ProjectileType projectileType, ExplosionType explosionType, sf::Vector2u radius, sf::Time timer, unsigned int range) : MyDrawable(texturefile, 0, 0, name), effect(effect) {
    this->damage = damage;
    this->dir = dir;
    this->radius = radius;
    this->projectileType = projectileType;
    this->explosionType = explosionType;
    this->timer = timer;
    this->alwaysStillSprite = true;
    this->explosionAudioName = audioName;
    this->range = range;
}

Projectile::Projectile(const Projectile& orig) : MyDrawable(orig), effect(orig.effect) {
    this->dir = orig.dir;
    this->damage = orig.damage;
    this->position = orig.position;
    this->radius = orig.radius;
    this->projectileType = orig.projectileType;
    this->explosionType = orig.explosionType;
    this->timer = orig.timer;
    this->alwaysStillSprite = orig.alwaysStillSprite;
    this->explosionAudioName = orig.explosionAudioName;
    this->range = orig.range;
    this->userName = orig.userName;
}

Projectile::~Projectile() {
    
}

void Projectile::move(sf::Vector2u dir) {
    MyDrawable::move(dir);
    this->moved++;
}

void Projectile::setDirection(sf::Vector2u dir) {
    this->dir = dir;
}

bool Projectile::update(sf::Time dt) {
    switch (this->projectileType) {
        case PROJECTILE:
            return this->updateProjectile();
            break;
        case EXPLOSIVE:
            return this->updateBomb(dt);
            break;
        case PICK:
            return this->updatePick();
            break;
        case MINE:
            return this->updateBomb(dt);
            break;
        case ACTIVATEDMINE:
            return this->updateProjectile();
            break;
        default:
            return false;
    }
}

bool Projectile::updateProjectile() {
    stepper++;
    if (stepper % 2 == 1) {
        Game &game = Game::getInstance();
        sf::Vector2u nextLocation = this->getPos() + this->dir;
        bool playerHit = false;
        for (auto& p : game.getPlayers()) {
            if ((p.getPos() == nextLocation && p.isAlive()
                    && (p.getName() != this->userName
                    || this->projectileType == ACTIVATEDMINE))
                    || this->reachedMaxRange()) {
                ExplosionManager::getInstance().explode(*this);
                return true;
            }
        }
        
        if (game.getMap().floorAt(nextLocation)) {
            this->move(this->dir);
        } else {
            ExplosionManager::getInstance().explode(*this);
            return true;
        }
    }
    return false;
}

bool Projectile::updateBomb(sf::Time dt) {
    this->timer -= dt;
    if (this->timer <= sf::milliseconds(0)) {
        if (this->projectileType == MINE) {
            this->setProjectileType(ACTIVATEDMINE);
            this->setDirection(sf::Vector2u(0, 0));
        } else {
            ExplosionManager::getInstance().explode(*this);
            return true;
        }
    }
    return false;
}

bool Projectile::updatePick() {
    Game& game = Game::getInstance();
    Map& map = game.getMap();
    sf::Vector2u loc = this->getPos() + this->dir;
    std::vector<Player>& players = game.getPlayers();
    
    map.damageTile(loc, this->damage);
    
    return true;
}

bool Projectile::reachedMaxRange() {
    return (this->moved >= this->range) && this->range != 0;
}



Effect& Projectile::getEffect() {
    return this->effect;
}

sf::Vector2u Projectile::getRadius() {
    return this->radius;
}

int Projectile::getDamage() {
    return this->damage;
}

std::string Projectile::getExplosionAudioName() {
    return this->explosionAudioName;
}

ExplosionType Projectile::getExplosionType() {
    return this->explosionType;
}

void Projectile::setProjectileType(ProjectileType projectileType) {
    this->projectileType = projectileType;
}

void Projectile::setTimer(sf::Time newTime) {
    this->timer = newTime;
}

void Projectile::setUser(std::string playerName) {
    this->userName = playerName;
}

std::string Projectile::getUser() {
    return this->userName;
}

