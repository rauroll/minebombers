//
//  Scene.hpp
//  minebombers1
//
//  Created by Jere Vaara on 12.11.2015.
//  Copyright © 2015 RVHN-project. All rights reserved.
//

#ifndef Scene_hpp
#define Scene_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>

class Scene {
public:
    virtual void update(sf::RenderWindow& window) = 0;
};

#endif /* Scene_hpp */
