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
#include <cmath>

#include "Game.h"
#include "ResourceManager.h"

#include "ExplosionType.h"
#include "ButtonReaction.h"

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
    std::vector<Projectile>& projectiles = game.getProjectiles();
    sf::Vector2u radius = projectile.getRadius();
    int damage = projectile.getDamage();
    
    for (auto dir : directions) {
        auto currentLoc = (sf::Vector2u)((sf::Vector2i)loc + dir);
        
        unsigned int rangeLeft = projectile.getRadius().x;

        while (!map.wallAt(currentLoc) && rangeLeft > 0) {
            Effect effect = Effect(projectile.getEffect());
            effect.setPos(currentLoc);

            game.addEffect(effect);
            map.damageTile(currentLoc, damage);

            for (auto& p : players) {
                if (p.getPos() == currentLoc) {
                    p.reduceHealth(damage, projectile.getUser());
                }
            }
            for (auto& p : projectiles) {
                if (p.getPos() == currentLoc) {
                    this->chainExplode(p);
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
            p.reduceHealth(damage, projectile.getUser());
        }
    }

}

void ExplosionManager::recursiveExplosion(Projectile& projectile) {
    
}
    
void ExplosionManager::circleExplosion(Projectile& projectile) {
    Game& game = Game::getInstance();
    Map& map = game.getMap();
    sf::Vector2u loc = projectile.getPos();
    std::vector<Player>& players = game.getPlayers();
    std::vector<Projectile>& projectiles = game.getProjectiles();
    sf::Vector2u radius = projectile.getRadius();
    int damage = projectile.getDamage();
    
    int lowest = 1;
    int lowerBoundX = std::max((int)(loc.x - radius.x), lowest);
    int lowerBoundY = std::max((int)(loc.y - radius.y), lowest);
    int upperBoundX = std::min(loc.x + radius.x, map.getSize().x-1);
    int upperBoundY = std::min(loc.y + radius.y, map.getSize().y-1);
    
    
//    Please do not remove these comments yet
//    
//    std::cout << "Map size: " << map.getSize().x << ", " << map.getSize().y << std::endl;
//    std::cout << "Bomb dropped at " << loc.x << ", " << loc.y << std::endl;
//    
//    std::cout << "Lower x" << lowerBoundX << std::endl;
//    std::cout << "Upper x" << upperBoundX << std::endl;
//    std::cout << "Lower y" << lowerBoundY << std::endl;
//    std::cout << "Upper y" << upperBoundY << std::endl;
    
    
    for (auto i = lowerBoundX; i < upperBoundX; i++) {
        for (auto j = lowerBoundY; j < upperBoundY; j++) {
            sf::Vector2u explosionLoc = sf::Vector2u(i, j);
            if (euclideanDistance((sf::Vector2i)loc, (sf::Vector2i)explosionLoc) < radius.x && !map.wallAt(explosionLoc)) {
                Effect effect = Effect(projectile.getEffect());

                effect.setPos(explosionLoc);

                game.addEffect(effect);
                map.damageTile(explosionLoc, damage);

                for (auto& p : players) {
                    if (p.getPos() == explosionLoc) {
                        p.reduceHealth(damage, projectile.getUser());
                    }
                }
                for (auto& p : projectiles) {
                    if (p.getPos() == explosionLoc) {
                        this->chainExplode(p);
                    }
                }
            }
        }
    }
    
    
}

unsigned int ExplosionManager::euclideanDistance(sf::Vector2i v1, sf::Vector2i v2) {
//    Please do not remove these comments yet
//    
//    std::cout << "v1: " << v1.x << ", " << v1.y << " and v2: " << v2.x << ", " << v2.y << std::endl;
//    std::cout << "Euclidean distance: " << sqrt(pow(v1.x - v2.x, 2) + pow(v1.y - v2.y, 2));
    return (unsigned int) sqrt(pow(v1.x - v2.x, 2) + pow(v1.y - v2.y, 2));
}

void ExplosionManager::recursiveCircleExplosion(Projectile& projectile) {
    
}

void ExplosionManager::chainExplode(Projectile& projectile) {
    projectile.setProjectileType(EXPLOSIVE);
    projectile.setTimer(sf::milliseconds(100));
}

void ExplosionManager::explode(Projectile& projectile) {
    switch (projectile.getExplosionType()) {
        case CROSS:
            this->crossExplosion(projectile);
            break;
        case CROSSREC:
            break;
        case CIRCLE:
            this->circleExplosion(projectile);
            break;
        case PICK:
            this->crossExplosion(projectile);
            break;
        default:
            break;
    }
    ResourceManager::getInstance().playExplosion(projectile.getDamage(), projectile.getExplosionAudioName());
}