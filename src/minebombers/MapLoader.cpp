/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MapLoader.cpp
 * Author: henrinurmi
 * 
 * Created on November 18, 2015, 5:34 PM
 */

#include "MapLoader.h"
#include "Tile.h"
#include "Tileset.h"
#include <iostream>

MapLoader::MapLoader() {
}

MapLoader::MapLoader(const MapLoader& orig) {
}

MapLoader::~MapLoader() {
}

Map MapLoader::fromFile(const std::string& path) {
    std::fstream file;
    file.open(path, std::ios::in | std::ios::binary);
    
    Map map;
    
    if(file.is_open()) {
        uint16_t magic;
        file.read((char*) &magic, 2);

        if(magic == 0x424d) {
            std::cout << "Correct magicnumber" << std::endl;
            
            std::string name = readString(file);
            std::cout << "Map name: " << name << std::endl;
            
            std::string tilesetFile = readString(file);
            std::cout << "Tileset: " << tilesetFile << std::endl;
            
            uint16_t mapWidth, mapHeight;
            file.read((char*) &mapWidth, 2);
            file.read((char*) &mapHeight, 2);
            
            std::cout << "Map width: " << mapWidth << std::endl << "Map height: " << mapHeight << std::endl;
            
            uint16_t tileWidth, tileHeight;
            file.read((char*) &tileWidth, 2);
            file.read((char*) &tileHeight, 2);
           
            std::cout << "Tile width: " << std::to_string(tileWidth) << std::endl << "Tile height: " << std::to_string(tileHeight) << std::endl;
            
            map = Map(mapWidth, mapHeight);
            Tileset tileset(sf::Vector2u(tileWidth, tileHeight));
            
            tileset.load(tilesetFile);
            
            map.setTileset(tileset);
            
            for(auto y = 0; y < mapHeight; y++) {
                for(auto x = 0; x < mapWidth; x++) {
                    uint16_t tileId, level, type;
                    
                    file.read((char*) &tileId, 2);
                    file.read((char*) &level, 2);
                    file.read((char*) &type, 2);
                    
                    Tile tile = Tile(level, tileId);
                    
                    sf::Vector2u pos(x, y);
                    map.setTile(pos, tile);
                }
            }
        }
        else {
            std::cout << "Incorrect magicnumber" << std::endl;
        }

        file.close();
    }
    else {
        std::cout << "Error: file not found" << std::endl;
    }
    
    //map = Map(100, 100, "assets/tileset.png", sf::Vector2u(16, 16));
    return map;
}

std::string MapLoader::readString(std::fstream& file) {
    uint16_t length;
    file.read((char*) &length, 2);

    std::cout << "String length: " << length << std::endl;
    
    char* buf = new char[length + 1];
    file.read(buf, length);
    buf[length] = 0;
    std::string str = std::string(buf);    
    delete[] buf;
    
    return str;
}
