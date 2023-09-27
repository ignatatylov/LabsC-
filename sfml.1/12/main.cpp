#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode({1550, 550}), "AIV");

    window.clear();

    sf::ConvexShape LetterA1;
    LetterA1.setFillColor(sf::Color(0xFF, 0x0, 0x0));
    LetterA1.setPosition({250, 50});
    LetterA1.setPointCount(3);
    LetterA1.setPoint(0, {0, 0});
    LetterA1.setPoint(1, {-200, 450});
    LetterA1.setPoint(2, {200, 450});
    window.draw(LetterA1);

    sf::ConvexShape LetterA2;
    LetterA2.setFillColor(sf::Color(0x0, 0x0, 0x0));
    LetterA2.setPosition({250, 250});
    LetterA2.setPointCount(3);
    LetterA2.setPoint(0, {0, 0});
    LetterA2.setPoint(1, {-50, 100});
    LetterA2.setPoint(2, {50, 100});
    window.draw(LetterA2);

    sf::ConvexShape LetterA3;
    LetterA3.setFillColor(sf::Color(0x0, 0x0, 0x0));
    LetterA3.setPosition({250, 400});
    LetterA3.setPointCount(4);
    LetterA3.setPoint(0, {-50, 0});
    LetterA3.setPoint(1, {-100, 100});
    LetterA3.setPoint(2, {100, 100});
    LetterA3.setPoint(3, {50, 0});
    window.draw(LetterA3);

    sf::RectangleShape LetterI1;
    LetterI1.setFillColor(sf::Color(0xFF, 0x0, 0x0));
    LetterI1.setSize({400, 50});
    LetterI1.setPosition({500, 50});
    window.draw(LetterI1);

    sf::RectangleShape LetterI2;
    LetterI2.setFillColor(sf::Color(0xFF, 0x0, 0x0));
    LetterI2.setSize({100, 350});
    LetterI2.setPosition({650, 100});
    window.draw(LetterI2);

    sf::RectangleShape LetterI3;
    LetterI3.setFillColor(sf::Color(0xFF, 0x0, 0x0));
    LetterI3.setSize({400, 50});
    LetterI3.setPosition({500, 450});
    window.draw(LetterI3);

    sf::ConvexShape LetterV1;
    LetterV1.setFillColor(sf::Color(0xFF, 0x0, 0x0));
    LetterV1.setPosition({1200, 50});
    LetterV1.setPointCount(3);
    LetterV1.setPoint(0, {-200, 0});
    LetterV1.setPoint(1, {200, 0});
    LetterV1.setPoint(2, {0, 450});
    window.draw(LetterV1);

    sf::ConvexShape LetterV2;
    LetterV2.setFillColor(sf::Color(0x0, 0x0, 0x0));
    LetterV2.setPosition({1200, 50});
    LetterV2.setPointCount(3);
    LetterV2.setPoint(0, {-100, 0});
    LetterV2.setPoint(1, {100, 0});
    LetterV2.setPoint(2, {0, 250});
    window.draw(LetterV2);

    window.display();

    sf::sleep(sf::seconds(5));
}