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

AudioManager::AudioManager() {
    sf::SoundBuffer soundBuffer;
    soundBuffer.loadFromFile("assets/kuolema1.wav");
    sounds["dead"] = soundBuffer;
}

AudioManager::AudioManager(const AudioManager& orig) {
}

AudioManager::~AudioManager() {
}

const void AudioManager::playSound(std::string soundName) {
    sf::Sound sound;
    sound.setBuffer(sounds.at(soundName));
    sound.play();
}
