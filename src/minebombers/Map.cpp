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
#include "TextureManager.h"
#include <iostream>

Map::Map() {
    
}

Map::Map(uint16_t w, uint16_t h, const std::string& tileset, sf::Vector2u tileSize) {
    width = w;
    height = h;
    this->tileSize = tileSize;
    
    initMap();
    
    TextureManager manager = TextureManager::getInstance();
    this->tileset = manager.load(tileset);
}


Map::Map(const Map& orig) {
    width = orig.width;
    height = orig.height;
    tileSize = orig.tileSize;

    initMap();
    tileset = orig.tileset;
    
    for(auto x = 0; x < width; x++) {
        for(auto y = 0; y < height; y++) {
            Tile tile = orig.getTile(x, y);
            setTile(x, y, tile);
        }
    }
}

Map::~Map() {
}

void Map::initMap() {
    for(auto x = 0; x < width; x++) {
        std::vector<Tile> row;
        for(auto y = 0; y < height; y++) {
            row.push_back(Tile(0, 0));
        }
        tiles.push_back(row);
    }
    
    vertices.setPrimitiveType(sf::Quads);
    vertices.resize(width * height * 4);
}


void Map::setTile(uint16_t x, uint16_t y, Tile& tile) {
    if(x >= 0 && x < width && y >= 0 && y < height) {
        tiles[x][y] = tile;

        sf::Vertex* quad = &vertices[(y + x * width) * 4];
        
        int tileNumber = tile.getId();
        int tX = tileNumber % (tileset.getSize().x / tileSize.x);
        int tY = tileNumber / (tileset.getSize().x / tileSize.x);

        quad[0].position = sf::Vector2f(x * tileSize.x, y * tileSize.y);
        quad[1].position = sf::Vector2f((x + 1) * tileSize.x, y * tileSize.y);
        quad[2].position = sf::Vector2f((x + 1) * tileSize.x, (y + 1) * tileSize.y);
        quad[3].position = sf::Vector2f(x * tileSize.x, (y + 1) * tileSize.y);

        quad[0].texCoords = sf::Vector2f(tX * tileSize.x, tY * tileSize.y);
        quad[1].texCoords = sf::Vector2f((tX + 1) * tileSize.x, tY * tileSize.y);
        quad[2].texCoords = sf::Vector2f((tX + 1) * tileSize.x, (tY + 1) * tileSize.y);
        quad[3].texCoords = sf::Vector2f(tX * tileSize.x, (tY + 1) * tileSize.y);
    }
}

Tile Map::getTile(uint16_t x, uint16_t y) const {
    return tiles[x][y];
}

void Map::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    states.transform *= getTransform();
    states.texture = &tileset;
    target.draw(vertices, states);
}

uint16_t Map::getHeight() const {
    return height;
}

uint16_t Map::getWidth() const {
    return width;
}

