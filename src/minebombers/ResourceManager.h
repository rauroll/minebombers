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
#include <SFML/Audio.hpp>
#include <map>

#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

class ResourceManager {
public:
    ResourceManager();
    virtual ~ResourceManager();
    
    static ResourceManager& getInstance() {
        static ResourceManager instance;
        return instance;
    }
    
    const sf::Font& getFont();
    const sf::Texture& loadTexture(const std::string& path);
    const void playSound(std::string soundName);
    const void playKling(int value);
    const void playPickSound(int pitch);
    const void playExplosion(int damage, std::string soundName);
    const void playMusic();
    const void playDeathSound();
    const void playHurtSound();
    const void enableMusic(bool);
private:
    std::map<std::string, sf::Texture> textures;
    sf::Font* font;
    std::map<std::string, sf::SoundBuffer> soundBuffers;
    std::map<std::string, sf::Sound> sounds;
    sf::Music music;
};

#endif /* TEXTUREMANAGER_H */

