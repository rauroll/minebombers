/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Tile.h
 * Author: henrinurmi
 *
 * Created on November 18, 2015, 7:03 PM
 */

#ifndef TILE_H
#define TILE_H

#include "TileType.h"

namespace MBEditor {
    typedef struct {
        uint16_t id;
        uint16_t level;
        MBEditor::TileType type;
    } Tile;
}

#endif /* TILE_H */

