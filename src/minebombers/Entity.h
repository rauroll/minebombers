/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Entity.h
 * Author: Jere
 *
 * Created on 17. marraskuuta 2015, 18:00
 */

#ifndef ENTITY_H
#define ENTITY_H

class Entity {
public:
    Entity();
    Entity(const Entity& orig);
    virtual ~Entity();
protected:
    std::string name;
    int health;
    sf::Sprite sprite;
    int x;
    int y;
};

#endif /* ENTITY_H */

