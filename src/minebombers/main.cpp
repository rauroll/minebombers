#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include "Game.h"
#include "Scene.h"
#include "MenuScene.h"

int main(int, char const**)
{
    Game* game = new Game();
    MenuScene* menuScene = new MenuScene();
    game->setScene(menuScene);
    
    sf::RenderWindow window(sf::VideoMode(800, 600), "Minebombers");

    while (window.isOpen())
    {
        window.clear();
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            else
                game->getScene()->onEvent(event);
        }
        game->getScene()->update(window);

        window.display();
    }

    return EXIT_SUCCESS;
}