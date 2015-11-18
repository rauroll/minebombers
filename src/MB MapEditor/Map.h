/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Map.h
 * Author: henrinurmi
 *
 * Created on November 18, 2015, 6:49 PM
 */

#ifndef MAP_H
#define MAP_H

#include <vector>

#include <SFML/Graphics.hpp>

#include "Tile.h"
#include "Tileset.h"
#include "TileType.h"

namespace MBEditor {
    class Map : public sf::Drawable, public sf::Transformable {
    public:
        Map();
        Map(uint16_t width, uint16_t height);
        Map(const Map& orig);
        virtual ~Map();
        
        void setName(const std::string& name);
        void setTileset(MBEditor::Tileset& tileset);
        
        void setTileId(sf::Vector2u p, uint16_t id);
        void setTileLevel(sf::Vector2u p, uint16_t level);
        void setTileType(sf::Vector2u p, MBEditor::TileType type);
        
        void clearTiles();
        
        const MBEditor::Tileset& getTileset() const;
        const std::vector<std::vector<MBEditor::Tile> >& getTiles() const;
        const std::string& getName() const;
        
        const sf::Vector2u getSize() const;
    private:
        uint16_t width;
        uint16_t height;
        
        std::vector<std::vector<MBEditor::Tile> > tiles;

        std::string name;
        MBEditor::Tileset tileset;
        
        sf::VertexArray vertices;

        void draw(sf::RenderTarget& target, sf::RenderStates states) const;
        void updateVertex(const sf::Vector2u& p);
        void updateAllVertex();
    };
}
#endif /* MAP_H */

