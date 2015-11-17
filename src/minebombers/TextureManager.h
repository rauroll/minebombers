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

#include<map>

#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

class TextureManager {
public:
    TextureManager();
    TextureManager(const TextureManager& orig);
    virtual ~TextureManager();
    
    sf::Texture* load(std::string path);
private:
    std::map<std::string, sf::Texture> textures;
};

#endif /* TEXTUREMANAGER_H */

