
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

MenuScene menuScene = *new MenuScene();

int main(int, char const**)
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Minebombers");

    // Start the game loop
    while (window.isOpen())
    {
        // Clear screen
        window.clear();

        // scene.update(window);
        menuScene.update(window);

        // Update the window
        window.display();
    }

    return EXIT_SUCCESS;
}
