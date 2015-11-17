/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TextureManager.cpp
 * Author: henrinurmi
 * 
 * Created on November 17, 2015, 6:35 PM
 */

#include "TextureManager.h"

TextureManager::TextureManager() {
}

TextureManager::TextureManager(const TextureManager& orig) {
}

TextureManager::~TextureManager() {
}

sf::Texture* TextureManager::load(std::string path) {
    if(textures.find(path) != textures.end()) {
        return &textures[path];
    }
    else {
        sf::Texture texture;
        if(!texture.loadFromFile(path) {
            //TODO add placeholder
        }

        textures[path] = texture;
        return &texture;
    }
}
