/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Editor.h
 * Author: henrinurmi
 *
 * Created on November 18, 2015, 8:08 PM
 */

#ifndef EDITOR_H
#define EDITOR_H

#include "Map.h"
#include "TileType.h"
#include "EditorInfo.h"

namespace MBEditor {
    class Editor : public sf::Drawable, public sf::Transformable {
    public:
        Editor(MBEditor::Map& map);
        Editor(const Editor& orig);
        virtual ~Editor();
        
        void changeTile(uint16_t tile);
        void nextTile();
        void prevTile();
        void moveCursor(sf::Vector2u d);
        void setType(MBEditor::TileType type);
        
        void insert();
        
        uint16_t getCurrentLevel() const;
        uint16_t getCurrentTile() const;
        MBEditor::TileType getCurrentType() const;
        
    private:
        MBEditor::Map& map;
        
        uint16_t currentTile;
        uint16_t currentLevel;
        MBEditor::TileType currentType;
        
        sf::Vector2u cursor;
        sf::RectangleShape cursorShape;
        
        MBEditor::EditorInfo info;
        
        void draw(sf::RenderTarget& target, sf::RenderStates states) const;
        void createCursor();
        void updateCursorShapePosition();
    };
}
#endif /* EDITOR_H */

