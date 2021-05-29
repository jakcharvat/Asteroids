//
//  GravityCircle.cpp
//  Asteroids
//
//  Created by Jakub Charvat on 29.05.2021.
//  Copyright © 2021 Jakub Charvat. All rights reserved.
//

#include "gravity-circle.hpp"


//MARK: - Constructor
GravityCircle::GravityCircle(const int &radius):
    posX(300),
    posY(300),
    velocityX(0),
    velocityY(-400),
    accelerationX(0),
    accelerationY(300)
{
    _circle = sf::CircleShape(radius);
    _circle.setFillColor({ 200, 200, 100 });
}


//MARK: - Update
void GravityCircle::update(const double &deltaTime)
{
    velocityX += accelerationX*deltaTime;
    velocityY += accelerationY*deltaTime;
    
    posX += velocityX*deltaTime;
    posY += velocityY*deltaTime;
    
    _circle.setPosition(posX, posY);
}


//MARK: - Draw
void GravityCircle::draw(sf::RenderWindow &window)
{
    window.draw(_circle);
}
