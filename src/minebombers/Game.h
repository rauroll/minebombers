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
    const Player& getPlayer() const;
    Map& getMap();

private:
    Scene* currentScene;
    Map map;
    Player player;
    
    std::vector<Treasure> treasures;
    
    bool isEmpty(sf::Vector2u pos);
    bool addTreasure(Treasure& treasure);
};

#endif /* GAME_H */

