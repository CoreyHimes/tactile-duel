#include <SFML/Graphics.hpp>

int main()
{
    unsigned int screenWidth = 600;
    unsigned int screenHeight = 512;
    sf::RenderWindow window(sf::VideoMode(screenHeight, screenWidth), "Tactile Duel");
    sf::Texture texture;
    texture.loadFromFile("images/soldierSpriteSheet.png");
    sf::Sprite sprite(texture, sf::IntRect(0, 0, 64, 64));
    while (window.isOpen())
    {
        window.clear();
        sf::Event event;
        for (int i = 0; i <= 7; i++) {
            sf::RectangleShape shape(sf::Vector2f(64.f, 64.f));
            for (int j = 0; j <= 7; j++)
            {
                //Make checkerboard pattern
                ((i + j) % 2 == 0) ? shape.setFillColor(sf::Color::Green) : shape.setFillColor(sf::Color::White);

                shape.setPosition(sf::Vector2f(64.f * i, 64.f * j));
                window.draw(shape);
            }
        }

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            else if (event.type == sf::Event::MouseMoved)
            {
                //check if mouse hovers the characters
            }
            else if (event.type == sf::Event::MouseButtonPressed)
            {
                if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Right) )
                {
                    sprite.setPosition(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
                }
                if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) 
                {
                    sprite.setPosition(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
                }
            }       

        }
        window.draw(sprite);
               
        window.display();
    }

    return 0;
}
