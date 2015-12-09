/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Effect.h
 * Author: Olli
 *
 * Created on December 9, 2015, 7:57 PM
 */

#ifndef EFFECT_H
#define EFFECT_H

#include "MyDrawable.h"
#include <SFML/Graphics.hpp>

class Effect : public MyDrawable {
public:
    Effect();
    Effect(std::string name, const std::string& texturefile, sf::Vector2u loc, bool removeAfterDone = true);
    Effect(const Effect& orig);
    
    virtual ~Effect();
    
private:
    
    bool removeAfterDone;

};

#endif /* EFFECT_H */

