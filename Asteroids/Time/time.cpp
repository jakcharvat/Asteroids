//
//  time.cpp
//  Asteroids
//
//  Created by Jakub Charvat on 28.05.2021.
//  Copyright © 2021 Jakub Charvat. All rights reserved.
//

#include "time.hpp"

#include <math.h>

#define TARGET_FPS 60
#define TARGET_PHYSICS_FPS 240


//MARK: - Member Initialisation
sf::Clock   Time::_clock;
sf::Clock   Time::_physicsClock;

sf::Time    Time::_deltaTime;
sf::Time    Time::_targetFrameDt;
sf::Time    Time::_frameTimeBias;

sf::Time    Time::_physicsDeltaTime;
sf::Time    Time::_targetPhysicsFrameDt;
sf::Time    Time::_physicsUpdateTimeBias;


//MARK: - Initialisation
void Time::initialise()
{
    initialise(TARGET_FPS, TARGET_PHYSICS_FPS);
}


void Time::initialise(const int &targetFps, const int &targetPhysicsFps)
{
    double seconds = 1 / (double)targetFps;
    _targetFrameDt = sf::seconds(seconds);
    
    double physicsSeconds = 1 / (double)targetPhysicsFps;
    _targetPhysicsFrameDt = sf::seconds(physicsSeconds);
}


//MARK: - Update DeltaTime
void Time::updateDeltaTime()
{
    _deltaTime = _clock.restart();
    _frameTimeBias += (_targetFrameDt-_deltaTime);
}

void Time::updatePhysicsDeltaTime()
{
    _physicsDeltaTime = _physicsClock.restart();
    _physicsUpdateTimeBias += (_targetPhysicsFrameDt-_physicsDeltaTime);
}


//MARK: - DeltaTime
sf::Time Time::deltaTime()
{
    return _deltaTime;
}

double Time::deltaTimeSec()
{
    return deltaTime().asSeconds();
}

sf::Time Time::physicsDeltaTime()
{
    return _physicsDeltaTime;
}

double Time::physicsDeltaTimeSec()
{
    return physicsDeltaTime().asSeconds();
}


//MARK: - Should Update
bool Time::shouldRedraw()
{
    return (_clock.getElapsedTime() > _targetFrameDt);
}

bool Time::shouldRecalculatePhysics()
{
    return (_physicsClock.getElapsedTime() > _targetPhysicsFrameDt);
}


//MARK: - Sleep
unsigned long Time::renderSleepNs()
{
    sf::Time time = _targetFrameDt - _clock.getElapsedTime() + _frameTimeBias;
    return fmax( 0, time.asMicroseconds() * 1e3 );
}

unsigned long Time::physicsUpdateSleepNs()
{
    sf::Time time = _targetPhysicsFrameDt - _physicsClock.getElapsedTime() + _physicsUpdateTimeBias;
    return fmax( 0, time.asMicroseconds() * 1e3);
}
