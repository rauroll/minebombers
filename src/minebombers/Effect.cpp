/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Effect.cpp
 * Author: Olli
 * 
 * Created on December 9, 2015, 7:57 PM
 */

#include "Effect.h"

Effect::Effect(std::string name, const std::string& texturefile, sf::Vector2u loc, bool permanent) : MyDrawable(texturefile, loc.x, loc.y, name) {
    this->permanent = permanent;
}

Effect::Effect() {
    
}

Effect::Effect(const Effect& orig) : MyDrawable(orig) {
    this->permanent = orig.permanent;
}

Effect::~Effect() {
    
}

Effect::isPermanent() {
    return !this->permanent;
}

Effect::update() {
    return this->spriteHasEnded();
}
