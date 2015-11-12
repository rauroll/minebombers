//
//  Game.hpp
//  minebombers1
//
//  Created by Max Huttunen on 12/11/15.
//  Copyright © 2015 RVHN-project. All rights reserved.
//

#ifndef Game_hpp
#define Game_hpp

#include <stdio.h>
#include "Scene.hpp"

class Game {
public:
    void setScene(Scene& scene) {
        currentScene = scene;
    }
    
    Scene& getScene() {
        return currentScene;
    }
private:
    Scene currentScene;
};

#endif /* Game_hpp */
