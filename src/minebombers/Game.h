/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Game.h
 * Author: Max
 *
 * Created on November 17, 2015, 2:21 PM
 */

#ifndef GAME_H
#define GAME_H

#include <vector>

#include "Scene.h"
#include "Map.h"
#include "Player.h"
#include "Treasure.h"

class Game {
public:
    Game();
    virtual ~Game();
    void setScene(Scene* scene);    
    Scene* getScene();
    Map& getMap();
    std::vector<Player>& getPlayers();

    void clearTreasures();
    void setRandomTreasures(uint16_t amount);
    std::vector<Treasure>& getTreasures();
    
    void addPlayer(const std::string& name);
    void movePlayer(uint8_t player, sf::Vector2u d);
private:
    Scene* currentScene;
    Map map;
    
    std::vector<Player> players;
    std::vector<Treasure> treasures;
    
    bool isEmpty(sf::Vector2u pos);
    bool addTreasure(Treasure& treasure);
};

#endif /* GAME_H */

