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

#include "ResourceManager.h"
#include "Game.h"
#include <iostream>

ResourceManager::ResourceManager() {
    sf::SoundBuffer soundBuffer;
    soundBuffer.loadFromFile("assets/lazer.wav");
    soundBuffers["lazer"] = soundBuffer;
    soundBuffer.loadFromFile("assets/tushy.wav");
    soundBuffers["tush"] = soundBuffer;
    soundBuffer.loadFromFile("assets/booom.wav");
    soundBuffers["boom"] = soundBuffer;
    soundBuffer.loadFromFile("assets/shot.wav");
    soundBuffers["shot"] = soundBuffer;
    soundBuffer.loadFromFile("assets/räjähdys.wav");
    soundBuffers["explosion"] = soundBuffer;
    soundBuffer.loadFromFile("assets/kling.wav");
    soundBuffers["kling"] = soundBuffer;
    soundBuffer.loadFromFile("assets/yesh.wav");
    soundBuffers["yesh"] = soundBuffer;
    soundBuffer.loadFromFile("assets/ohright.wav");
    soundBuffers["ohright"] = soundBuffer;
    soundBuffer.loadFromFile("assets/kuolema2.wav");
    soundBuffers["death2"] = soundBuffer;
    soundBuffer.loadFromFile("assets/aivittu1.wav");
    soundBuffers["hurt1"] = soundBuffer;
    soundBuffer.loadFromFile("assets/plip.wav");
    soundBuffers["plip"] = soundBuffer;
    soundBuffer.loadFromFile("assets/plop.wav");
    soundBuffers["plop"] = soundBuffer;
}

ResourceManager::~ResourceManager() {
}

const sf::Font& ResourceManager::getFont() {
    if (!font) {
        font = new sf::Font();
        font->loadFromFile("assets/BebasNeue.otf");
    }
    return *font;
}

const sf::Texture& ResourceManager::loadTexture(const std::string& path) {
    if(textures.find(path) != textures.end()) {
        return textures[path];
    }
    else {
        sf::Texture texture;
        if(!texture.loadFromFile(path)) {
            //TODO add placeholder
        }

        textures[path] = texture;
        return textures[path];
    }
}

const void ResourceManager::playSound(std::string soundName) {
    if (Game::getInstance().soundEnabled()) {
        if (sounds.find(soundName) == sounds.end())
            sounds[soundName] = sf::Sound(soundBuffers.at(soundName));
        sounds[soundName].play();
    }
}

const void ResourceManager::playKling(int value) {
    if (Game::getInstance().soundEnabled()) {
        if (sounds.find("kling") == sounds.end())
            sounds["kling"] = sf::Sound(soundBuffers.at("kling"));
        sounds["kling"].setPitch(1 / (value / 500.0));
        sounds["kling"].setVolume(20);
        sounds["kling"].play();
        if (value > 700) {
            this->playSound("ohright");
        } else if (value > 600) {
            this->playSound("yesh");
        }
    }
}

const void ResourceManager::playExplosion(int damage, std::string soundName) {
    if (Game::getInstance().soundEnabled()) {
        if (sounds.find(soundName) == sounds.end())
            sounds[soundName] = sf::Sound(soundBuffers.at(soundName));
        sounds[soundName].setPitch(1 / (damage / 20.0));
        sounds[soundName].setVolume(50 * (damage / 30.0));
        sounds[soundName].play();
    }
}


const void ResourceManager::playMusic(std::string musicName) {
    if (musicName == "game") {
        if (!this->music.openFromFile("assets/never_die.flac")) {
            return;
        }
        //this->music.setPitch(2); // for hilarious effect :: D maybe for some power up?
        this->music.setVolume(15);
        this->music.play();
        this->music.setLoop(true);
    }
}

const void ResourceManager::enableMusic(bool enable) {
    music.setVolume(enable ? 15 : 0);
}