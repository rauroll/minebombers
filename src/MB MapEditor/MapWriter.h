/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MapWriter.h
 * Author: henrinurmi
 *
 * Created on November 18, 2015, 6:59 PM
 */

#ifndef MAPWRITER_H
#define MAPWRITER_H

#include <string>

#include "Map.h"

namespace MBEditor {
    class MapWriter {
    public:
        MapWriter();
        MapWriter(const MapWriter& orig);
        virtual ~MapWriter();
        
        void saveToFile(MBEditor::Map& map, const std::string& filename);
    private:
        void writeWord(uint16_t value, std::fstream& file);
        void writeString(const std::string& str, std::fstream& file);
    };
}
#endif /* MAPWRITER_H */

