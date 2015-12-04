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

#include "MyDrawable.h"
#include "TextureManager.h"

MyDrawable::MyDrawable() : sprite(), x(0), y(0), name() {
}

MyDrawable::MyDrawable(const std::string texturefile, int x, int y, const std::string& name) {
    this->x = x;
    this->y = y;
    this->name = name;

    sprite = sf::Sprite(TextureManager::getInstance().load(texturefile));
}

MyDrawable::MyDrawable(const MyDrawable& orig) : sprite(orig.sprite) {
    x = orig.x;
    y = orig.y;
    name = orig.name;   
}

MyDrawable::~MyDrawable() {
}

const sf::Sprite& MyDrawable::getSprite() const {
    return sprite;
}

sf::Vector2u MyDrawable::getPos() const {
    return sf::Vector2u(x, y);
}

std::string MyDrawable::getName() const {
    return name;
}

void MyDrawable::move(sf::Vector2u dir) {
    x += dir.x;
    y += dir.y;
}

void MyDrawable::setPos(int newX, int newY) {
    x = newX;
    y = newY;
}

