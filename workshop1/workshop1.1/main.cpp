#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>

void pollEvents(sf::RenderWindow &window)
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        switch (event.type)
        {
        case sf::Event::Closed:
            window.close();
            break;
        default:
            break;
        }
    }
}

int main()
{
    const sf::Vector2f position = {500, 350};
    float rotation = -82;

    sf::RenderWindow window(sf::VideoMode({800, 600}), "pointer");

    sf::ConvexShape pointer;
    constexpr int pointCount = 7;
    pointer.setPointCount(pointCount);
    pointer.setPoint(0, {90, 0});
    pointer.setPoint(1, {30, 60});
    pointer.setPoint(2, {30, 30});
    pointer.setPoint(3, {-30, 30});
    pointer.setPoint(4, {-30, -30});
    pointer.setPoint(5, {30, -30});
    pointer.setPoint(6, {30, -60});
    pointer.setFillColor(sf::Color(0xFF, 0xFF, 0));
    pointer.setPosition(position);
    pointer.setRotation(rotation);
    pointer.setOutlineThickness(3);
    pointer.setOutlineColor(sf::Color(0x00, 0x00, 0x00));

    while (window.isOpen())
    {
        pollEvents(window);
        window.clear(sf::Color(0xFF, 0xFF, 0xFF));
        window.draw(pointer);
        window.display();
    }
}