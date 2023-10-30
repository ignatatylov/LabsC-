#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <cmath>
#include <algorithm>

struct Pointer
{
    sf::ConvexShape arrow;
    sf::Vector2f position;
    float rotation = 0;
};

void onMouseMove(const sf::Event::MouseMoveEvent &event, sf::Vector2f &mousePosition)
{
    mousePosition = {float(event.x), float(event.y)};
}

float toDegrees(float radians)
{
    float x = double(radians) * 180.0 / M_PI;
    if (x < 0)
    {
        x = x + 360.0;
    }
    return x;
}

void pollEvents(sf::RenderWindow &window, sf::Vector2f &mousePosition)
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        switch (event.type)
        {
        case sf::Event::Closed:
            window.close();
            break;
        case sf::Event::MouseMoved:
            onMouseMove(event.mouseMove, mousePosition);
            break;
        default:
            break;
        }
    }
}

void update(Pointer &pointer, sf::Vector2f &mousePosition)
{
    const sf::Vector2f delta = mousePosition - pointer.position;
    pointer.rotation = toDegrees(atan2(delta.y, delta.x));
    pointer.arrow.setRotation(pointer.rotation);
    float motion = sqrt(pow(mousePosition.x - pointer.position.x, 2) + pow(mousePosition.y - pointer.position.y, 2));
    float distance = 0.3 * 0.016;
    sf::Vector2f direction = {(delta.x / motion) * distance, (delta.y / motion) * distance};
    if (motion >= 90)
    {
        pointer.position = pointer.position + direction;
        pointer.arrow.setPosition(pointer.position);
    }
}

void init(Pointer &pointer, sf::Vector2f &mousePosition)
{
    constexpr int pointCount = 7;
    pointer.arrow.setPointCount(pointCount);
    pointer.arrow.setPoint(0, {90, 0});
    pointer.arrow.setPoint(1, {30, 60});
    pointer.arrow.setPoint(2, {30, 30});
    pointer.arrow.setPoint(3, {-30, 30});
    pointer.arrow.setPoint(4, {-30, -30});
    pointer.arrow.setPoint(5, {30, -30});
    pointer.arrow.setPoint(6, {30, -60});
    pointer.arrow.setFillColor(sf::Color(0xFF, 0xFF, 0));
    pointer.arrow.setPosition(pointer.position);
    pointer.arrow.setRotation(pointer.rotation);
    pointer.arrow.setOutlineThickness(3);
    pointer.arrow.setOutlineColor(sf::Color(0x00, 0x00, 0x00));
}
int main()
{

    constexpr unsigned WINDOW_WIDTH = 800;
    constexpr unsigned WINDOW_HEIGHT = 600;

    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(
        sf::VideoMode({WINDOW_WIDTH, WINDOW_HEIGHT}),
        "Follows mouse", sf::Style::Default, settings);

    Pointer pointer;
    pointer.position = {500, 350};
    pointer.rotation = -82;

    sf::Vector2f mousePosition;

    init(pointer, mousePosition);
    while (window.isOpen())
    {
        pollEvents(window, mousePosition);
        update(pointer, mousePosition);
        window.clear(sf::Color(0xFF, 0xFF, 0xFF));
        window.draw(pointer.arrow);
        window.display();
    }
}