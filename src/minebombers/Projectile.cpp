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

#include "Projectile.h"
#include <iostream>
#include <algorithm>
#include "Game.h"
#include "ResourceManager.h"

Projectile::Projectile(const std::string& name, const std::string& texturefile, const std::string& audioName, int damage, Effect& effect, sf::Vector2u radius, sf::Time timer) : MyDrawable(texturefile, 0, 0, name), effect(effect) {
    this->damage = damage;
    this->dir = dir;
    this->radius = radius;
    this->timer = timer;
    this->alwaysStillSprite = true;
    this->explosionAudioName = audioName;
}

Projectile::Projectile(const Projectile& orig) : MyDrawable(orig), effect(orig.effect) {
    this->dir = orig.dir;
    this->damage = orig.damage;
    this->position = orig.position;
    this->radius = orig.radius;
    this->timer = orig.timer;
    this->alwaysStillSprite = orig.alwaysStillSprite;
    this->explosionAudioName = orig.explosionAudioName;
}

Projectile::~Projectile() {
    
}

void Projectile::setDirection(sf::Vector2u dir) {
    this->dir = dir;
}

bool Projectile::update() {
    stepper++;
    if (stepper % 2 == 1) {
        Game &game = Game::game();
        if (game.getMap().floorAt(this->getPos() + this->dir)) {
            this->move(this->dir);
        } else {
            this->explode();
            return true;
        }
    }
    return false;
    
}

Effect& Projectile::getEffect() {
    return this->effect;
}

void Projectile::explode() {
    Game& game = Game::game();
    Map& map = game.getMap();
    sf::Vector2u loc = this->getPos();
    
    
    int zero = 1;
    for (auto i = std::max((int)(loc.x - radius.x), zero); i < std::min(loc.x + radius.x, map.getSize().x-1); i++) {
        Effect effect = Effect(this->getEffect());
        sf::Vector2u explosionLoc = sf::Vector2u(i, loc.y);
        effect.setPos(i, loc.y);
        game.addEffect(effect);
        map.damageTile(explosionLoc, this->damage);
    }
    
    for (auto i = std::max((int)(loc.y - radius.y), zero); i < std::min(loc.y + radius.y, map.getSize().y-1); i++) {
        
        if (i == loc.y) continue;
        Effect effect = Effect(this->getEffect());
        sf::Vector2u explosionLoc = sf::Vector2u(loc.x, i);
        effect.setPos(loc.x, i);
        game.addEffect(effect);
        map.damageTile(explosionLoc, this->damage);
    }
    ResourceManager::getInstance().playSound(this->explosionAudioName);
    
}

