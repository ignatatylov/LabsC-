#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <cmath>
#include <algorithm>

struct Eyelid
{
    sf::ConvexShape pupil;
    sf::ConvexShape eye;
    sf::RectangleShape stem;
    sf::Vector2f position;
    float rotation = 0;
};

sf::Vector2f toEuclidean(float radius, float angle)
{
    sf::Vector2f v = {
        radius * float(cos(angle)),
        radius * float(sin(angle))};
    return v;
}

float toDegrees(float radians)
{
    return float(double(radians) * 180.0 / M_PI);
}

void updateEyelidElements(Eyelid &eyelid)
{
    eyelid.eye.setPosition(eyelid.position);

    const sf::Vector2f headOffset = toEuclidean(20, eyelid.rotation);
    eyelid.pupil.setPosition(eyelid.position + headOffset);

    const sf::Vector2f stemOffset = toEuclidean(-10, eyelid.rotation);
    eyelid.stem.setPosition(eyelid.position);
    eyelid.stem.setRotation(toDegrees(eyelid.rotation));
}

// Инициализирует фигуру-стрелку
void initEyelid(Eyelid &eyelid)
{
    constexpr int pointCount = 200;
    const sf::Vector2f ellipseRadiusPupil = {8.f, 20.f};

    eyelid.pupil.setFillColor(sf::Color(0x0, 0x0, 0x0));
    eyelid.pupil.setPointCount(pointCount);
    for (int pointNo = 0; pointNo < pointCount; ++pointNo)
    {
        float angle = float(2 * M_PI * pointNo) / float(pointCount);
        sf::Vector2f point = {
            ellipseRadiusPupil.x * std::sin(angle),
            ellipseRadiusPupil.y * std::cos(angle)};
        eyelid.pupil.setPoint(pointNo, point);
    }

    const sf::Vector2f ellipseRadiusEye = {40.f, 100.f};
    eyelid.eye.setFillColor(sf::Color(0xFF, 0xFF, 0xFF));
    eyelid.eye.setPointCount(pointCount);
    for (int pointNo = 0; pointNo < pointCount; ++pointNo)
    {
        float angle = float(2 * M_PI * pointNo) / float(pointCount);
        sf::Vector2f point = {
            ellipseRadiusEye.x * std::sin(angle),
            ellipseRadiusEye.y * std::cos(angle)};
        eyelid.eye.setPoint(pointNo, point);
    }

    eyelid.stem.setSize({80, 20});
    eyelid.stem.setOrigin({40, 10});
    eyelid.stem.setFillColor(sf::Color(0xFF, 0xFF, 0xFF));

    updateEyelidElements(eyelid);
}

void onMouseMove(const sf::Event::MouseMoveEvent &event, sf::Vector2f &mousePosition)
{
    std::cout << "mouse x=" << event.x << ", y=" << event.y << std::endl;
    mousePosition = {float(event.x), float(event.y)};
}
// Опрашивает и обрабатывает доступные события в цикле.
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

void update(const sf::Vector2f &mousePosition, Eyelid &eyelid)
{
    const sf::Vector2f delta = mousePosition - eyelid.position;
    eyelid.rotation = atan2(delta.y, delta.x);
    updateEyelidElements(eyelid);
}

void redrawFrame(sf::RenderWindow &window, Eyelid &eyelid1, Eyelid &eyelid2)
{
    window.clear();
    window.draw(eyelid1.stem);
    window.draw(eyelid1.eye);
    window.draw(eyelid1.pupil);
    window.draw(eyelid2.stem);
    window.draw(eyelid2.eye);
    window.draw(eyelid2.pupil);
    window.display();
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

    Eyelid eyelid1;
    Eyelid eyelid2;
    sf::Vector2f mousePosition;

    eyelid1.position = {300, 300};
    eyelid2.position = {500, 300};

    initEyelid(eyelid1);
    initEyelid(eyelid2);
    while (window.isOpen())
    {
        pollEvents(window, mousePosition);
        update(mousePosition, eyelid1);
        update(mousePosition, eyelid2);
        redrawFrame(window, eyelid1, eyelid2);
    } //dsfdsffsfd
}