#include "animate.h"

Animate::Animate():sidebar(WORK_PANEL, SIDE_BAR)
{
    cout<<"Animate CTOR: TOP"<<endl;
    window.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "SFML window!");
    //VideoMode class has functions to detect screen size etc.
    //RenderWindow constructor has a third argument to set style
    //of the window: resize, fullscreen etc.
    window.setFramerateLimit(360);

    //System will be implemented to manage a vector of objects to be animated.
    //  at that point, the constructor of the System class will take a vector
    //  of objects created by the animate object.
    //  animate will
    system = System();
    mouseIn = true;
    command = 0;
    mousePoint = sf::CircleShape();
    mousePoint.setRadius(5.0);
    mousePoint.setFillColor(sf::Color::Red);

    cout<<"Animate CTOR: preparing to load the font."<<endl;
    //--- FONT ----------
    //font file must be in the "working directory:
    //      debug/build folder
    //Make sure working directory is where it should be
    //      Projects->Build
    // and not inside the app file:
    //      Project->RUN->Working Folder
    //font must be a member of the class.
    //  Will not work with a local declaration
    if (!font.loadFromFile("arial.ttf")){
        cout<<"Animate() CTOR: Font failed to load"<<endl;
        cin.get();
        exit(-1);
    }
    myTextLabel = sf::Text("Initial String for myTextLabel", font);
    // set the character size
    myTextLabel.setCharacterSize(20);  // in pixels, not points!
    // set the text style
    myTextLabel.setStyle(sf::Text::Bold);
    // set the color
    myTextLabel.setFillColor(sf::Color::Green);
    myTextLabel.setPosition(sf::Vector2f(10, SCREEN_HEIGHT-myTextLabel.getLocalBounds().height-5));

    cout<<"Animate instantiated successfully."<<endl;
}

void Animate::run()
{
   while (window.isOpen())
   {
       processEvents();
       update();
       render(); //clear/draw/display
   }
   cout<<endl<<"-------ANIMATE MAIN LOOP EXITING ------------"<<endl;
}


void Animate::processEvents()
{
    sf::Event event;
    float mouseX, mouseY;
    while (window.pollEvent(event))//or waitEvent
    {
    // check the type of the event...
        switch (event.type)
        {
            // window closed
            case sf::Event::Closed:
                window.close();
                break;
            // key pressed
            case sf::Event::KeyPressed:
                switch(event.key.code)
                {
                    case sf::Keyboard::Left:
                        sidebar[SB_DIRECTION] = "LEFT ARROW";
                        command = 4;
                        break;
                    case sf::Keyboard::Right:
                        sidebar[SB_DIRECTION] = "RIGHT ARROW";
                        command = 6;
                        break;
                    case sf::Keyboard::Up:
                        sidebar[SB_SPEED] = "UP ARROW";
                        command = 8;
                        break;
                    case sf::Keyboard::Down:
                        sidebar[SB_SPEED] = "DOWN ARROW";
                        command = 2;
                        break;
                    case sf::Keyboard::C:
                        sidebar[SB_COLOR] = "C Pressed";
                        command = 99;
                        break;
                    case sf::Keyboard::LBracket:
                        sidebar[SB_SIZE] = "LEFT BRACKET";
                        command = 11;
                        break;
                    case sf::Keyboard::RBracket:
                        sidebar[SB_SIZE] = "RIGHT BRACKET";
                        command = 12;
                        break;
                    case sf::Keyboard::Escape:
                        sidebar[SB_SYSTEM] = "ESC: EXIT";
                        window.close();
                        break;
                    default:
                        break;
                }
                break;
            case sf::Event::MouseEntered:
                mouseIn = true;
                break;
            case sf::Event::MouseLeft:
                mouseIn = false;
                break;
            case sf::Event::MouseMoved:
                mouseX = event.mouseMove.x;
                mouseY = event.mouseMove.y;
                //Do something with it if you need to...
                break;
            case sf::Event::MouseButtonReleased:
                if (event.mouseButton.button == sf::Mouse::Right) {
                    sidebar[SB_MOUSE_CLICKED] = "RIGHT CLICK " +
                            mouse_pos_string(window);
                } else {
                    sidebar[SB_MOUSE_CLICKED] = "LEFT CLICK " +
                            mouse_pos_string(window);
                }
                break;
            default:
                break;
        }
    }
}

void Animate::update()
{
    //cause changes to the data for the next frame
    system.Step(command);
    command = 0;
    if (mouseIn){
        //mousePoint red dot:
        mousePoint.setPosition(sf::Mouse::getPosition(window).x-5,
                               sf::Mouse::getPosition(window).y-5);

        //mouse location text for sidebar:
        sidebar[SB_MOUSE_POSITION] = mouse_pos_string(window);
    }
}

void Animate::render()
{
    window.clear();
    Draw();
    window.display();
}
void Animate::Draw()
{
    //Look at the data and based on the data, draw shapes on window object.
    system.Draw(window);
    if (mouseIn){
        window.draw(mousePoint);
    }

    sidebar.draw(window);

    //- - - - - - - - - - - - - - - - - - -
    //getPosition() gives you screen coords, getPosition(window) gives you window coords
    //cout<<"mouse pos: "<<sf::Mouse::getPosition(window).x<<", "<<sf::Mouse::getPosition(window).y<<endl;
    //- - - - - - - - - - - - - - - - - - -

    //drawing Test: . . . . . . . . . . . .
    //This is how you draw text:)
    window.draw(myTextLabel);
    //. . . . . . . . . . . . . . . . . . .
}

string mouse_pos_string(sf::RenderWindow& window)
{
    return "(" +
            to_string(sf::Mouse::getPosition(window).x) +
            ", " +
            to_string(sf::Mouse::getPosition(window).y) +
            ")";
}
