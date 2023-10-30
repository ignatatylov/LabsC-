#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>

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
        default:
            break;
        }
    }
}

int main()
{

    constexpr unsigned WINDOW_WIDTH = 800;
    constexpr unsigned WINDOW_HEIGHT = 600;

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

    sf::Sprite cat(catTexture);
    cat.setPosition(
        WINDOW_WIDTH / 2 - 40,
        WINDOW_HEIGHT / 2 - 40);

    sf::Vector2f targetSize(80, 80);

    cat.setScale(
        targetSize.x / cat.getLocalBounds().width,
        targetSize.y / cat.getLocalBounds().height);

    while (window.isOpen())
    {
        pollEvents(window, mousePosition);
        window.clear(sf::Color::White);
        window.draw(cat);
        window.display();
    }
}