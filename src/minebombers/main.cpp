#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include "Game.h"
#include "Scene.h"
#include "MenuScene.h"
#include "MapGenerator.h"
#include "GameScene.h"
#include "FPS.h"

#include <iostream>

int main(int argc, char const** argv) {
    Game game = Game();
    game.setRandomTreasures(50);
    game.addPlayer("JERE");
    game.addPlayer("JERE2");
    
    MenuScene menuScene = MenuScene();
    GameScene gameScene = GameScene(game);
    game.setScene(&menuScene);
    
    
    sf::RenderWindow window(sf::VideoMode(800, 800), "Minebombers");
    
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
            sf::sleep(sf::milliseconds(1));
        }
        
        
    }

    return EXIT_SUCCESS;
}