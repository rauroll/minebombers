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
#include "Tileset.h"
#include "TileType.h"

class Map : public sf::Drawable, public sf::Transformable {
public:
    Map();
    Map(uint16_t width, uint16_t height);
    Map(const Map& orig);
    virtual ~Map();

    void setName(const std::string& name);
    void setTileset(Tileset& tileset);
    void setTile(sf::Vector2u pos, Tile& tile);
    void setTileLevel(sf::Vector2u pos, int level);
    bool floorAt(sf::Vector2u newPosition);
    bool wallAt(sf::Vector2u newPosition);
    bool isUnpassable(sf::Vector2u newPosition);
    void makeFloorAround(sf::Vector2u pos);

    void clearTiles();
    
    void setTileAsVisible(sf::Vector2u p);

    const Tileset& getTileset() const;
    const Tile& getTile(sf::Vector2u pos) const;
    const std::vector<std::vector<Tile> >& getTiles() const;
    void damageTile(sf::Vector2u pos, int damage);
    const std::string& getName() const;

    const sf::Vector2u getSize() const;
private:
    uint16_t width;
    uint16_t height;

    std::vector<std::vector<Tile> > tiles;

    std::string name;
    Tileset tileset;

    sf::VertexArray vertices;

    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    void updateVertex(const sf::Vector2u& p);
    void updateAllVertex();
};


#endif /* MAP_H */

