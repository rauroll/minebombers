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
#include <math.h>

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
    uint16_t w = 80;
    uint16_t h = 40;
    float floorRatio = 0.05; // how much floor relative to total amount of tiles
    float wallRatio = 0.05 + (rand() % 2 / 100.0); // how much wall relative to total amount of tiles
    float softRatio = 0.5; // how much soft wall relative to total wall
    float wallSizeRatio = 0.1; // how long walls are relative to (w + h) / 2
    
    Map map = Map(w, h);
    Tileset tileset(sf::Vector2u(16, 16));
    tileset.load("map_spritesheet.png");
    map.setTileset(tileset);
        
    // fill with rock
    for (int x = 0; x < w; x++)
        for(int y = 0; y < h; y++) {
            bool isSoft = rand() % 100 < softRatio * 100;
            Tile tile = Tile(isSoft ? 2 : 5, isSoft ? 20 : 30, ROCK);
            sf::Vector2u pos(x, y);
            map.setTile(pos, tile);
        }
            
    // fill floor
    int floor = 0;
    while (floor++ <= w * h * floorRatio ) {
        Tile tile = Tile(0, 0, FLOOR);
        sf::Vector2u pos(rand() % w, rand() % h);
        map.setTile(pos, tile);
    }
    
    // fill wall
    int walls = 0;
    while (walls++ <= w * h * wallRatio) {
        Tile tile = Tile(0, 10, WALL);
        sf::Vector2u pos(rand() % w, rand() % h);
        map.setTile(pos, tile);
        
        int size = rand() % ((w + h) / 2) * wallSizeRatio;
        bool direction = rand() % 2 == 0;
        for (int i = 0; i < size; ++i) {
            Tile tile(0, 10, WALL);
            sf::Vector2u p = direction ? sf::Vector2u(pos.x, pos.y + i) : sf::Vector2u(pos.x + i, pos.y);
            map.setTile(sf::Vector2u(fmin(w - 1, p.x), fmin(h - 1, p.y)), tile);
        }
    }
    
    // edges
    for (int x = 0; x < w; x++) {
        Tile tile = Tile(0, 10, WALL);
        map.setTile(sf::Vector2u(x, 0), tile); 
        map.setTile(sf::Vector2u(x, h - 1), tile); 
    }
    
    for (int y = 0; y < h; y++) {
        Tile tile = Tile(0, 10, WALL);
        map.setTile(sf::Vector2u(0, y), tile); 
        map.setTile(sf::Vector2u(w - 1, y), tile); 
    }
        

    std::cout << "end generate" << std::endl;
    return map;
}


