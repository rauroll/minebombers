/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MyDrawable.h
 * Author: Jere
 *
 * Created on 17. marraskuuta 2015, 18:00
 */

#ifndef MYDRAWABLE_H
#define MYDRAWABLE_H

#include <SFML/Graphics.hpp>

class MyDrawable {
public:
    MyDrawable();
    MyDrawable(const std::string texturefile, int x, int y, const std::string& name);
    MyDrawable(const MyDrawable& orig);
    
    virtual ~MyDrawable();
    
    const sf::Sprite& getSprite() const; 
    sf::Vector2u getPos() const;
    sf::Vector2u getDir() const;
    void setPos(int x, int y);
    const sf::Vector2u& getPos();
    void move(sf::Vector2u dir);
    
    std::string getName() const;
    
    void updateSpritePosition();
protected:
    sf::Vector2u dir = sf::Vector2u(1, 0);
    int spriteColumn = 0;
    int spriteRow = 0;
    int tickRate = 2;
    int tick = 0;
    std::string name;
    std::string texturefile;
    sf::Sprite sprite;
    sf::Vector2u position;
};

#endif /* MYDRAWABLE_H */

