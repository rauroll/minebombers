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

#include <SFML/System.hpp>
#include <vector>

#include "Scene.h"
#include "Map.h"
#include "Player.h"
#include "Treasure.h"
#include "Projectile.h"
#include "Effect.h"
#include "MapGenerator.h"
#include "MapLoader.h"


enum SceneType { GAMESCENE, MENUSCENE, SHOPSCENE };

class Game {
public:
    Game();
    virtual ~Game();
    void setScene(SceneType scene);    
    Scene* getScene();
    Map& getMap();
    std::vector<Player>& getPlayers();
    std::vector<Player> getPlayersSortedByScore();
    
    void initGame();

    void clearTreasures();
    void setRandomTreasures(uint16_t amount);
    std::vector<Treasure>& getTreasures();
    
    bool isEntityAtPos(sf::Vector2u pos);
    
    void addPlayer(const std::string& name, const std::string textureName);
    void movePlayer(uint8_t player, sf::Vector2u d);
    void turnPlayer(uint8_t player, sf::Vector2u d);
    sf::Vector2u getRandomEmptyPos();
    void addProjectile(Projectile projectile);
    std::vector<Projectile>& getProjectiles();
    void onPlayerDead(std::string killed, std::string killer);
    
    void addEffect(Effect effect);
    
    bool toggleSound();
    bool soundEnabled();
    
    std::vector<Effect>& getEffects();
    
    sf::Vector2u getCanvasSize();
    
    void update(sf::Time dt);
    
    static Game& getInstance() {
        static Game instance;
        return instance;
    }
    
    int getRound();
    int getTotalRounds();
    
    bool roundHasEnded();
    
    sf::Time getRoundRemainingTime() const;
    
    sf::Image& getOverlayImage();
    void revealMapAt(sf::Vector2u pos, int radius = 150);
    
    void startRound();
    void endRound(bool switchToShop = false);
    
    void useRandomMap();
    void useMap(const std::string& name);
private:
    sf::Vector2u getNewPlayerPosition();
    sf::Image overlayImage;
    
    Scene* currentScene;
    Map map;
    
    MapLoader loader;
    MapGenerator gen;
    
    std::vector<Player> players;
    std::vector<Treasure> treasures;
    std::vector<Projectile> projectiles;
    std::vector<Effect> effects;
    
    std::map<SceneType, Scene*> scenes;
    
    bool isEmpty(sf::Vector2u pos);
    bool addTreasure(Treasure& treasure);
    bool lastManStanding();
      
    int round;
    int totalRounds;
    bool sound = true;
    
    sf::Clock roundClock;
    sf::Time roundTime;
    
    bool roundEnded = false;
    sf::Clock roundEndClock;
    int roundEndClocktime;
    
    std::vector<sf::Vector2u> startPositions;
    
    bool useMapGenerator;
    std::string mapName;
    
    int startMoney;
    int treasureCount;
};

#endif /* GAME_H */

