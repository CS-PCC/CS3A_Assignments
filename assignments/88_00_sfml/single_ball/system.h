#ifndef SYSTEM_H
#define SYSTEM_H

#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>

#include "constants.h"
#include "random.h"

using namespace std;

class System
{
public:
    System();
    void Step(int command);
    int Size();
    void Draw(sf::RenderWindow& widnow);
private:
    Random r;
    sf::CircleShape shape;
    sf::Vector2f vel; // velocity
};

#endif // SYSTEM_H
