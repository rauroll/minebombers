//
//  MenuScene.hpp
//  minebombers1
//
//  Created by Jere Vaara on 12.11.2015.
//  Copyright © 2015 RVHN-project. All rights reserved.
//

#ifndef MenuScene_hpp
#define MenuScene_hpp

#include <stdio.h>
#include "Scene.hpp"

class MenuScene: public Scene {
    
public:
    void update(sf::RenderWindow& window) {
        
        sf::CircleShape shape(50);
        
        // set the shape color to green
        shape.setFillColor(sf::Color(asd++, 250, 50));
        window.draw(shape);
        
    }
    void onEvent(sf::Event& event) {
        
    }
private:
    int asd = 5;
    
};

#endif /* MenuScene_hpp */
