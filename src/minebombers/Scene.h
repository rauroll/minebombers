/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Scene.h
 * Author: Max
 *
 * Created on November 17, 2015, 2:22 PM
 */

#ifndef SCENE_H
#define SCENE_H

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

class Scene {
public:
    Scene();
    Scene(const Scene& orig);
    virtual ~Scene();
    virtual void update(sf::RenderWindow& window) = 0;
    virtual void onEvent(sf::Event& event) = 0;
private:

};

#endif /* SCENE_H */

