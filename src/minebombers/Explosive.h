/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Explosive.h
 * Author: Olli
 *
 * Created on December 2, 2015, 2:22 PM
 */

#ifndef EXPLOSIVE_H
#define EXPLOSIVE_H

#include <SFML/Graphics.hpp>

class Explosive {
public:
    Explosive(sf::Sprite sprite);
    Explosive(const Explosive& orig);
    virtual ~Explosive();
    
    void use(sf::Vector2u loc);
private:
    
    sf::Sprite sprite;

};

#endif /* EXPLOSIVE_H */

