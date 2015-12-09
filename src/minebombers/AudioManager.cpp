/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   AudioManager.cpp
 * Author: Max
 * 
 * Created on December 5, 2015, 8:51 PM
 */

#include "AudioManager.h"
#include <SFML/Audio.hpp>
#include <iostream>

AudioManager::AudioManager() {
    sf::SoundBuffer soundBuffer;
    soundBuffer.loadFromFile("assets/lazer.wav");
    soundBuffers["lazer"] = soundBuffer;
    soundBuffer.loadFromFile("assets/tushy.wav");
    soundBuffers["tush"] = soundBuffer;
}

AudioManager::AudioManager(const AudioManager& orig) {
}

AudioManager::~AudioManager() {
}

const void AudioManager::playSound(std::string soundName) {
    if (sounds.find(soundName) == sounds.end())
        sounds[soundName] = sf::Sound(soundBuffers.at(soundName));
    sounds[soundName].play();
}
