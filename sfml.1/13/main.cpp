#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

int main()
{
    sf::ConvexShape trapeze;
    trapeze.setFillColor(sf::Color(0xFF, 0x00, 0));
    trapeze.setPosition(400, 200);
    trapeze.setPointCount(4);
    trapeze.setPoint(0, {-200, -20});
    trapeze.setPoint(1, {+200, -20});
    trapeze.setPoint(2, {+270, 120});
    trapeze.setPoint(3, {-270, 120});

    sf::RectangleShape mainRect;
    mainRect.setPosition({200, 320});
    mainRect.setSize({400, 300});
    mainRect.setFillColor(sf::Color(0x99, 0x66, 0x33));

    sf::RectangleShape door;
    door.setPosition({230, 420});
    door.setSize({100, 200});
    door.setFillColor(sf::Color(0x10, 0x10, 0x10));

    sf::CircleShape shape1(25);
    shape1.setPosition({470, 75});
    shape1.setFillColor(sf::Color(0xCF, 0xCF, 0xCF));

    sf::CircleShape shape2(30);
    shape2.setPosition({500, 45});
    shape2.setFillColor(sf::Color(0xCF, 0xCF, 0xCF));

    sf::CircleShape shape3(35);
    shape3.setPosition({540, 25});
    shape3.setFillColor(sf::Color(0xCF, 0xCF, 0xCF));

    sf::RectangleShape pipe;
    pipe.setPosition({470, 150});
    pipe.setSize({50, 100});
    pipe.setFillColor(sf::Color(0x90, 0x90, 0x90));

    sf::RectangleShape pipe2;
    pipe2.setPosition({455, 120});
    pipe2.setSize({75, 40});
    pipe2.setFillColor(sf::Color(0x90, 0x90, 0x90));

    sf::RenderWindow window(sf::VideoMode({1000, 800}), "Convex Shape");
    window.clear();
    window.draw(trapeze);
    window.draw(mainRect);
    window.draw(door);
    window.draw(pipe);
    window.draw(shape1);
    window.draw(shape2);
    window.draw(shape3);

    window.draw(pipe2);

    window.display();

    sf::sleep(sf::seconds(5));

    return 0;
}