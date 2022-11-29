#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <time.h>

using namespace std;

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
const int GRID_WIDTH = 40;
const int GRID_HEIGHT = 30;
const int CELL_SIZE = 20;

class Anim
{
public:
    /**/Anim();
    int Random(int lo, int hi);         //This should be in its own class
    void FillShapes();                  //Fill Shapes array
    void UpdateShapes();
    /**/void run();                     //call process, update, and render
    /**/void processEvents();           //Event Loop:
                                        //  handle keyboard and mouse events
    /**/void update();                      //prepare the next frame
    /**/void render();                      //draw and display the next frame
    /**/void ShowShapes();                  //draw shapes on window object
private:
    sf::RenderWindow window;
    sf::RectangleShape shapeArray[GRID_HEIGHT][GRID_WIDTH];
    int grid[GRID_HEIGHT][GRID_WIDTH];
};


Anim::Anim()
{
    cout << "Creating Anim Window..." << endl;
    window.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "SFML window!");
    //VideoMode class has functions to detect screen size etc.
    //RenderWindow constructor has a third argument to set style
    //of the window: resize, full screen etc.
    //
    //or... window.create(sf::VideoMode(...
    window.setFramerateLimit(1);

    //initialize my shape objects:
    FillShapes();
}

int Anim::Random(int lo, int hi)
{
    int r = rand()%(hi+1)+lo+1;
    return r;
}

void Anim::FillShapes()
{
    for (int row=0; row<GRID_HEIGHT; row++){
        for (int col=0; col<GRID_WIDTH; col++){
            shapeArray[row][col].setSize(sf::Vector2f(CELL_SIZE, CELL_SIZE));

            //calculate the position of each rectangle (square)
            int vectorY=row*(CELL_SIZE+1);
            int vectorX=col*(CELL_SIZE+1);
            shapeArray[row][col].setPosition(sf::Vector2f(vectorX,vectorY));

            //color:
            shapeArray[row][col].setFillColor(sf::Color(Random(0,255),
                                                        Random(0,255),
                                                        Random(0,255)));
        }
    }
}

void Anim::UpdateShapes()
{
    for (int row=0; row<GRID_HEIGHT; row++){
        for (int col=0; col<GRID_WIDTH; col++){
            shapeArray[row][col].setFillColor(sf::Color(Random(0,255),
                                                        Random(0,255),
                                                        Random(0,255)));
        }
    }
}

void Anim::run()
{
    while (window.isOpen())
    {
        processEvents();
        update();
        render();
    }
}

void Anim::processEvents()
{
    sf::Event event;
    while (window.pollEvent(event))//or waitEvent
    {
    // check the type of the event...
        switch (event.type)
        {
            // window closed
            // "close requested" event: we close the window
            case sf::Event::Closed:
                window.close();
                cout << "Windows is closed!" << endl;
                break;
            // key pressed
            case sf::Event::KeyPressed:
                switch (event.key.code)
                {
                    case sf::Keyboard::Left:
                    case sf::Keyboard::A:
                        cout << "Moving Left..." << endl;
                        break;
                    case sf::Keyboard::Right:
                    case sf::Keyboard::D:
                        cout << "Moving Right..." << endl;
                        break;
                    case sf::Keyboard::Down:
                    case sf::Keyboard::S:
                        cout << "Moving Down..." << endl;
                        break;
                    case sf::Keyboard::Up:
                    case sf::Keyboard::W:
                        cout << "Moving Up..." << endl;
                        break;
                    default:
                        cout << "Unkown key..." << endl;
                }
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
}


void Anim::update()
{
    UpdateShapes();
}

void Anim::render()
{
    window.clear();
    ShowShapes();
    window.display();
}

void Anim::ShowShapes()
{
    for (int row=0; row<GRID_HEIGHT; row++){
        for (int col=0; col<GRID_WIDTH; col++){
            window.draw(shapeArray[row][col]);
        }
    }
}

int main()
{
    srand(time(0));
    Anim Animation;     //ctor
    Animation.run();    //run
    return 0;
}