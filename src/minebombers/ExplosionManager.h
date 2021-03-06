/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ExplosionManager.h
 * Author: Olli
 *
 * Created on December 12, 2015, 6:21 PM
 */

#ifndef EXPLOSIONMANAGER_H
#define EXPLOSIONMANAGER_H

#include <SFML/Graphics.hpp>
#include "Projectile.h"



class ExplosionManager {
public:
    ExplosionManager();
    virtual ~ExplosionManager();
    
    static ExplosionManager& getInstance() {
        static ExplosionManager instance;
        return instance;
    }
    
    void crossExplosion(Projectile& projectile);
    void recursiveExplosion(Projectile& projectile);
    
    void circleExplosion(Projectile& projectile);
    void recursiveCircleExplosion(Projectile& projectile);
    
    void chainExplode(Projectile& projectile);
    
    void explode(Projectile& projectile);
    
private:
    std::vector<sf::Vector2i> directions;
    unsigned int euclideanDistance(sf::Vector2i v1, sf::Vector2i v2);
    

};

#endif /* EXPLOSIONMANAGER_H */

