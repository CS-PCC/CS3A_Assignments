#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <time.h>

const int SCREEN_WIDTH = 2560;
const int SCREEN_HEIGHT = 1600;
const int GRID_WIDTH = 200;
const int GRID_HEIGHT = 110;
const int CELL_SIZE = 5;

using namespace std;

int main()
{
    //----------S E T U P ------------------------------:

    //declare a window object:
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT),
                                                      "JAVA IS FOR WUSSIES!");
    //
    //VideoMode class has functions to detect screen size etc.
    //RenderWindow constructor has a third arguments to set style
    //of the window: resize, fullscreen etc.
    //
    //or...
    // you could do this:
    //sf::RenderWindow window;
    //window.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT),
    //                                                  "SFML window!");
    //

    window.setFramerateLimit(3);

    //this is where we keep all the shapes.
    //sf::RectangleShape shapeArray[GRID_HEIGHT][GRID_WIDTH];


    // call it once, after creating the window
    window.setVerticalSyncEnabled(true);
    //Application runs at the same freq as monitor

    //. . . . . . . SHAPES ............
    //this is how you would declare and manipulate shapes:
    sf::CircleShape circle(250.f);
    circle.setFillColor(sf::Color::Green);
    // set a 10-pixel wide orange outline
    circle.setOutlineThickness(10);
    circle.setOutlineColor(sf::Color(250, 150, 100));
    //circle.move(sf::Vector2f(200,300));


    // define a 120x50 rectangle
    sf::RectangleShape rectangle(sf::Vector2f(720, 500));
    rectangle.move(sf::Vector2f(300,20));
    rectangle.setFillColor(sf::Color::Magenta);
    // change the size to 100x100
    //rectangle.setSize(sf::Vector2f(10, 10));
    //. . . . . . . . . . . . . . . . . . . . . . . . . . .



    // run the program as long as the window is open
    // this is your main loop:
    while (window.isOpen()){
        cout<<"looooping..."<<endl;
        // check all the window's events that were triggered since the last iteration of the loop

        sf::Event event;

        //go through all the pending events: keyboard, mouse, close, resize, etc.
        //pollEvent and waitEvent are the only two functions that can fill event
        while (window.pollEvent(event))//or waitEvent: EVENT LOOP
        {
            // check the type of the event...
            switch (event.type)
            {
            // window closed
            // "close requested" event: we close the window
            case sf::Event::Closed:
                cout<<"close event was encountered!"<<endl;
                window.close();
                break;

                // key pressed
            case sf::Event::KeyPressed:
                cout<<"a key was pressed..."<<endl;
                //...
                break;
            case sf::Event::MouseButtonReleased:
                if (event.mouseButton.button == sf::Mouse::Right)
                {
                    std::cout << "the right button was pressed" << std::endl;
                    std::cout << "mouse x: " << event.mouseButton.x << std::endl;
                    std::cout << "mouse y: " << event.mouseButton.y << std::endl;
                }
                else
                    std::cout<<"left button?"<<std::endl;
                break;
            default:
                break;
            }
        }

        // you HAVE TO clear your window on every iteration of this while.
        window.clear();

        window.draw(circle); //draw the circle on the window
        window.draw(rectangle);
        window.display();
    }

    cout<<"------ NORMAL TERMINATION: WINDOW CLOSED!"<<endl;
    return 0;
}