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

class Tile {
public:
    Tile(int level, sf::Texture& texture);
    Tile(const Tile& orig);
    virtual ~Tile();
private:
    int level;
    sf::Texture texture;
};

#endif /* TILE_H */

