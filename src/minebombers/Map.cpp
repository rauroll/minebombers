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
#include "ResourceManager.h"
#include "TileType.h"
#include <iostream>

Map::Map() {
    Map(0, 0);
}

Map::Map(uint16_t width, uint16_t height) : width(width), height(height) {
    clearTiles();
}

Map::Map(const Map& orig) : width(orig.width), height(orig.height), name(orig.name) {
    clearTiles();

    for(auto x = 0; x < width; x++) {
        for(auto y = 0; y < height; y++) {
            tiles[x][y] = orig.tiles[x][y];
        }
    }
}

Map::~Map() {
}

void Map::clearTiles() {
    tiles.clear();

    for(auto x = 0; x < width; x++) {
        std::vector<Tile> column;

        for(auto y = 0; y < height; y++) {
            Tile empty(0, 0, FLOOR);

            /*if ((y == 0 || y == (height - 1)) || x == 0 || x == (width - 1))
                empty.type = WALL;*/

            column.push_back(empty);
        }

        tiles.push_back(column);
    }

    vertices.setPrimitiveType(sf::Quads);
    vertices.resize(width * height * 4);
}

void Map::setName(const std::string& name) {
    this->name = name;
}
void Map::setTileset(Tileset& tileset) {
    this->tileset = tileset;
    updateAllVertex();
}

bool Map::floorAt(sf::Vector2u newPosition) {
    if ((int) newPosition.x >= 0 && newPosition.x < getSize().x && (int) newPosition.y >= 0 && newPosition.y < getSize().y) {
        const Tile& tile = this->getTile(newPosition);
        TileType tileType = tile.getType();
        return newPosition.x > 0 && newPosition.y > 0
               && newPosition.x <= width && newPosition.y <= height
               && (tileType == FLOOR || (tileType == ROCK && tile.getLevel() <= 0));
    } else return false;
}

void Map::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    states.transform *= getTransform();
    states.texture = &tileset.getTexture();
    target.draw(vertices, states);        
}

void Map::updateVertex(const sf::Vector2u& p) {
    Tile tile = tiles[p.x][p.y];
    if (tile.isVisible() || true) {
        int tileNumber = tile.getId();
        int healthPerLevel = tile.getStartLevel()/5;
            
        if(tile.getType() == ROCK) {
            tileNumber += 5 - tile.getLevel()/healthPerLevel;
        }

        int tu = tileNumber % (tileset.width() / tileset.tileWidth());
        int tv = tileNumber / (tileset.width() / tileset.tileWidth());

        // get a pointer to the current tile's quad
        sf::Vertex* quad = &vertices[(p.x + p.y * width) * 4];

        // define its 4 corners
        quad[0].position = sf::Vector2f(p.x * tileset.tileWidth(), p.y * tileset.tileHeight());
        quad[1].position = sf::Vector2f((p.x + 1) * tileset.tileWidth(), p.y * tileset.tileHeight());
        quad[2].position = sf::Vector2f((p.x + 1) * tileset.tileWidth(), (p.y + 1) * tileset.tileHeight());
        quad[3].position = sf::Vector2f(p.x * tileset.tileWidth(), (p.y + 1) * tileset.tileHeight());

        // define its 4 texture coordinates
        quad[0].texCoords = sf::Vector2f(tu * tileset.tileWidth(), tv * tileset.tileHeight());
        quad[1].texCoords = sf::Vector2f((tu + 1) * tileset.tileWidth(), tv * tileset.tileHeight());
        quad[2].texCoords = sf::Vector2f((tu + 1) * tileset.tileWidth(), (tv + 1) * tileset.tileHeight());
        quad[3].texCoords = sf::Vector2f(tu * tileset.tileWidth(), (tv + 1) * tileset.tileHeight());
        
    }
}

void Map::updateAllVertex() {
    for(auto x = 0; x < width; x++) {
        for(auto y = 0; y < height; y++) {
            updateVertex(sf::Vector2u(x, y));
        }
    }       
}

void Map::setTile(sf::Vector2u pos, Tile& tile) {
    tiles[pos.x][pos.y] = tile;
    updateVertex(pos);
}

void Map::setTileAsVisible(sf::Vector2u p) {
    int radius = 5;
    for (int x = 0; x < radius*2; x++) {
        for (int y = 0; y < radius*2; y++) {
        sf::Vector2f v(p.x + x - radius, p.y + y - radius);
            if (v.x >= 0 && v.x < getSize().x && v.y >= 0 && v.y < getSize().y) {
                if(((float)v.x - p.x)*((float)v.x - p.x) + ((float)v.y - p.y)*((float)v.y - p.y) + 0.5 <= radius*radius) {
                    tiles[v.x][v.y].setVisible();
                    this->updateVertex(sf::Vector2u(v.x, v.y));
                }
            }
        }
    }
}

void Map::setTileLevel(sf::Vector2u pos, int level) {
    tiles[pos.x][pos.y].setLevel(level);
}

const Tileset& Map::getTileset() const {
    return tileset;
}

const std::vector<std::vector<Tile> >& Map::getTiles() const {
    return tiles;
}

const std::string& Map::getName() const {
    return name;
}

const sf::Vector2u Map::getSize() const {
    return sf::Vector2u(width, height);
}

const Tile& Map::getTile(sf::Vector2u pos) const {
    return tiles[pos.x][pos.y];
}

void Map::damageTile(sf::Vector2u pos) {
    tiles[pos.x][pos.y].reduceLevel();
    updateVertex(pos);
}
