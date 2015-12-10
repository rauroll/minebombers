/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TextureManager.h
 * Author: henrinurmi
 *
 * Created on November 17, 2015, 6:35 PM
 */


#include <SFML/Graphics.hpp>
#include <map>

#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

class TextureManager {
public:
    TextureManager();
    virtual ~TextureManager();
    
    static TextureManager& getInstance() {
        static TextureManager instance;
        return instance;
    }
    
    const sf::Font& getFont();
    
    const sf::Texture& load(const std::string& path);
private:
    std::map<std::string, sf::Texture> textures;
    sf::Font* font;
};

#endif /* TEXTUREMANAGER_H */

