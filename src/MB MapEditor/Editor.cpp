/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Editor.cpp
 * Author: henrinurmi
 * 
 * Created on November 18, 2015, 8:08 PM
 */

#include "Editor.h"

namespace MBEditor {
    Editor::Editor(MBEditor::Map& map) : map(map), info(map) {
        currentTile = 0;
        currentLevel = 255;
        currentType = WALL;
        
        info.setCurrentLevel(currentLevel);
        info.setCurrentType(currentType);
        info.setCurretTile(currentTile);
        
        cursor = sf::Vector2u(0, 0);
        createCursor();
        info.update();
    }

    Editor::Editor(const Editor& orig) : map(orig.map), info(map) {
        currentLevel = orig.currentLevel;
        currentType = orig.currentType;
        currentTile = orig.currentTile;
        
        info.setCurrentLevel(currentLevel);
        info.setCurrentType(currentType);
        info.setCurretTile(currentTile);
        
        cursor = orig.cursor;
        createCursor();
        info.update();
    }

    Editor::~Editor() {
    }
    
    void Editor::changeTile(uint16_t tile) {
        currentTile = tile;
    }
    
    void Editor::nextTile() {
        currentTile = currentTile + 1 % map.getTileset().count();
        info.setCurretTile(currentTile);
    }

    void Editor::moveCursor(sf::Vector2u d) {
        cursor += d;
        updateCursorShapePosition();
    }
    
    void Editor::insert() {
        map.setTileId(cursor, currentTile);
        map.setTileLevel(cursor, currentLevel);
        map.setTileType(cursor, currentType);
    }

    void Editor::draw(sf::RenderTarget& target, sf::RenderStates states) const {
        target.draw(cursorShape);
        target.draw(info);
    }

    void Editor::createCursor() {
        cursorShape = sf::RectangleShape(sf::Vector2f(map.getTileset().tileWidth() -  2, map.getTileset().tileHeight() - 2));
        
        cursorShape.setOutlineThickness(1);
        cursorShape.setOutlineColor(sf::Color::Red);
        cursorShape.setFillColor(sf::Color::Transparent);
        
        updateCursorShapePosition();
    }

    void Editor::updateCursorShapePosition() {
        sf::Vector2u tileSize = map.getTileset().getTileSize();
        sf::Vector2u pos = sf::Vector2u(cursor.x * tileSize.x + 1, cursor.y * tileSize.y + 1);
        cursorShape.setPosition(pos.x, pos.y);
    }

    uint16_t Editor::getCurrentLevel() const {
        return currentLevel;
    }

    uint16_t Editor::getCurrentTile() const {
        return currentTile;
    }

    MBEditor::TileType Editor::getCurrentType() const {
        return currentType;
    }
    void Editor::setType(MBEditor::TileType type) {
        currentType = type;
        info.setCurrentType(type);
    }

    void Editor::prevTile() {
        currentTile = currentTile - 1 % map.getTileset().count();
        info.setCurretTile(currentTile);
    }
}

