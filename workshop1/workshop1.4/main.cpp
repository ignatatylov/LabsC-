#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>

void onMouseClick(const sf::Event::MouseButtonEvent &event, sf::Vector2f &mousePosition)
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
        case sf::Event::MouseButtonPressed:
            onMouseClick(event.mouseButton, mousePosition);
            break;
        default:
            break;
        }
    }
}

void setScale(sf::Sprite &cat, float scaleWidth, float scaleHeight)
{
    sf::Vector2f targetSize(800 / 16, 800 / 16);
    cat.setScale(
        targetSize.x / cat.getLocalBounds().width * scaleWidth,
        targetSize.y / cat.getLocalBounds().height * scaleHeight);
}

void updatePosition(const sf::Vector2f &mousePosition, sf::Sprite &cat, float dtime)
{
    const sf::Vector2f delta = mousePosition - cat.getPosition();
    const float deltaLength = std::sqrt(delta.x * delta.x + delta.y * delta.y);
    if (deltaLength != 0)
    {
        const sf::Vector2f direction = {delta.x / deltaLength, delta.y / deltaLength};
        const float speed = 20.0f;
        cat.move(direction * speed * dtime);
    }
    if (delta.x >= 0)
    {
        setScale(cat, 1, 1);
    }
    else
    {
        setScale(cat, -1, 1);
    }
}

void update(const sf::Vector2f &mousePosition, sf::Sprite &cat, sf::Clock &clock, sf::Sprite &pointer)
{
    const float dtime = clock.restart().asSeconds();
    pointer.setPosition(mousePosition);
    updatePosition(mousePosition, cat, dtime);
}

int main()
{

    constexpr unsigned WINDOW_WIDTH = 800;
    constexpr unsigned WINDOW_HEIGHT = 600;

    sf::Clock clock;

    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(
        sf::VideoMode({WINDOW_WIDTH, WINDOW_HEIGHT}),
        "Cat", sf::Style::Default, settings);

    sf::Vector2f mousePosition;
    sf::Texture catTexture;
    if (!catTexture.loadFromFile("cat.png"))
    {
        std::cout << "err" << std::endl;
    }

    sf::Texture pointerTexture;
    if (!pointerTexture.loadFromFile("pointer.png"))
    {
        std::cout << "err" << std::endl;
    }

    sf::Sprite cat(catTexture);
    cat.setOrigin(cat.getLocalBounds().width / 2, cat.getLocalBounds().height / 2);
    setScale(cat, 1, 1);

    sf::Sprite pointer(pointerTexture);
    pointer.setOrigin(pointer.getLocalBounds().width / 2, pointer.getLocalBounds().height / 2);
    setScale(pointer, 1, 1);

    cat.setPosition(
        WINDOW_WIDTH / 2,
        WINDOW_HEIGHT / 2);

    while (window.isOpen())
    {
        pollEvents(window, mousePosition);
        update(mousePosition, cat, clock, pointer);
        window.clear(sf::Color::White);
        window.draw(cat);
        window.draw(pointer);
        window.display();
    }
}