//
//  GravityCircle.hpp
//  Asteroids
//
//  Created by Jakub Charvat on 29.05.2021.
//  Copyright © 2021 Jakub Charvat. All rights reserved.
//

#pragma once

#include <SFML/Graphics.hpp>


class GravityCircle
{
public:
    GravityCircle(const int &);
    void            update(const double &);
    void            draw(sf::RenderWindow &window);
    
private:
    sf::CircleShape _circle;
    double          posX;
    double          posY;
    double          velocityX;
    double          velocityY;
    double          accelerationX;
    double          accelerationY;
};
