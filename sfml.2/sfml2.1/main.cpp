#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <cmath>

constexpr unsigned WINDOW_WIDTH = 800;
constexpr unsigned WINDOW_HEIGHT = 600;

int main()
{
    constexpr float BALL_SIZE = 40;

    sf::RenderWindow window(sf::VideoMode({WINDOW_WIDTH, WINDOW_HEIGHT}), "Moving Ball");
    sf::Clock clock;

    sf::Vector2f position = {10, 350};

    sf::CircleShape ball(BALL_SIZE);
    ball.setFillColor(sf::Color(0xFF, 0xFF, 0xFF));

    sf::Vector2f speed = {50.f, 15.f};
    float speedX = 100.f;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        constexpr float amplitudeY = 80.f;
        constexpr float periodY = 2;

        float time = clock.getElapsedTime().asSeconds();
        float wavePhase = time * float(2 * M_PI);
        float x = speedX * time;
        float y = amplitudeY * std::sin(wavePhase / periodY);
        sf::Vector2f offset = {x, y};

        if (position.x + offset.x + 2 * BALL_SIZE >= WINDOW_WIDTH)
        {
            speedX = -speedX;
        }
        if ((position.x < 0) && (speedX < 0))
        {
            speedX = -speedX;
        }
        // if ((position.y + 2 * BALL_SIZE >= WINDOW_HEIGHT) && (speed.y > 0))
        // {
        //     speed.y = -speed.y;
        // }
        // if ((position.y < 0) && (speed.y < 0))
        // {
        //     speed.y = -speed.y;
        // }

        ball.setPosition(position + offset);

        window.clear();
        window.draw(ball);
        window.display();
    }
}