//
//  time.hpp
//  Asteroids
//
//  Created by Jakub Charvat on 28.05.2021.
//  Copyright © 2021 Jakub Charvat. All rights reserved.
//

#pragma once

#include <iostream>

#include <SFML/System.hpp>


class Time
{
public:
    static void             initialise();
    static void             initialise(const int &, const int &);
        
    static void             updateDeltaTime();
    static sf::Time         deltaTime();
    static double           deltaTimeSec();
    static bool             shouldRedraw();
    static unsigned long    renderSleepNs();
    
    static void             updatePhysicsDeltaTime();
    static sf::Time         physicsDeltaTime();
    static double           physicsDeltaTimeSec();
    static bool             shouldRecalculatePhysics();
    static unsigned long    physicsUpdateSleepNs();
    
private:
    static sf::Clock    _clock;
    static sf::Clock    _physicsClock;
    
    static sf::Time     _deltaTime;
    static sf::Time     _targetFrameDt;
    static sf::Time     _frameTimeBias;
    
    static sf::Time     _physicsDeltaTime;
    static sf::Time     _targetPhysicsFrameDt;
    static sf::Time     _physicsUpdateTimeBias;
};
