/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MyDrawable.cpp
 * Author: Jere
 * 
 * Created on 17. marraskuuta 2015, 18:00
 */

#include <cmath>
#include <algorithm>
#include <iostream>

#include "MyDrawable.h"
#include "ResourceManager.h"

MyDrawable::MyDrawable() : sprite(), name(), texturefile() {
    this->position = sf::Vector2u(0, 0);
}

MyDrawable::MyDrawable(const std::string texturefile, int x, int y, const std::string& name) {
    this->position = sf::Vector2u(x, y);
    this->name = name;
    this->texturefile = texturefile;

    const sf::Texture& texture = ResourceManager::getInstance().loadTexture(texturefile);
    sf::Vector2u size = texture.getSize();
    
    std::cout << "texture size: " <<  size.x << " " << size.y << std::endl;
    sprite = sf::Sprite(texture);
    //sprite.setScale(16.0 / size.x, 16.0 / size.y);
    
    sprite.setPosition(x*16, y*16);
    std::cout << sprite.getPosition().x << ", " << sprite.getPosition().y << std::endl;
    this->updateSpritePosition();
}

MyDrawable::MyDrawable(const MyDrawable& orig) : sprite(orig.sprite) {
    position = orig.position;
    name = orig.name;
    sprite.setPosition(orig.sprite.getPosition());
    //sprite.setPosition(position.x*16, position.y*16);
    this->updateSpritePosition();
}

MyDrawable::~MyDrawable() {
}

const sf::Sprite& MyDrawable::getSprite() const {
    return sprite;
}

sf::Vector2u MyDrawable::getPos() const {
    return position;
}

sf::Vector2u MyDrawable::getDir() const {
    return dir;
}

std::string MyDrawable::getName() const {
    return name;
}

void MyDrawable::move(sf::Vector2u dir) {
    this->dir = dir;
    position += dir;
}

void MyDrawable::setPos(int newX, int newY) {
    position = sf::Vector2u(newX, newY);
    sprite.setPosition(newX*16, newY*16);
}

const sf::Vector2u& MyDrawable::getPos() {
    return position;
}

bool MyDrawable::isMoving() const {
    sf::Vector2f v(this->position.x * 16.0 + 8, this->position.y * 16.0 + 8);
    return (v != this->sprite.getPosition() && !this->alwaysStillSprite);
}

bool MyDrawable::spriteHasEnded() const {
    return this->spriteEnded;
}


void MyDrawable::updateSpritePosition() {
    int spriteLength = sprite.getTexture()->getSize().x / 16;
    spriteLength = spriteLength == 0 ? 1 : spriteLength;
    
    

    if (spriteColumn == spriteLength - 1) this->spriteEnded = true;
    
    if (!isMoving()) spriteRow = 0; else spriteRow = 1;
    sf::IntRect r1(spriteColumn * 16, spriteRow * 16, 16, 16);
    
    sprite.setTextureRect(r1);
    sprite.setOrigin(sprite.getLocalBounds().width / 2, sprite.getLocalBounds().height / 2);
    
    
    int rotation = 0;
    if (dir.x == 1) {
        rotation = dir.y == 0 ? 90 : dir.y == 1 ? 135 : 45;
    } else if (dir.x == 0) {
        rotation = dir.y == 1 ? 180 : 0;
    } else {
        rotation = dir.y == 0 ? 270 : dir.y == 1 ? 225 : 315;
    }
    
    sprite.setRotation(rotation);
    
    sf::Vector2f pixelPos = sprite.getPosition();
    
    int dX = position.x*16 - pixelPos.x + 8;
    int dY = position.y*16 - pixelPos.y + 8;
    
   // std::cout << position.x << ", " << position.y << " | " << pixelPos.x << ", " << pixelPos.y << " | " << dX << ", " << dY << std::endl;
    
    if(dX != 0) {
        pixelPos.x += std::min(std::abs(dX), 4)*(std::abs(dX)/dX);
    }
    
    if(dY != 0) {
        pixelPos.y += std::min(std::abs(dY), 4)*(std::abs(dY)/dY);
    }
    
    if (tick == tickRate) {
        spriteColumn = (spriteColumn + 1) % spriteLength;
        tick = 0;
    }
    tick++;

    sprite.setPosition(pixelPos);
}

