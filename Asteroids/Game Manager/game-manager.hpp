//
//  game-manager.hpp
//  Asteroids
//
//  Created by Jakub Charvat on 28.05.2021.
//  Copyright © 2021 Jakub Charvat. All rights reserved.
//

#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

#include "gravity-circle.hpp"

class GravityCircle;

class GameManager
{
public:
    GameManager(sf::RenderWindow &);
    void update();
    
    
private:
    sf::RenderWindow    &window;
    std::thread *physicsThread;
    
    GravityCircle _circle;
    
    void handleWindowEvent(sf::Event &);
    void handleWindowRedraw();
};
