#ifndef SIDEBAR_H
#define SIDEBAR_H

#include <iostream>
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>

#include "constants.h"

using namespace std;

class Sidebar
{
public:
    Sidebar();
    Sidebar(float left, float width);
    void draw(sf::RenderWindow& window);
    string& operator [](int index);
private:
    vector<string> items;               //strings to place on the sidebar
    sf::RectangleShape rect;            //sidebar rectangle
    sf::Font font;                      //used to draw text
    sf::Text sb_text;                   //used to draw strings on the window object

    float _left;
    float _width;
};

#endif // SIDEBAR_H
