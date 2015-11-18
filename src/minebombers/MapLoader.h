/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MapLoader.h
 * Author: henrinurmi
 *
 * Created on November 18, 2015, 5:34 PM
 */

#ifndef MAPLOADER_H
#define MAPLOADER_H

#include <fstream>

#include "Map.h"

class MapLoader {
public:
    MapLoader();
    MapLoader(const MapLoader& orig);
    virtual ~MapLoader();
    
    Map fromFile(const std::string& path);
private:
    std::string readString(std::fstream& file);
};

#endif /* MAPLOADER_H */

