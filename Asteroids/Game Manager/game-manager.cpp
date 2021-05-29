//
//  game-manager.cpp
//  Asteroids
//
//  Created by Jakub Charvat on 28.05.2021.
//  Copyright © 2021 Jakub Charvat. All rights reserved.
//

#include "game-manager.hpp"

#include <thread>

#include "ResourcePath.hpp"
#include "time.hpp"


//MARK: - Constructor
GameManager::GameManager(sf::RenderWindow &window):
    window(window),
    _circle(20)
{
    Time::initialise();
}


//MARK: - Update
void GameManager::update()
{
    // Process events
    sf::Event event;
    while (window.pollEvent(event)) {
        handleWindowEvent(event);
    }
    
//    if (Time::shouldRecalculatePhysics()) {
//        Time::updatePhysicsDeltaTime();
//
//    }
    

    Time::updateDeltaTime();
    handleWindowRedraw();

    std::this_thread::sleep_for(std::chrono::nanoseconds(Time::renderSleepNs()));
}


//MARK: - Event Handling
void GameManager::handleWindowEvent(sf::Event &event)
{
    if (event.type == sf::Event::Closed) {
        window.close();
    }
    
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
        window.close();
    }
}


//MARK: - Window Drawing
void GameManager::handleWindowRedraw()
{
    // Clear screen
    window.clear();
    
    _circle.update(Time::deltaTimeSec());
    _circle.draw(window);
    
    // Update the window
    window.display();
}
