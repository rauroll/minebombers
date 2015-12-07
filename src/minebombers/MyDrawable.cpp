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
#include <iostream>

#include "MyDrawable.h"
#include "TextureManager.h"

MyDrawable::MyDrawable() : sprite(), name(), texturefile() {
    this->position = sf::Vector2u(0, 0);
}

MyDrawable::MyDrawable(const std::string texturefile, int x, int y, const std::string& name) {
    this->position = sf::Vector2u(x, y);
    this->name = name;
    this->texturefile = texturefile;

    const sf::Texture& texture = TextureManager::getInstance().load(texturefile);
    sf::Vector2u size = texture.getSize();
    
    std::cout << "texture size: " <<  size.x << " " << size.y << std::endl;
    sprite = sf::Sprite(texture);
    //sprite.setScale(16.0 / size.x, 16.0 / size.y);
    
    sprite.setPosition(x*16, y*16);
    std::cout << sprite.getPosition().x << ", " << sprite.getPosition().y << std::endl;
}

MyDrawable::MyDrawable(const MyDrawable& orig) : sprite(orig.sprite) {
    position = orig.position;
    name = orig.name;
    sprite.setPosition(orig.sprite.getPosition());
    //sprite.setPosition(position.x*16, position.y*16);
}

MyDrawable::~MyDrawable() {
}

const sf::Sprite& MyDrawable::getSprite() const {
    return sprite;
}

sf::Vector2u MyDrawable::getPos() const {
    return position;
}

std::string MyDrawable::getName() const {
    return name;
}

void MyDrawable::move(sf::Vector2u dir) {
    position += dir;
}

void MyDrawable::setPos(int newX, int newY) {
    position = sf::Vector2u(newX, newY);
}

const sf::Vector2u& MyDrawable::getPos() {
    return position;
}

void MyDrawable::updateSpritePosition() {
    sf::IntRect r1(spriteIndex * 16, 0, 16, 16);
    sprite.setTextureRect(r1);
    
    sf::Vector2f pixelPos = sprite.getPosition();
    
    int dX = position.x*16 - pixelPos.x;
    int dY = position.y*16 - pixelPos.y;
    
    //std::cout << position.x << ", " << position.y << " | " << pixelPos.x << ", " << pixelPos.y << " | " << dX << ", " << dY << std::endl;
    
    if(dX != 0) {
        pixelPos.x += std::min(std::abs(dX), 4)*(std::abs(dX)/dX);
    }
    
    if(dY != 0) {
        pixelPos.y += std::min(std::abs(dY), 4)*(std::abs(dY)/dY);
    }
    
    if (tick == tickRate) {
        spriteIndex = (spriteIndex + 1) % 8;
        tick = 0;
    }
        
    tick++;
    
    sprite.setPosition(pixelPos);
}

