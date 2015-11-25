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

#include <SFML/Graphics.hpp>

class Entity {
public:
    Entity(): sprite(), x(0), y(0), health(0), name() {}
    Entity(const sf::Sprite& sp, int x, int y, int hp, const std::string& name) : 
    sprite(sp), x(x), y(y), 
    health(hp), name(name) {};
    Entity(const Entity& orig);
    virtual ~Entity();
    const sf::Sprite& getSprite() const; 
    const std::tuple<int, int> getPos() const;
    void setPos(int x, int y);
protected:
    std::string name;
    int health;
    sf::Sprite sprite;
    int x;
    int y;
};

#endif /* ENTITY_H */

