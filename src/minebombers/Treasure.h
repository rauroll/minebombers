/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Treasure.h
 * Author: Jere
 *
 * Created on 17. marraskuuta 2015, 17:59
 */

#ifndef TREASURE_H
#define TREASURE_H

#include <SFML/Graphics.hpp>

class Treasure {
public:
    Treasure(sf::Sprite& sprite, uint32_t score, uint32_t value, sf::Vector2u pos);
    Treasure(const Treasure& orig);
    virtual ~Treasure();
    
    uint32_t getValue() const;
    uint32_t getScore() const;
    sf::Vector2u getPosition() const;
    sf::Sprite& getSprite();
private:
    sf::Sprite sprite;
    uint32_t value;
    uint32_t score;
    sf::Vector2u position;
};

#endif /* TREASURE_H */

