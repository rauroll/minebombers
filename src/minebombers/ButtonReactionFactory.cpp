/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ButtonReactionFactory.cpp
 * Author: henrinurmi
 * 
 * Created on December 12, 2015, 12:04 PM
 */

#include <SFML/Window/Keyboard.hpp>

#include "ButtonReactionFactory.h"

ButtonReactionFactory::ButtonReactionFactory() {
}

ButtonReactionFactory::ButtonReactionFactory(const ButtonReactionFactory& orig) {
}

ButtonReactionFactory::~ButtonReactionFactory() {
}

std::map<sf::Keyboard::Key, ButtonReaction> ButtonReactionFactory::getPlayerButtons(uint8_t id) {
    std::map<sf::Keyboard::Key, ButtonReaction> buttons;
    
    if (id == 0) {
        buttons[sf::Keyboard::Up] = MOVE_UP;
        buttons[sf::Keyboard::Down] = MOVE_DOWN;
        buttons[sf::Keyboard::Left] = MOVE_LEFT;
        buttons[sf::Keyboard::Right] = MOVE_RIGHT;
        
        buttons[sf::Keyboard::RAlt] = SHOOT;
        buttons[sf::Keyboard::RShift] = CHANGE_WEAPON;
    }
    else if (id == 1) {
        buttons[sf::Keyboard::W] = MOVE_UP;
        buttons[sf::Keyboard::S] = MOVE_DOWN;
        buttons[sf::Keyboard::A] = MOVE_LEFT;
        buttons[sf::Keyboard::D] = MOVE_RIGHT;
        
        buttons[sf::Keyboard::LAlt] = SHOOT;
        buttons[sf::Keyboard::LShift] = CHANGE_WEAPON;
    }
    
    return buttons;
}


