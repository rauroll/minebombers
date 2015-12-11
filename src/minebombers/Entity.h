/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Entity.h
 * Author: Olli
 *
 * Created on December 4, 2015, 2:13 PM
 */

#ifndef ENTITY_H
#define ENTITY_H

#include "MyDrawable.h"

class Entity : public MyDrawable {
public:
    Entity();
    Entity(const std::string texturefile, int x, int y, int hp, const std::string& name);
    Entity(const Entity& orig);
    virtual ~Entity();
    
    int getHealth();
    void reduceHealth(int damage);
    bool isAlive();
private:
    
    int health;
};

#endif /* ENTITY_H */

