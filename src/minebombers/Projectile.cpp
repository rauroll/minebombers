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

Projectile::Projectile(const std::string& name, const std::string& texturefile, const std::string& audioName, int damage, Effect& effect, ProjectileType projectileType, sf::Vector2u radius, sf::Time timer, unsigned int range) : MyDrawable(texturefile, 0, 0, name), effect(effect) {
    this->damage = damage;
    this->dir = dir;
    this->radius = radius;
    this->projectileType = projectileType;
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
    this->timer = orig.timer;
    this->alwaysStillSprite = orig.alwaysStillSprite;
    this->explosionAudioName = orig.explosionAudioName;
    this->range = orig.range;
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
            if ((p.getPos() == nextLocation && p.isAlive()) || this->reachedMaxRange()) {
                this->explode();
                return true;
            }
        }
        
        if (game.getMap().floorAt(nextLocation)) {
            this->move(this->dir);
        } else {
            this->explode();
            return true;
        }
    }
    return false;
}

bool Projectile::updateBomb(sf::Time dt) {
    this->timer -= dt;
    if (this->timer <= sf::milliseconds(0)) {
        this->explode();
        return true;
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

void Projectile::explode() {
    Game& game = Game::getInstance();
    Map& map = game.getMap();
    sf::Vector2u loc = this->getPos();
    std::vector<Player>& players = game.getPlayers();
    
    
    int zero = 1;
    for (auto i = std::max((int)(loc.x - radius.x), zero); i < std::min(loc.x + radius.x, map.getSize().x-1); i++) {
        Effect effect = Effect(this->getEffect());
        
        sf::Vector2u explosionLoc = sf::Vector2u(i, loc.y);
        effect.setPos(explosionLoc);
        
        game.addEffect(effect);
        map.damageTile(explosionLoc, this->damage);

        for (auto& p : players) {
            if (p.getPos() == explosionLoc) {
                p.reduceHealth(this->damage);
            }    
        }
    }
    
    for (auto i = std::max((int)(loc.y - radius.y), zero); i < std::min(loc.y + radius.y, map.getSize().y-1); i++) {
        if (i == loc.y) continue;
        
        Effect effect = Effect(this->getEffect());
        sf::Vector2u explosionLoc = sf::Vector2u(loc.x, i);
        effect.setPos(explosionLoc);
        
        game.addEffect(effect);
        map.damageTile(explosionLoc, this->damage);
        for (auto& p : players) {
            if (p.getPos() == explosionLoc) {
                p.reduceHealth(this->damage);
            }    
        }
    }

    ResourceManager::getInstance().playExplosion(this->damage, this->explosionAudioName);
}

