/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   EditorInfo.cpp
 * Author: henrinurmi
 * 
 * Created on November 18, 2015, 9:36 PM
 */

#include "EditorInfo.h"
#include "Tileset.h"
#include <iostream>

namespace MBEditor {
    EditorInfo::EditorInfo(const MBEditor::Map& map) : map(map) {
        font.loadFromFile("assets/Courier_Prime.ttf");
        quad.setPrimitiveType(sf::Quads);
        quad.resize(4);
    }

    EditorInfo::EditorInfo(const EditorInfo& orig) : map(orig.map) {
        font.loadFromFile("assets/Courier_Prime.ttf");
    }

    EditorInfo::~EditorInfo() {
    }

    void EditorInfo::update() {
        std::string str = "Current tile:\n\n";
        str += "Current level: " + std::to_string(currentLevel) + "\n";
        str += "Current type: " + typeToString(currentType) + "\n";
        
        text = sf::Text(str, font);
        text.setCharacterSize(12);
        text.setPosition(map.getSize().x * map.getTileset().tileWidth() + 10, 5);
        
        const MBEditor::Tileset& tileset = map.getTileset();
        int tu = currentTile % (tileset.width() / tileset.tileWidth());
        int tv = currentTile / (tileset.width() / tileset.tileWidth());

        // define its 4 corners
        sf::Vector2u pos(map.getSize().x * tileset.tileWidth() + 110, 5);
        quad[0].position = sf::Vector2f(pos.x, pos.y);
        quad[1].position = sf::Vector2f(pos.x + tileset.tileWidth(), pos.y);
        quad[2].position = sf::Vector2f(pos.x + tileset.tileWidth(), pos.y + tileset.tileHeight());
        quad[3].position = sf::Vector2f(pos.x, pos.y + tileset.tileHeight());

        // define its 4 texture coordinates
        quad[0].texCoords = sf::Vector2f(tu * tileset.tileWidth(), tv * tileset.tileHeight());
        quad[1].texCoords = sf::Vector2f((tu + 1) * tileset.tileWidth(), tv * tileset.tileHeight());
        quad[2].texCoords = sf::Vector2f((tu + 1) * tileset.tileWidth(), (tv + 1) * tileset.tileHeight());
        quad[3].texCoords = sf::Vector2f(tu * tileset.tileWidth(), (tv + 1) * tileset.tileHeight());
    }

    void EditorInfo::draw(sf::RenderTarget& target, sf::RenderStates states) const {
        target.draw(text);
        
        //states.transform *= getTransform();
        states.texture = &map.getTileset().getTexture();
        target.draw(quad, states);       
    }

    const std::string EditorInfo::typeToString(const MBEditor::TileType& type) const {
        switch(type) {
            case WALL:
                return "WALL";
            case FLOOR:
                return "FLOOR";
            default:
                return "UNKNOW";
        }
    }

    void EditorInfo::setCurrentLevel(uint16_t level) {
        currentLevel = level;
        update();
    }

    void EditorInfo::setCurrentType(MBEditor::TileType type) {
        currentType = type;
        update();
    }

    void EditorInfo::setCurretTile(uint16_t tile) {
        currentTile = tile;
        std::cout << tile << std::endl;
        update();
    }



}

