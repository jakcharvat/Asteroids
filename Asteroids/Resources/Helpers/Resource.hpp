//
//  Resource.hpp
//  Asteroids
//
//  Created by Jakub Charvat on 29.05.2021.
//  Copyright © 2021 Jakub Charvat. All rights reserved.
//

#pragma once

#include <SFML/Graphics.hpp>

#include "ResourcePath.hpp"


class Resource
{
public:
    static sf::Font loadFont(const std::string &name);
    
private:
    static std::string basePath;
    static std::string pathForResource(const std::string &name);
};
