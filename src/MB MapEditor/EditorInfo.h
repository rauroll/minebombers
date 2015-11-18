/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   EditorInfo.h
 * Author: henrinurmi
 *
 * Created on November 18, 2015, 9:36 PM
 */

#ifndef EDITORINFO_H
#define EDITORINFO_H

#include <SFML/Graphics.hpp>

#include "TileType.h"
#include "Map.h"

namespace MBEditor {
    class EditorInfo : public sf::Drawable {
    public:
        EditorInfo(const MBEditor::Map& map);
        EditorInfo(const EditorInfo& orig);
        virtual ~EditorInfo();

        void update();
        
        void setCurretTile(uint16_t tile);
        void setCurrentLevel(uint16_t level);
        void setCurrentType(MBEditor::TileType type);
    private:
        const MBEditor::Map& map;

        sf::Font font;
        sf::Text text;
        sf::VertexArray quad;

        uint16_t currentTile;
        uint16_t currentLevel;
        MBEditor::TileType currentType;

        void draw(sf::RenderTarget& target, sf::RenderStates states) const;
        const std::string typeToString(const MBEditor::TileType& type) const;
    };
}
#endif /* EDITORINFO_H */

