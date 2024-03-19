#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <string>
#include <fstream>

//clickCount++;
//std::string ss = std::to_string(clickCount);
//text.setString(ss);
struct Data
{
    int age;
    std::string education;
    std::string gender;
    std::string answer;
};

struct List
{
    Data d;
    List* next;
};

void write_file(List* u) {
    std::ofstream write;
    write.open("data.txt", std::ios::app);

    List* p = u;
    while (p)
    {
        write << p->d.gender << " ";
        write << p->d.age << " ";
        write << p->d.education << " ";
        write << p->d.answer << "\n";
        p = p->next;
    }
    write.close();
}

void create_list(int age, std::string education, std::string gender, std::string answer) {
    List* u = NULL;
    Data data = { age, education, gender, answer };
    if (u == NULL)
    {
        u = new List{ data, NULL };
    }
    else
    {
        List* x = u;
        while (x->next)
        {
            x = x->next;
        }
        x->next = new List{ data, NULL };
    }
    write_file(u);
}









void menu_2(sf::RenderWindow& window, sf::Music& music, sf::Music& music2, sf::Music& music3);
void menu_1(sf::RenderWindow& window, sf::Music& music);
void menu_3(sf::RenderWindow& window, sf::Music& music);
void menu_4(sf::RenderWindow& window, sf::Music& music);
void menu_5(sf::RenderWindow& window, sf::Music& music);



int main()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "SFML window", sf::Style::Fullscreen);
    sf::Music music;
    music.openFromFile("music\\kahoot2.wav");
    music.play();
    music.setLoop(true);

    menu_1(window, music);


}

void menu_2(sf::RenderWindow& window, sf::Music& music, sf::Music& music2, sf::Music& music3) {
    int kol = 0;

    //блоки
    sf::RectangleShape rectangle_gendar(sf::Vector2f(700, 70));
    rectangle_gendar.setPosition(600, 150);
    rectangle_gendar.setFillColor(sf::Color::Transparent); // Прозрачный цвет заливки
    rectangle_gendar.setOutlineColor(sf::Color::Black); // Черный цвет контура
    rectangle_gendar.setOutlineThickness(2); // Толщина контура

    sf::RectangleShape rectangle_age(sf::Vector2f(700, 70));
    rectangle_age.setPosition(600, 350);
    rectangle_age.setFillColor(sf::Color::Transparent);
    rectangle_age.setOutlineColor(sf::Color::Black);
    rectangle_age.setOutlineThickness(2);

    sf::RectangleShape rectangle_education(sf::Vector2f(700, 70));
    rectangle_education.setPosition(600, 550);
    rectangle_education.setFillColor(sf::Color::Transparent);
    rectangle_education.setOutlineColor(sf::Color::Black);
    rectangle_education.setOutlineThickness(2);

    sf::RectangleShape rectangle_vopros(sf::Vector2f(700, 70));
    rectangle_vopros.setPosition(600, 750);
    rectangle_vopros.setFillColor(sf::Color::Transparent);
    rectangle_vopros.setOutlineColor(sf::Color::Black);
    rectangle_vopros.setOutlineThickness(2);

    sf::RectangleShape button_back(sf::Vector2f(250, 100));
    button_back.setPosition(600, 950);
    button_back.setFillColor(sf::Color::Transparent);


    sf::RectangleShape button_next(sf::Vector2f(250, 100));
    button_next.setPosition(1000, 950);
    button_next.setFillColor(sf::Color::Transparent);


    //шрифт и картинки
    sf::Texture texture;
    texture.loadFromFile("foto\\foto.jpg");
    sf::Sprite sprite(texture);
    sprite.setPosition(400, 400);

    sf::Texture fon2;
    fon2.loadFromFile("foto\\menu2.jpg");
    sf::Sprite img_menu2(fon2);
    img_menu2.setPosition(-100, -100);

    sf::Texture texture2;
    texture2.loadFromFile("foto\\Sa.jpg");
    sf::Sprite spriteSa(texture2);
    spriteSa.setPosition(700, 400);

    sf::Texture shipR;
    shipR.loadFromFile("foto\\ship_R.png");
    sf::Sprite ship_R(shipR);
    ship_R.setPosition(990, 830);
    ship_R.setScale(0.43, 0.43); // Уменьшение 

    sf::Texture shipL;
    shipL.loadFromFile("foto\\ship_L.png");
    sf::Sprite ship_L(shipL);
    ship_L.setPosition(580, 830);
    ship_L.setScale(0.43, 0.43); // Уменьшение 

    sf::Font font;
    font.loadFromFile("shriftu\\pirat.otf");

    sf::Text textStas(L"Стас ГЕЙ", font);
    textStas.setCharacterSize(100);
    textStas.setFillColor(sf::Color::Red);
    textStas.setPosition(610, 260);


    //основная часть

    sf::Text text_gander(L"Какой у вас пол?", font, 45);
    text_gander.setFillColor(sf::Color::Black);
    text_gander.setPosition(610, 92);

    sf::Text text_age(L"Сколько вам лет?", font, 45);
    text_age.setFillColor(sf::Color::Black);
    text_age.setPosition(610, 295);

    sf::Text text_education(L"Какое у вас образование?", font, 45);
    text_education.setFillColor(sf::Color::Black);
    text_education.setPosition(610, 490);

    sf::Text text_vopros(L"Вы пират?", font, 45);
    text_vopros.setFillColor(sf::Color::Black);
    text_vopros.setPosition(610, 690);

    sf::Text text_next(L"ОТПРАВИТЬ", font, 33);
    text_next.setFillColor(sf::Color::Yellow);
    text_next.setPosition(1022, 1005);

    sf::Text text_button_back(L"НАЗАД", font, 33);
    text_button_back.setPosition(685, 1005);
    text_button_back.setFillColor(sf::Color::Yellow);

    //написание
    sf::Text text_write_gander("", font);
    text_write_gander.setCharacterSize(50);
    text_write_gander.setFillColor(sf::Color::Black);
    text_write_gander.setPosition(610, 150);

    sf::Text text_write_age("", font);
    text_write_age.setCharacterSize(50);
    text_write_age.setFillColor(sf::Color::Black);
    text_write_age.setPosition(610, 350);

    sf::Text text_write_education("", font);
    text_write_education.setCharacterSize(50);
    text_write_education.setFillColor(sf::Color::Black);
    text_write_education.setPosition(610, 550);

    sf::Text text_write_vopros("", font);
    text_write_vopros.setCharacterSize(50);
    text_write_vopros.setFillColor(sf::Color::Black);
    text_write_vopros.setPosition(610, 750);

    //проверка
    sf::Text text_check_gendar("", font);
    text_check_gendar.setCharacterSize(35);
    text_check_gendar.setFillColor(sf::Color(0, 100, 0));
    text_check_gendar.setPosition(610, 220);

    sf::Text text_check_age("", font);
    text_check_age.setCharacterSize(35);
    text_check_age.setFillColor(sf::Color::Green);
    text_check_age.setPosition(610, 420);

    sf::Text text_check_education("", font);
    text_check_education.setCharacterSize(35);
    text_check_education.setFillColor(sf::Color(0, 100, 0));
    text_check_education.setPosition(610, 620);

    sf::Text text_check_vopros("", font);
    text_check_vopros.setCharacterSize(35);
    text_check_vopros.setFillColor(sf::Color(0, 100, 0));
    text_check_vopros.setPosition(610, 820);

    bool isRectangle1Clicked = false;
    bool isRectangle2Clicked = false;
    bool isRectangle3Clicked = false;
    bool isRectangle4Clicked = false;
    int intValue{};
    int correct_block_1 = 0;
    int correct_block_2 = 0;
    int correct_block_3 = 0;
    int correct_block_4 = 0;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                window.close();
            }

            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    if (rectangle_gendar.getGlobalBounds().contains(mousePos.x, mousePos.y))
                    {
                        isRectangle1Clicked = true;
                        isRectangle2Clicked = false;
                        isRectangle3Clicked = false;
                        isRectangle4Clicked = false;
                    }
                    else if (rectangle_age.getGlobalBounds().contains(mousePos.x, mousePos.y))
                    {
                        isRectangle1Clicked = false;
                        isRectangle2Clicked = true;
                        isRectangle3Clicked = false;
                        isRectangle4Clicked = false;
                    }
                    else if (rectangle_education.getGlobalBounds().contains(mousePos.x, mousePos.y))
                    {
                        isRectangle1Clicked = false;
                        isRectangle2Clicked = false;
                        isRectangle3Clicked = true;
                        isRectangle4Clicked = false;
                    }
                    else if (rectangle_vopros.getGlobalBounds().contains(mousePos.x, mousePos.y))
                    {
                        isRectangle1Clicked = false;
                        isRectangle2Clicked = false;
                        isRectangle3Clicked = false;
                        isRectangle4Clicked = true;
                    }
                }

            }

            if (event.type == sf::Event::TextEntered)
            {
                if (event.text.unicode < 128)
                {
                    if (isRectangle1Clicked && text_write_gander.getString().getSize() < 6)
                    {
                        text_write_gander.setString(text_write_gander.getString() + static_cast<char>(event.text.unicode));

                    }
                    if (isRectangle2Clicked && text_write_age.getString().getSize() < 3)
                    {

                        char inputChar = static_cast<char>(event.text.unicode);


                        if (std::isdigit(inputChar))
                        {

                            text_write_age.setString(text_write_age.getString() + inputChar);

                            std::string age = text_write_age.getString();
                            intValue = std::stoi(age);
                        }
                    }
                    if (isRectangle3Clicked && text_write_education.getString().getSize() < 7)
                    {
                        text_write_education.setString(text_write_education.getString() + static_cast<char>(event.text.unicode));
                    }
                    if (isRectangle4Clicked && text_write_vopros.getString().getSize() < 3)
                    {
                        text_write_vopros.setString(text_write_vopros.getString() + static_cast<char>(event.text.unicode));
                    }
                }
            }
            //очитска
            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    if (rectangle_gendar.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                        text_write_gander.setString("");
                    }
                    if (rectangle_age.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                        text_write_age.setString("");
                    }
                    if (rectangle_education.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                        text_write_education.setString("");
                    }
                    if (rectangle_vopros.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                        text_write_vopros.setString("");
                    }
                }
            }

            //проверка
            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    if (button_back.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                        menu_1(window, music);
                    }
                    if (button_next.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                        //1
                        if (text_write_gander.getString() == "man" || text_write_gander.getString() == "woman") {
                            text_check_gendar.setFillColor(sf::Color(0, 100, 0));
                            text_check_gendar.setString("That's right");
                            correct_block_1++;
                        }
                        else if (text_write_gander.getString() == "gay") {
                            music.stop();
                            kol = 2;
                            music3.play();
                        }
                        else if (text_write_gander.getString() == "sashka") {
                            music.stop();
                            kol = 4;
                            music2.play();
                        }
                        else {
                            text_check_gendar.setFillColor(sf::Color::Red);
                            text_check_gendar.setString("That's no right(man/woman)");
                            correct_block_1 = 0;
                        }
                        //2
                        if (intValue > 0 && intValue < 150) {
                            text_check_age.setFillColor(sf::Color(0, 100, 0));
                            text_check_age.setString("That's right");
                            correct_block_2++;
                        }
                        else {
                            text_check_age.setFillColor(sf::Color::Red);
                            text_check_age.setString("That's no right");
                            correct_block_2 = 0;
                        }

                        //3
                        if (text_write_education.getString() == "higher" || text_write_education.getString() == "average" || text_write_education.getString() == "initial") {
                            text_check_education.setFillColor(sf::Color(0, 100, 0));
                            text_check_education.setString("That's right");
                            correct_block_3++;
                        }
                        else {
                            text_check_education.setFillColor(sf::Color::Red);
                            text_check_education.setString("That's no right(higher/average/initial)");
                            correct_block_3 = 0;
                        }
                        //4
                        if (text_write_vopros.getString() == "yes" || text_write_vopros.getString() == "no") {
                            text_check_vopros.setFillColor(sf::Color(0, 100, 0));
                            text_check_vopros.setString("That's right");
                            correct_block_4++;
                        }
                        else {
                            text_check_vopros.setFillColor(sf::Color::Red);
                            text_check_vopros.setString("That's no right(yes/no)");
                            correct_block_4 = 0;
                        }
                        if (correct_block_1 > 0 && correct_block_2 > 0 && correct_block_3 > 0 && correct_block_4 > 0) {
                            create_list(intValue, text_write_education.getString(), text_write_gander.getString(), text_write_vopros.getString());
                            window.clear();
                            menu_3(window, music);
                        }
                    }
                }
            }
        }
        if (kol == 0) {

            window.clear();
            window.draw(img_menu2);
            window.draw(ship_R);
            window.draw(ship_L);
            window.draw(rectangle_education);
            window.draw(text_education);
            window.draw(text_write_education);
            window.draw(text_check_education);
            window.draw(text_age);
            window.draw(rectangle_gendar);
            window.draw(text_gander);
            window.draw(text_write_gander);
            window.draw(rectangle_age);
            window.draw(text_write_age);
            window.draw(text_check_gendar);
            window.draw(text_check_age);
            window.draw(button_back);
            window.draw(text_button_back);
            window.draw(rectangle_vopros);
            window.draw(text_vopros);
            window.draw(text_write_vopros);
            window.draw(text_check_vopros);
            window.draw(button_next);
            window.draw(text_next);
            window.display();
        }
        else if (kol == 2) {
            window.clear(sf::Color::White);
            window.draw(textStas);
            window.draw(sprite);
            window.display();
        }
        else if (kol == 4) {

            window.clear(sf::Color::White);
            window.draw(spriteSa);
            window.display();

        }
    }
}

void menu_1(sf::RenderWindow& window, sf::Music& music) {

    sf::Texture fon;
    fon.loadFromFile("foto\\menu_1.jpg");

    sf::Sprite sprite(fon);
    sprite.setPosition(-200, -100);

    sf::Music music2;
    music2.openFromFile("music\\xomick.wav");

    sf::Music music3;
    music3.openFromFile("music\\gy.wav");


    sf::RectangleShape button_start(sf::Vector2f(490, 100));
    button_start.setPosition(690, 350);
    button_start.setFillColor(sf::Color::Transparent); // Прозрачный цвет заливки
    button_start.setOutlineColor(sf::Color::Black); // Черный цвет контура
    button_start.setOutlineThickness(2); // Толщина контура


    sf::RectangleShape button_result(sf::Vector2f(490, 100));
    button_result.setPosition(690, 550);
    button_result.setFillColor(sf::Color::Transparent);
    button_result.setOutlineColor(sf::Color::Black);
    button_result.setOutlineThickness(2);

    sf::RectangleShape button_end(sf::Vector2f(490, 100));
    button_end.setPosition(690, 750);
    button_end.setFillColor(sf::Color::Transparent);
    button_end.setOutlineColor(sf::Color::Black);
    button_end.setOutlineThickness(2);

    sf::Font font;
    font.loadFromFile("shriftu\\pirat.otf");






    sf::Text text_button_start(L"Пройти анкету", font, 65);
    text_button_start.setPosition(700, 355);
    text_button_start.setFillColor(sf::Color::Black);

    sf::Text text_button_result(L"Результаты", font, 65);
    text_button_result.setPosition(750, 555);
    text_button_result.setFillColor(sf::Color::Black);

    sf::Text text_button_end(L"Выход", font, 65);
    text_button_end.setPosition(830, 755);
    text_button_end.setFillColor(sf::Color::Black);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                window.close();
            }

            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    if (button_end.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                        window.close();
                    }
                }
            }

            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    if (button_result.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                        menu_4(window, music);
                    }
                }
            }
            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    if (button_start.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                        menu_2(window, music, music2, music3);
                    }
                }
            }


        }

        window.clear();
        window.draw(sprite);
        window.draw(button_start);
        window.draw(button_result);
        window.draw(text_button_result);
        window.draw(button_end);
        window.draw(text_button_end);
        window.draw(text_button_start);
        window.display();
    }
}

void menu_3(sf::RenderWindow& window, sf::Music& music) {

    //блоки

    sf::RectangleShape button_menu(sf::Vector2f(200, 65));
    button_menu.setPosition(1420, 985);
    button_menu.setFillColor(sf::Color::Transparent);

    //шрифт и картинки
    sf::Font font;
    font.loadFromFile("shriftu\\Shrift.ttf");

    sf::Texture fon3;
    fon3.loadFromFile("foto\\menu3.jpg");
    sf::Sprite img_menu3(fon3);
    img_menu3.setPosition(-330, -350);
    img_menu3.setScale(0.80, 0.80); // Уменьшение 

    //текст

    sf::Text text_button_menu(L"МЕНЮ", font, 65);
    text_button_menu.setPosition(1420, 980);
    text_button_menu.setFillColor(sf::Color::White);


    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                window.close();
            }
            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    if (button_menu.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                        menu_1(window, music);
                    }
                }
            }
        }

        window.clear();
        window.draw(img_menu3);
        window.draw(button_menu);
        window.draw(text_button_menu);
        window.display();
    }

}

void menu_4(sf::RenderWindow& window, sf::Music& music) {


    sf::Font font;
    font.loadFromFile("shriftu\\Shrift.ttf");

    sf::Texture fon4;
    fon4.loadFromFile("foto\\menu4.jpg");
    sf::Sprite img_menu4(fon4);
    img_menu4.setPosition(0, 0);

    sf::Texture Tabl;
    Tabl.loadFromFile("foto\\tabl.png");
    sf::Sprite img_tabl(Tabl);
    img_tabl.setPosition(1400, 750);
    img_tabl.setScale(2.30, 2.30);

    sf::RectangleShape button_menu(sf::Vector2f(200, 70));
    button_menu.setPosition(1540, 780);
    button_menu.setFillColor(sf::Color::Transparent);

    sf::Text text_button_menu(L"МЕНЮ", font, 60);
    text_button_menu.setPosition(1550, 780);
    text_button_menu.setFillColor(sf::Color(255, 235, 205));

    sf::RectangleShape button_rest(sf::Vector2f(220, 70));
    button_rest.setPosition(1540, 880);
    button_rest.setFillColor(sf::Color::Transparent);

    sf::Text text_button_rest(L"ДРУГИЕ", font, 60);
    text_button_rest.setPosition(1545, 870);
    text_button_rest.setFillColor(sf::Color(255, 235, 205));

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                window.close();
            }
            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    if (button_menu.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                        menu_1(window, music);
                    }
                }
            }
            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    if (button_rest.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                        menu_5(window, music);
                    }
                }
            }
        }


        window.clear();
        window.draw(img_menu4);
        window.draw(img_tabl);
        window.draw(button_menu);
        window.draw(text_button_menu);
        window.draw(button_rest);
        window.draw(text_button_rest);
        window.display();
    }
}

void menu_5(sf::RenderWindow& window, sf::Music& music) {

    //блоки



    //шрифт и картинки
    sf::Font font;
    font.loadFromFile("shriftu\\Shrift.ttf");



    //текст

    sf::Text text_button_menu(L"Технические шоколадки", font, 75);
    text_button_menu.setPosition(500, 500);
    text_button_menu.setFillColor(sf::Color::White);


    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                window.close();
            }

        }

        window.clear();

        window.draw(text_button_menu);
        window.display();
    }

}