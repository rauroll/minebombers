/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   AudioManager.h
 * Author: Max
 *
 * Created on December 5, 2015, 8:51 PM
 */

#ifndef AUDIOMANAGER_H
#define AUDIOMANAGER_H

#include <map>
#include <SFML/Audio.hpp>

class AudioManager {
public:
    AudioManager();
    AudioManager(const AudioManager& orig);
    virtual ~AudioManager();
    
    static AudioManager& getInstance() {
        static AudioManager instance;
        return instance;
    }
    
    const void playSound(std::string);
private:
    std::map<std::string, sf::SoundBuffer> soundBuffers;
    std::map<std::string, sf::Sound> sounds;
};

#endif /* AUDIOMANAGER_H */

