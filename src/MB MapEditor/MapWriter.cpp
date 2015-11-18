/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MapWriter.cpp
 * Author: henrinurmi
 * 
 * Created on November 18, 2015, 6:59 PM
 */

#include <fstream>
#include <vector>

#include "MapWriter.h"

namespace MBEditor {
    MapWriter::MapWriter() {
    }

    MapWriter::MapWriter(const MapWriter& orig) {
    }

    MapWriter::~MapWriter() {
    }

    void MapWriter::saveToFile(MBEditor::Map& map, const std::string& filename) {
        std::fstream file;
        file.open(filename, std::ios::out | std::ios::trunc | std::ios::binary);
        
        if(file.is_open()) {
            //Magic number
            writeWord(0x424d, file);
            
            //Map and tileset names
            writeString(map.getName(), file);
            writeString(map.getTileset().getName(), file);
            
            //Map size
            sf::Vector2u mapSize = map.getSize();
            writeWord(mapSize.x, file);
            writeWord(mapSize.y, file);
            
            //Tilesize
            writeWord(map.getTileset().tileWidth(), file);
            writeWord(map.getTileset().tileHeight(), file);
            
            auto tiles = map.getTiles();
            
            for(auto y = 0; y < mapSize.y; y++) {
                for(auto x = 0; x < mapSize.x; x++) {
                    auto tile = tiles[x][y];
                    writeWord(tile.id, file);
                    writeWord(tile.level, file);
                    writeWord(tile.type, file);
                }
            }
            
            file.close();
        }
    }

    void MapWriter::writeWord(uint16_t value, std::fstream& file) {
        file.write((char*) &value, 2);
    }

    void MapWriter::writeString(const std::string& str, std::fstream& file) {
        writeWord(str.size(), file);
        file.write(str.c_str(), str.size());
    }
}

