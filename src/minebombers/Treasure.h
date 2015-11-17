/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Treasure.h
 * Author: Jere
 *
 * Created on 17. marraskuuta 2015, 17:59
 */

#ifndef TREASURE_H
#define TREASURE_H

class Treasure {
public:
    Treasure();
    Treasure(const Treasure& orig);
    virtual ~Treasure();
private:
    sf::Sprite sprite;
    int value;
    int x;
    int y;
};

#endif /* TREASURE_H */

