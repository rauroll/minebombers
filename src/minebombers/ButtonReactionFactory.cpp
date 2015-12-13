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
#include <string>
#include <iostream>

#include "ButtonReactionFactory.h"
#include "ConfigManager.h"

ButtonReactionFactory::ButtonReactionFactory() {
}

ButtonReactionFactory::ButtonReactionFactory(const ButtonReactionFactory& orig) {
}

ButtonReactionFactory::~ButtonReactionFactory() {
}

std::map<sf::Keyboard::Key, ButtonReaction> ButtonReactionFactory::getPlayerButtons(uint8_t id) {
    std::map<sf::Keyboard::Key, ButtonReaction> buttons;
    ConfigManager& config = ConfigManager::getInstance();
    
    if (id == 0) {
        buttons[(sf::Keyboard::Key)(config.getInt("p1_up", sf::Keyboard::Up))] = MOVE_UP;
        buttons[(sf::Keyboard::Key)(config.getInt("p1_down", sf::Keyboard::Down))] = MOVE_DOWN;
        buttons[(sf::Keyboard::Key)(config.getInt("p1_left", sf::Keyboard::Left))] = MOVE_LEFT;
        buttons[(sf::Keyboard::Key)(config.getInt("p1_right", sf::Keyboard::Right))] = MOVE_RIGHT;
        
        buttons[(sf::Keyboard::Key)(config.getInt("p1_shoot", sf::Keyboard::RAlt))] = SHOOT;
        buttons[(sf::Keyboard::Key)(config.getInt("p1_change_weapon", sf::Keyboard::RShift))] = CHANGE_WEAPON;
    }
    else if (id == 1) {
        buttons[(sf::Keyboard::Key)(config.getInt("p2_up", sf::Keyboard::A))] = MOVE_UP;
        buttons[(sf::Keyboard::Key)(config.getInt("p2_down", sf::Keyboard::S))] = MOVE_DOWN;
        buttons[(sf::Keyboard::Key)(config.getInt("p2_left", sf::Keyboard::A))] = MOVE_LEFT;
        buttons[(sf::Keyboard::Key)(config.getInt("p2_right", sf::Keyboard::D))] = MOVE_RIGHT;
        
        buttons[(sf::Keyboard::Key)(config.getInt("p2_shoot", sf::Keyboard::LAlt))] = SHOOT;
        buttons[(sf::Keyboard::Key)(config.getInt("p2_change_weapon", sf::Keyboard::LShift))] = CHANGE_WEAPON;
    }
    else if (id > 1) {
        std::string pre = "p" + std::to_string(id + 1);
        
        buttons[(sf::Keyboard::Key)(config.getInt(pre + "_up", sf::Keyboard::Unknown))] = MOVE_UP;
        buttons[(sf::Keyboard::Key)(config.getInt(pre + "_down", sf::Keyboard::Unknown))] = MOVE_DOWN;
        buttons[(sf::Keyboard::Key)(config.getInt(pre + "_left", sf::Keyboard::Unknown))] = MOVE_LEFT;
        buttons[(sf::Keyboard::Key)(config.getInt(pre + "_right", sf::Keyboard::Unknown))] = MOVE_RIGHT;
        
        buttons[(sf::Keyboard::Key)(config.getInt(pre + "_shoot", sf::Keyboard::Unknown))] = SHOOT;
        buttons[(sf::Keyboard::Key)(config.getInt(pre + "_change_weapon", sf::Keyboard::Unknown))] = CHANGE_WEAPON;        
    }
    
    return buttons;
}


