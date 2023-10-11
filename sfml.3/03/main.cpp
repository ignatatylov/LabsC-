#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <chrono>
#include <thread>

float lastAngle{1000.0};

void init(sf::ConvexShape &pointer)
{
    pointer.setPointCount(3);
    pointer.setPoint(0, {40, 0});
    pointer.setPoint(1, {-20, -20});
    pointer.setPoint(2, {-20, 20});
    pointer.setPosition({400, 300});
    pointer.setFillColor(sf::Color(0xFF, 0x80, 0x00));
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

void onMouseMove(const sf::Event::MouseMoveEvent &event, sf::Vector2f &mousePosition)
{

    mousePosition = {float(event.x), float(event.y)};
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

void update(const sf::Vector2f &mousePosition, sf::ConvexShape &pointer)
{
    const sf::Vector2f delta = mousePosition - pointer.getPosition();
    const float angle = toDegrees(atan2(delta.y, delta.x));
    std::cout << angle << " xxx " << lastAngle << std::endl;
    if (lastAngle == 1000.0)
    {
        lastAngle = angle;
        return;
    }
    float dAngleDegrees = angle - lastAngle;
    if (lastAngle < 0)
    {
        lastAngle = 360.0;
    }
    if (lastAngle > 360.0)
    {
        lastAngle = 0.0;
    }

    if (((dAngleDegrees <= -0.15) || (dAngleDegrees > 180.0)) && (dAngleDegrees > -180.0))
    {
        pointer.setRotation(lastAngle - 0.15);
        lastAngle = lastAngle - 0.15;
        return;
    }
    if (((dAngleDegrees >= 0.15) || (dAngleDegrees < -180.0)) && (dAngleDegrees < 180.0))
    {
        pointer.setRotation(lastAngle + 0.15);
        lastAngle = lastAngle + 0.15;
        return;
    }
    if ((dAngleDegrees <= 0.15) && (dAngleDegrees > 0))
    {
        pointer.setRotation(angle);
        lastAngle = angle;
        return;
    }
    if ((dAngleDegrees >= -0.15) && (dAngleDegrees < 0))
    {
        pointer.setRotation(angle);
        lastAngle = angle;
        return;
    }

    lastAngle = angle;
}

void redrawFrame(sf::RenderWindow &window, sf::ConvexShape &pointer)
{
    window.clear();
    window.draw(pointer);
    window.display();
}

int main()
{

    constexpr unsigned WINDOW_WIDTH = 800;
    constexpr unsigned WINDOW_HEIGHT = 600;

    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode({WINDOW_WIDTH, WINDOW_HEIGHT}), "Prints mouse events to terminal", sf::Style::Default, settings);

    sf::ConvexShape pointer;
    sf::Vector2f mousePosition;

    init(pointer);

    while (window.isOpen())
    {
        pollEvents(window, mousePosition);
        update(mousePosition, pointer);
        redrawFrame(window, pointer);
        _sleep(10);
    }
}
