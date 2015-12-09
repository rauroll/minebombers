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

#include <iostream>

int main(int argc, char const** argv) {
    Game game = Game();
    game.setRandomTreasures(50);
    game.addPlayer("JERE");
    game.addPlayer("JERE2");
    
    Projectile proj = Projectile("jonnemissile", "assets/explosion.png", 10);
    Weapon onlyWeapon = Weapon("jonnegun", 99, proj);
    
    game.getPlayers()[0].addWeapon(onlyWeapon);
    
    game.setScene(MENUSCENE);

    sf::Vector2u mapSize = game.getMap().getSize();
    int statusbarHeight = 100;
    sf::RenderWindow window(sf::VideoMode(mapSize.x * 16, mapSize.y * 16 + statusbarHeight), "Minebombers");
    
    sf::Clock clock;
    FPS fps;
    clock.restart();
    
    sf::Time dt = sf::milliseconds(30);
    sf::Time gameTime = sf::milliseconds(0);
    bool draw = true;
    
    while (window.isOpen())
    {        
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            else
                game.getScene()->onEvent(event);
        }
        
        while(gameTime + dt <= clock.getElapsedTime()) {            
            game.getScene()->update();
                        
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