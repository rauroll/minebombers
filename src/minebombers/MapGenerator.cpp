/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MapGenerator.cpp
 * Author: henrinurmi
 * 
 * Created on November 17, 2015, 7:00 PM
 */

#include "MapGenerator.h"
#include "TextureManager.h"
#include <iostream>

MapGenerator::MapGenerator() {
}

MapGenerator::MapGenerator(const MapGenerator& orig) {
}

MapGenerator::~MapGenerator() {
}

Map MapGenerator::generate() {
    Map map = Map(20, 20);
    TextureManager manager = TextureManager::getInstance();
    std::cout << "start generate" << std::endl;
    for(int i = 0; i < 20; i++ ) {
        for(int j = 0; j < 20; j++ ) {
            sf::Texture texture = manager.load("assets/mq1.jpg");
            //std::cout << "set tile" << std::endl;
            Tile tile = Tile(40, texture);
            map.setTile(i, j, tile);
        }
    }
    std::cout << "end generate" << std::endl;
    return map;
}


