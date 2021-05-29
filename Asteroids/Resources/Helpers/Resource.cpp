//
//  Resource.cpp
//  Asteroids
//
//  Created by Jakub Charvat on 29.05.2021.
//  Copyright © 2021 Jakub Charvat. All rights reserved.
//

#include "Resource.hpp"


std::string Resource::basePath = resourcePath();

//MARK: - Load Font
sf::Font Resource::loadFont(const std::string &name)
{
    sf::Font font;
    if (!font.loadFromFile(pathForResource(name)))
    {
        throw "Cannot load font " + name;
    }
    return font;
}
