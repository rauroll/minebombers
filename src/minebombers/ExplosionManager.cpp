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


ExplosionManager::ExplosionManager() {
    
}

ExplosionManager::~ExplosionManager() {
    
}

void crossExplosion(Projectile& projectile) {
    Game& game = Game::game();
    Map& map = game.getMap();
    sf::Vector2u loc = projectile.getPos();
    std::vector<Player>& players = game.getPlayers();
    sf::Vector2u radius = projectile.getRadius();
    int damage = projectile.getDamage();
    
    
    int zero = 1;
    for (auto i = std::max((int)(loc.x - radius.x), zero); i < std::min(loc.x + radius.x, map.getSize().x-1); i++) {
        Effect effect = Effect(projectile.getEffect());
        
        sf::Vector2u explosionLoc = sf::Vector2u(i, loc.y);
        effect.setPos(explosionLoc);
        
        game.addEffect(effect);
        map.damageTile(explosionLoc, damage);

        for (auto& p : players) {
            if (p.getPos() == explosionLoc) {
                p.reduceHealth(damage);
            }    
        }
    }
    
    for (auto i = std::max((int)(loc.y - radius.y), zero); i < std::min(loc.y + radius.y, map.getSize().y-1); i++) {
        if (i == loc.y) continue;
        
        Effect effect = Effect(projectile.getEffect());
        sf::Vector2u explosionLoc = sf::Vector2u(loc.x, i);
        effect.setPos(explosionLoc);
        
        game.addEffect(effect);
        map.damageTile(explosionLoc, damage);
        for (auto& p : players) {
            if (p.getPos() == explosionLoc) {
                p.reduceHealth(damage);
            }    
        }
    }

    ResourceManager::getInstance().playExplosion(damage, projectile.getExplosionAudioName());
}

void recursiveExplosion(Projectile& projectile) {
    
}
    
void circleExplosion(Projectile& projectile) {
    
}

void recursiveCircleExplosion(Projectile& projectile) {
    
}

void explode(Projectile& projectile) {
    switch (projectile.getExplosionType()) {
        case CROSS:
            crossExplosion(projectile);
            break;
        case CROSSREC:
            break;
        case CIRCLE:
            break;
        case CIRCLEREC:
            break;
        case BOOMERANG:
            break;
    }
}