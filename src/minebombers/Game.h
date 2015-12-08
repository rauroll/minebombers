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
#include "Projectile.h"

class Game {
public:
    Game();
    virtual ~Game();
    void setScene(std::string scene);    
    Scene* getScene();
    Map& getMap();
    std::vector<Player>& getPlayers();

    void clearTreasures();
    void setRandomTreasures(uint16_t amount);
    std::vector<Treasure>& getTreasures();
    
    bool isEntityAtPos(sf::Vector2u pos);
    
    void addPlayer(const std::string& name);
    void movePlayer(uint8_t player, sf::Vector2u d);
    sf::Vector2u getRandomEmptyPos();
    void addProjectile(Projectile projectile);
    std::vector<Projectile>& getProjectiles();
    
    static Game& game() {
        static Game instance;
        return instance;
    }
private:
    Scene* currentScene;
    Map map;
    
    std::vector<Player> players;
    std::vector<Treasure> treasures;
    std::vector<Projectile> projectiles;
    
    std::map<std::string, Scene*> scenes;
    
    bool isEmpty(sf::Vector2u pos);
    bool addTreasure(Treasure& treasure);
};

#endif /* GAME_H */

