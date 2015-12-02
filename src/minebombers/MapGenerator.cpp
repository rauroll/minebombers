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
#include "TileType.h"
#include <iostream>

MapGenerator::MapGenerator() {
}

MapGenerator::MapGenerator(const MapGenerator& orig) {
}

MapGenerator::~MapGenerator() {
}

Map MapGenerator::generate() {
    uint16_t w = 40;
    uint16_t h = 20;
    Map map = Map(w, h);
    Tileset tileset(sf::Vector2u(16, 16));
    tileset.load("tileset.png");
    map.setTileset(tileset);
    
    std::cout << "start generate" << std::endl;
    for(int i = 0; i < w; i++ ) {
        for(int j = 0; j < h; j++ ) {
            Tile tile = Tile(40, (j + i) % 10, FLOOR);
            sf::Vector2u pos(i, j);
            map.setTile(pos, tile);
        }
    }
    std::cout << "end generate" << std::endl;
    return map;
}


