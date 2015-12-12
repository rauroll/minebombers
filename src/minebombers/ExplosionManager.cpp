/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ExplosionManager.cpp
 * Author: Olli
 * 
 * Created on December 12, 2015, 6:21 PM
 */

#include "ExplosionManager.h"
#include <SFML/Graphics.hpp>

#include <algorithm>

#include "Game.h"
#include "ResourceManager.h"

#include "ExplosionType.h"

#include <iostream>


ExplosionManager::ExplosionManager() {
    this->directions.clear();
    this->directions.push_back(sf::Vector2i(0, -1));
    this->directions.push_back(sf::Vector2i(0, 1));
    this->directions.push_back(sf::Vector2i(-1, 0));
    this->directions.push_back(sf::Vector2i(1, 0));
}

ExplosionManager::~ExplosionManager() {
    
}

void ExplosionManager::crossExplosion(Projectile& projectile) {
    Game& game = Game::getInstance();
    Map& map = game.getMap();
    sf::Vector2u loc = projectile.getPos();
    std::vector<Player>& players = game.getPlayers();
    sf::Vector2u radius = projectile.getRadius();
    int damage = projectile.getDamage();
    
    for (auto dir : directions) {
        auto currentLoc = (sf::Vector2u)((sf::Vector2i)loc + dir);
        
        unsigned int rangeLeft = projectile.getRadius().x;
        while (!game.getMap().wallAt(currentLoc) && rangeLeft > 0) {
            Effect effect = Effect(projectile.getEffect());
            effect.setPos(currentLoc);

            game.addEffect(effect);
            map.damageTile(currentLoc, damage);

            for (auto& p : players) {
                if (p.getPos() == currentLoc) {
                    p.reduceHealth(damage);
                }
            }
            currentLoc = (sf::Vector2u)((sf::Vector2i)currentLoc + dir);
            rangeLeft--;
        }
    }
    
    Effect effect = Effect(projectile.getEffect());
    
    effect.setPos(loc);

    game.addEffect(effect);
    map.damageTile(loc, damage);

    for (auto& p : players) {
        if (p.getPos() == loc) {
            p.reduceHealth(damage);
        }
    }

    ResourceManager::getInstance().playExplosion(damage, projectile.getExplosionAudioName());
}

void ExplosionManager::recursiveExplosion(Projectile& projectile) {
    
}
    
void ExplosionManager::circleExplosion(Projectile& projectile) {
    
    
}

void ExplosionManager::recursiveCircleExplosion(Projectile& projectile) {
    
}

void ExplosionManager::explode(Projectile& projectile) {
    switch (projectile.getExplosionType()) {
        case CROSS:
            this->crossExplosion(projectile);
            break;
        case CROSSREC:
            break;
        case CIRCLE:
            break;
        case CIRCLEREC:
            break;
        case BOOMERANG:
            break;
        default:
            break;
    }
}