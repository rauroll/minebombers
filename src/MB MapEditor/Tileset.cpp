/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Tileset.cpp
 * Author: henrinurmi
 * 
 * Created on November 18, 2015, 6:50 PM
 */

#include "Tileset.h"
namespace MBEditor {
    Tileset::Tileset() {
        Tileset(sf::Vector2u(0, 0));
    }
    
    Tileset::Tileset(sf::Vector2u tileSize) : tileSize(tileSize) {
    }

    Tileset::Tileset(const Tileset& orig) : tileSize(orig.tileSize) {
        texture = orig.texture;
    }

    Tileset::~Tileset() {
    }

    uint32_t Tileset::count() const {
        return (texture.getSize().x / tileSize.x) * (texture.getSize().y / tileSize.y);
    }
    
    bool Tileset::load(const std::string& filename) {
        textureName = filename;
        return texture.loadFromFile("assets/"+filename);
    }

    uint16_t Tileset::tileHeight() const {
        return tileSize.x;
    }

    uint16_t Tileset::tileWidth() const {
        return tileSize.y;
    }
    
    const sf::Texture& Tileset::getTexture() const {
        return texture;
    }
    
    uint16_t Tileset::height() const {
        return texture.getSize().y;
    }

    uint16_t Tileset::width() const {
        return texture.getSize().x;
    }

    sf::Vector2u Tileset::getTileSize() const {
        return tileSize;
    }

    const std::string& Tileset::getName() const {
        return textureName;
    }

}

