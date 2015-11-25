/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Tileset.h
 * Author: henrinurmi
 *
 * Created on November 24, 2015, 4:07 PM
 */

#ifndef TILESET_H
#define TILESET_H

#include <SFML/Graphics.hpp>

class Tileset {
public:
    Tileset();
    Tileset(sf::Vector2u tileSize);
    Tileset(const Tileset& orig);
    virtual ~Tileset();

    bool load(const std::string& filename);

    uint16_t tileWidth() const;
    uint16_t tileHeight() const;
    sf::Vector2u getTileSize() const;

    uint16_t width() const;
    uint16_t height() const;

    uint32_t count() const;

    const sf::Texture& getTexture() const;
    const std::string& getName() const;
private:
    sf::Texture texture;
    sf::Vector2u tileSize;
    std::string textureName;
};


#endif /* TILESET_H */

