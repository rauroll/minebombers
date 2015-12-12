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

#include <iostream>
#include <list>

#include "MapGenerator.h"
#include "ResourceManager.h"
#include "TileType.h"

MapGenerator::MapGenerator() {
}

MapGenerator::MapGenerator(const MapGenerator& orig) {
}

MapGenerator::~MapGenerator() {
}

Map MapGenerator::generate() {
    uint16_t w = 40;
    uint16_t h = 20;
    float floorRatio = 0.4 + (rand() % 20 / 100.0);
    float wallRatio = 0.05 + (rand() % 5 / 100.0);
    float softRatio = 0.5;
    
    Map map = Map(w, h);
    Tileset tileset(sf::Vector2u(16, 16));
    tileset.load("map_spritesheet.png");
    map.setTileset(tileset);
        
    // fill with rock
    for (int x = 0; x < w; x++)
        for(int y = 0; y < h; y++) {
            bool isSoft = rand() % 100 < softRatio * 100;
            Tile tile = Tile(5, isSoft ? 20 : 30, ROCK);
            sf::Vector2u pos(x, y);
            map.setTile(pos, tile);
        }
            
    // fill floor
    int floor = 0;
    while (floor++ < w * h * floorRatio) {
        Tile tile = Tile(0, 0, FLOOR);
        sf::Vector2u pos(rand() % w, rand() % h);
        map.setTile(pos, tile);
    }
    
    // fill wall
    int wall = 0;
    while (wall++ < w * h * wallRatio) {
        Tile tile = Tile(0, 10, WALL);
        sf::Vector2u pos(rand() % w, rand() % h);
        map.setTile(pos, tile);
    }

    std::cout << "end generate" << std::endl;
    return map;
}


