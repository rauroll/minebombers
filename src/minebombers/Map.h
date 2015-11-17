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

#include "Tile.h"
#include "Treasure.h"

class Map {
public:
    Map(int w, int h);
    Map(const Map& orig);
    virtual ~Map();
private:
    int width;
    int height;
    std::vector< std::vector<Tile*> > tiles;
    std::vector<Treasure*> treasures;
};

#endif /* MAP_H */

