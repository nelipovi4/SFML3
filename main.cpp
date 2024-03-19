#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>


int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), L"Счетчик кликов мыши");
    sf::Font font;
    if (!font.loadFromFile("shrift.ttf")) // Замените на путь к вашему шрифту
    {
        // обработка ошибки
    }

    sf::Text text;
    text.setFont(font);
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::Red);
    text.setPosition(10, 10);

    int clickCount = 0;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    clickCount++;
                    std::string ss = std::to_string(clickCount);
                    text.setString(ss);

                }
            }
        }

        window.clear();
        window.draw(text);
        window.display();
    }

    return 0;
}
