/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Tile.h
 * Author: henrinurmi
 *
 * Created on November 17, 2015, 5:53 PM
 */

#ifndef TILE_H
#define TILE_H

#include <SFML/Graphics.hpp>

#include "TileType.h"

class Tile {
public:
    Tile(int level, int id, TileType type);
    Tile(const Tile& orig);
    virtual ~Tile();
    
    int getId() const;
    int getLevel() const;
    
    void setId(int id);
    void setLevel(int level);
    
    void setVisible();
    bool isVisible();
    
    TileType getType() const;
private:
    bool visible;;
    int level;
    int id;
    TileType type;
};

#endif /* TILE_H */

