/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Player.h
 * Author: Jere
 *
 * Created on 24. marraskuuta 2015, 14:34
 */

#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include "Entity.h"

class Player: public Entity {
public:
    Player(): Entity() {};
    Player(sf::Sprite sp, int x, int y, const std::string& name): Entity(sp, x, y, 100, name) {};
    Player(const Player& orig);
    virtual ~Player();
private:

};

#endif /* PLAYER_H */

