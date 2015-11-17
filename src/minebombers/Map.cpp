/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Map.cpp
 * Author: Jere
 * 
 * Created on 17. marraskuuta 2015, 17:53
 */

#include "Map.h"
#include <iostream>

Map::Map() {
    
}

Map::Map(int w, int h) {
    width = w;
    height = h;

    for(int x = 0; x < width; x++) {
        std::vector<Tile> row;
        for(int y = 0; y < height; y++) {
            sf::Texture texture = sf::Texture();
            row.push_back(Tile(0, texture));
        }
        tiles.push_back(row);
    } 
}

Map::Map(const Map& orig) {
    width = orig.width;
    height = orig.height;
    
    tiles.clear();
    for(int x = 0; x < width; x++) {
        std::vector<Tile> row;
        for(int y = 0; y < height; y++) {
            sf::Texture texture = sf::Texture();
            row.push_back(Tile(0, texture));
        }
        tiles.push_back(row);
    } 
    
    for(int x = 0; x < width; x++) {
        for(int y = 0; y < height; y++) {
            Tile tile = orig.getTile(x, y);
            setTile(x, y, tile);
        }
    }
}

Map::~Map() {
}

void Map::setTile(int x, int y, Tile& tile) {
    if(x >= 0 && x < width && y >= 0 && y < height) {
        //std::cout << tiles[0].size() << std::endl;
        tiles[x][y] = tile;
    }
}

Tile Map::getTile(int x, int y) const {
    return tiles[x][y];
}