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
    Entity();
    Entity(const std::string texturefile, int x, int y, int hp, const std::string& name);
    Entity(const Entity& orig);
    
    virtual ~Entity();
    
    const sf::Sprite& getSprite() const; 
    const std::tuple<int, int> getPos() const;
    void setPos(int x, int y);
    void move(sf::Vector2u dir);
    
    std::string getName() const;
protected:
    std::string name;
    int health;
    sf::Sprite sprite;
    int x;
    int y;
};

#endif /* ENTITY_H */

