#include <iostream>

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include "Game.h"
#include "Scene.h"
#include "MenuScene.h"
#include "MapGenerator.h"
#include "FPS.h"
#include "Weapon.h"
#include "Projectile.h"
#include "ConfigManager.h"


int main(int argc, char const** argv) {
    ConfigManager& config = ConfigManager::getInstance();
    config.loadFromFile("mb.config");
    
    Game& game = Game::getInstance();
    game.setScene(MENUSCENE);
    
    sf::Vector2u mapSize = game.getMap().getSize();
    int statusbarHeight = 100;
    
    sf::RenderWindow window(sf::VideoMode(mapSize.x * 16, mapSize.y * 16 + statusbarHeight), "Minebombers");
    window.setMouseCursorVisible(false);
    
    sf::Clock clock;
    FPS fps;
    clock.restart();
    
    sf::Time dt = sf::milliseconds(30);
    sf::Time gameTime = sf::milliseconds(0);
    bool draw = true;
    
    sf::Keyboard::Key muteButton = (sf::Keyboard::Key)config.getInt("mute_button", sf::Keyboard::F10);
    
    while (window.isOpen())
    {        
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            else if (event.type == sf::Event::KeyPressed && event.key.code == muteButton)
                game.toggleSound();
            else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
                game.setScene(MENUSCENE);
            else
                game.getScene()->onEvent(event);
        }
        
        while(gameTime + dt <= clock.getElapsedTime()) {            
            game.getScene()->update(dt);
                        
            gameTime += dt;
            draw = true;
        }
        
        if(draw) {
            window.clear();            
            game.getScene()->draw(window);            
            window.display();
            draw = false;
            
            std::string fpsStr = "Minebombers - FPS: " + std::to_string(fps.getFPS());
            window.setTitle(fpsStr);
            fps.update();
        }
        else {
            sf::sleep(sf::milliseconds(10));
        }
    }

    return EXIT_SUCCESS;
}