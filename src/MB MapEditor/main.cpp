/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: henrinurmi
 *
 * Created on November 18, 2015, 6:45 PM
 */

#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include "Tileset.h"
#include "Map.h"
#include "Editor.h"
#include "MapWriter.h"
#include "TileType.h"
#include "MapLoader.h"

int main(int argc, char** argv) {
    sf::RenderWindow window(sf::VideoMode(1600, 800), "MB MapEditor");
    
    MBEditor::MapLoader loader;
    MBEditor::Map map = loader.fromFile("map.mb");
    
    MBEditor::Editor editor = MBEditor::Editor(map);
    MBEditor::MapWriter writer;
    
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::KeyPressed:
                    if (event.key.code == sf::Keyboard::Space) {
                        editor.insert();
                    }
                    else if (event.key.code == sf::Keyboard::L) {
                        editor.nextTile();
                    }
                    else if (event.key.code == sf::Keyboard::H) {
                        editor.prevTile();
                    }
                    else if (event.key.code == sf::Keyboard::Left) {
                        editor.moveCursor(sf::Vector2u(-1, 0));
                    }
                    else if (event.key.code == sf::Keyboard::Up) {
                        editor.moveCursor(sf::Vector2u(0, -1));
                    }
                    else if (event.key.code == sf::Keyboard::Right) {
                        editor.moveCursor(sf::Vector2u(1, 0));
                    }
                    else if (event.key.code == sf::Keyboard::Down) {
                        editor.moveCursor(sf::Vector2u(0, 1));
                    }
                    else if (event.key.code == sf::Keyboard::W) {
                        editor.setType(MBEditor::WALL);
                    }
                    else if (event.key.code == sf::Keyboard::F) {
                        editor.setType(MBEditor::FLOOR);
                    }
                    else if (event.key.code == sf::Keyboard::R) {
                        editor.setType(MBEditor::ROCK);
                        uint8_t level = editor.getCurrentLevel() == 100 ? 50 : 100;
                        editor.setLevel(level);
                    }
                    else if (event.key.code == sf::Keyboard::S) {
                        writer.saveToFile(map, "map.mb");
                    }
                    break;
                default:
                    break;
            }
        }

        window.clear();
        window.draw(map);
        window.draw(editor);
        window.display();
    }

    return 0;
}

