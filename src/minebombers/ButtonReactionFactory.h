/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ButtonReactionFactory.h
 * Author: henrinurmi
 *
 * Created on December 12, 2015, 12:04 PM
 */

#ifndef BUTTONREACTIONFACTORY_H
#define BUTTONREACTIONFACTORY_H

#include <SFML/System.hpp>
#include <map>

#include "ButtonReaction.h"

class ButtonReactionFactory {
public:
    ButtonReactionFactory();
    ButtonReactionFactory(const ButtonReactionFactory& orig);
    virtual ~ButtonReactionFactory();
    
    std::map<sf::Keyboard::Key, ButtonReaction> getPlayerButtons(uint8_t id);
private:

};

#endif /* BUTTONREACTIONFACTORY_H */

