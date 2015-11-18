/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Map.h
 * Author: Jere
 *
 * Created on 17. marraskuuta 2015, 17:53
 */

#ifndef MAP_H
#define MAP_H

#include <SFML/Graphics.hpp>

#include "Tile.h"
#include "Treasure.h"

class Map : public sf::Drawable, public sf::Transformable {
public:
    Map();
    Map(uint16_t w, uint16_t h, const std::string& tileset, sf::Vector2u tileSize);
    Map(const Map& orig);
    virtual ~Map();
    
    void setTile(uint16_t x, uint16_t y, Tile& tile);
    Tile getTile(uint16_t x, uint16_t y) const;
    
    uint16_t getWidth() const;
    uint16_t getHeight() const;
private:    
    uint16_t width;
    uint16_t height;
    
    std::vector<std::vector<Tile> > tiles;
    sf::Texture tileset;
    sf::Vector2u tileSize;
    
    sf::VertexArray vertices;
    
    std::vector<Treasure*> treasures;
    
    void initMap();
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif /* MAP_H */

