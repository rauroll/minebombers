/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MapGenerator.h
 * Author: henrinurmi
 *
 * Created on November 17, 2015, 7:00 PM
 */

#ifndef MAPGENERATOR_H
#define MAPGENERATOR_H

#include "Map.h"

class MapGenerator {
public:
    MapGenerator();
    MapGenerator(const MapGenerator& orig);
    virtual ~MapGenerator();
    
    Map generate();
private:

};

#endif /* MAPGENERATOR_H */

