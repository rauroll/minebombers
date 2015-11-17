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

#include "Scene.h"

class Game {
public:
    Game();
    Game(const Game& orig);
    virtual ~Game();
    void setScene(Scene* scene);    
    Scene* getScene();
private:
    Scene* currentScene;
};

#endif /* GAME_H */

