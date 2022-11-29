#include "system.h"

System::System()
{
    int xpos = 100;
    int ypos = 100;
    //the shape of the object, along with its velocity, acceleration,
    //position, etc. should be part of the individual object.
    shape = sf::CircleShape(MIN_RADIUS + (MAX_RADIUS - MIN_RADIUS) / 2);
    shape.setPosition(sf::Vector2f(xpos, ypos));
    vel = sf::Vector2f(r.Next(-5,5), r.Next(-5,5)); //random velocity
    int r_ = r.Next(0,255);
    int g_ = r.Next(0,255);
    int b_ = r.Next(0,255);
    shape.setFillColor(sf::Color(r_, g_, b_));
}

void System::Step(int command)
{
    //all this is the responsibility of the individual object:
    shape.move(vel);
    sf::Vector2f pos = shape.getPosition();
    if ((pos.x)>=WORK_PANEL-20)
        vel = sf::Vector2f(-1*vel.x,1*vel.y);
    else if (pos.x<=0)
        vel = sf::Vector2f(-1*vel.x,1*vel.y);
    if ((pos.y)>=SCREEN_HEIGHT-20)
        vel = sf::Vector2f(1*vel.x,-1*vel.y);
    else if (pos.y<=0)
        vel = sf::Vector2f(1*vel.x,-1*vel.y);
    if (command == 4)
        vel = sf::Vector2f(-abs(vel.x),1*vel.y);
    else if (command == 6) {
        vel = sf::Vector2f(abs(vel.x),1*vel.y);
    }
    // speed up
    if (command == 8) {
        int vel_x = vel.x > 0 ? ++vel.x : --vel.x;
        int vel_y = vel.y > 0 ? ++vel.y : --vel.y;
        vel = sf::Vector2f(vel_x, vel_y);
    }
    // speed down
    else if (command == 2) {
        int vel_x = 0;
        int vel_y = 0;
        if (vel.x != 0) vel_x = vel.x < 0 ? ++vel.x : --vel.x;
        if (vel.y != 0) vel_y = vel.y < 0 ? ++vel.y : --vel.y;
        vel = sf::Vector2f(vel_x, vel_y);
    }
    // change color
    if (command == 99) {
        int r_ = r.Next(0,255);
        int g_ = r.Next(0,255);
        int b_ = r.Next(0,255);
        shape.setFillColor(sf::Color(r_, g_, b_));
    }
    // increase radius of circle
    if (command == 11) {
        float radius = shape.getRadius();
        if (radius > MIN_RADIUS) --radius;
        shape.setRadius(radius);
    }
    // decrease radius of circle
    else if (command == 12) {
        float radius = shape.getRadius();
        if (radius < MAX_RADIUS) ++radius;
        shape.setRadius(radius);
    }
    
}

void System::Draw(sf::RenderWindow& window)
{
    window.clear();
    window.draw(shape);
}
