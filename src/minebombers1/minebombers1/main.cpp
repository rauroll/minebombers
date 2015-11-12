
//
// Disclamer:
// ----------
//
// This code will work only if you selected window, graphics and audio.
//
// Note that the "Run Script" build phase will copy the required frameworks
// or dylibs to your application bundle so you can execute it on any OS X
// computer.
//
// Your resource files (images, sounds, fonts, ...) are also copied to your
// application bundle. To get the path to these resource, use the helper
// method resourcePath() from ResourcePath.hpp
//

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

// Here is a small helper for you ! Have a look.
#include "ResourcePath.hpp"
#include "MenuScene.hpp"
#include "Game.hpp"

int main(int, char const**)
{
    Game* game = new Game();
    MenuScene* menuScene = new MenuScene(*game);
    game->setScene(*menuScene);
    
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
                game->getScene().onEvent(event);
        }
        game->getScene().update(window);

        window.display();
    }

    return EXIT_SUCCESS;
}
