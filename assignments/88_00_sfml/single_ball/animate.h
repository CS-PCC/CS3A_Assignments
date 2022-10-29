#ifndef ANIMATE_H
#define ANIMATE_H

#include <iostream>
#include <SFML/Graphics.hpp>

#include "constants.h"
#include "system.h"
#include "sidebar.h"

using namespace std;

class Animate
{
public:
    Animate();
    void run();
    void processEvents();
    void update();
    void render();
    void Draw();
private:
    sf::RenderWindow window;
    sf::CircleShape mousePoint;         //The little red dot
    System system;                      //container for all the animated objects
    int command;                        //command to send to system
    sf::Font font;                      //font to draw on main screen
    sf::Text myTextLabel;               //text to draw on main screen
    bool mouseIn;                       //mouse is in the screen
    Sidebar sidebar;                    //rectangular message sidebar
};

string mouse_pos_string(sf::RenderWindow& window);

#endif // ANIMATE_H
