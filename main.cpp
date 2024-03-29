#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <string>
#include <fstream>
#include <windows.h> 

#include "man_woman.h"

//массив


List* u = NULL;
sf::Music music;
sf::RenderWindow window(sf::VideoMode(1920, 1080), "no HUESOS", sf::Style::Fullscreen);

void write_file(int age, std::string education, std::string gender, std::string answer) {
    std::ofstream write;
    write.open("data.txt", std::ios::app);

    write << gender << " ";
    write << age << " ";
    write << education << " ";
    write << answer <<"\n";
    write.close();
}



void create_list(int age, std::string education, std::string gender, std::string answer) {
    write_file(age, education, gender, answer);
    Data data = { age, education, gender, answer };
    List* x = u;
    if (x == NULL) {
        u = new List{ data, NULL };
    }
    else {
        while (x->next) {
            x = x->next;
        }
        x->next = new List{ data, NULL };
    }
}

void load_file() {
    std::ifstream file("data.txt");

    Data data;
    while (file >> data.gender >> data.age >> data.education  >> data.answer) {
        List* x = u;
        if (x == NULL) {
            u = new List{ data, NULL };
        }
        else {
            while (x->next) {
                x = x->next;
            }
            x->next = new List{ data, NULL };
        }
    }

    file.close();
}

void menu_choice();
void menu_anketa(sf::Music& music2, sf::Music& music3, sf::Music& music4, sf::Music& music6);
void menu_main();
void menu_great();
void menu_result();
void menu_m();
void menu_w();
void menu_settings();
void menu_admin();

int main()
{
    music.openFromFile("music\\kahoot2.wav");
    music.play();
    music.setLoop(true);
    load_file();
    menu_main();
}


void menu_anketa(sf::Music& music2, sf::Music& music3, sf::Music& music4, sf::Music& music6) {
    int kol = 0;
    List* p = u;
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

    sf::Texture texture5;
    texture5.loadFromFile("foto\\Zhe.jpg");
    sf::Sprite spriteZ(texture5);
    spriteZ.setPosition(400, 400);

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

    sf::Texture shipMat;
    shipMat.loadFromFile("foto\\mat.jpg");
    sf::Sprite ship(shipMat);
    ship.setPosition(200, 0);
    ship.setScale(0.90, 0.90); // Уменьшение 

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
            //закрытие программы на кнопку
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                window.close();
            }
            //запрет на области
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

            //написание и пределы по буквам
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
                        menu_main();
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
                        else if (text_write_gander.getString() == "PIVA") {
                            music.stop();
                            kol = 5;
                            music4.play();
                        }
                        else if (text_write_gander.getString() == "mat") {
                            music.stop();
                            kol = 6;
                            music6.play();
                            Sleep(11000);
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
                            menu_great();
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
        else if (kol == 5) {

            window.clear(sf::Color::White);
            window.draw(spriteZ);
            window.display();
        }
        else if (kol == 6) {
            window.clear(sf::Color::White);
            window.draw(ship);
            window.display();

        }
         
    }
}

void menu_main() {

    sf::Texture fon;
    fon.loadFromFile("foto\\menu_1.jpg");

    sf::Sprite sprite(fon);
    sprite.setPosition(-200, -100);

    sf::Music music2;
    music2.openFromFile("music\\xomick.wav");

    sf::Music music3;
    music3.openFromFile("music\\gy.wav");

    sf::Music music4;
    music4.openFromFile("music\\Zhe.wav");

    sf::Music music6;
    music6.openFromFile("music\\mat.wav");

    //блоки
    sf::RectangleShape button_start(sf::Vector2f(490, 100));
    button_start.setPosition(690, 350);
    button_start.setFillColor(sf::Color::Transparent); // Прозрачный цвет заливки
    button_start.setOutlineColor(sf::Color::Black); // Черный цвет контура
    button_start.setOutlineThickness(2); // Толщина контура


    sf::RectangleShape button_settings(sf::Vector2f(490, 100));
    button_settings.setPosition(690, 550);
    button_settings.setFillColor(sf::Color::Transparent);
    button_settings.setOutlineColor(sf::Color::Black);
    button_settings.setOutlineThickness(2);

    sf::RectangleShape button_end(sf::Vector2f(490, 100));
    button_end.setPosition(690, 750);
    button_end.setFillColor(sf::Color::Transparent);
    button_end.setOutlineColor(sf::Color::Black);
    button_end.setOutlineThickness(2);

    //шрифт
    sf::Font font;
    font.loadFromFile("shriftu\\pirat.otf");

    //текст
    sf::Text text_button_start(L"Пройти анкету", font, 65);
    text_button_start.setPosition(700, 355);
    text_button_start.setFillColor(sf::Color::Black);

    sf::Text text_button_settings(L"Настройки", font, 65);
    text_button_settings.setPosition(770, 555);
    text_button_settings.setFillColor(sf::Color::Black);

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
                    if (button_settings.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                        menu_settings();
                    }
                }
            }
            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    if (button_start.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                        menu_anketa(music2, music3, music4, music6);
                    }
                }
            }


        }

        window.clear();
        window.draw(sprite);
        window.draw(button_start);
        window.draw(button_settings);
        window.draw(text_button_settings);
        window.draw(button_end);
        window.draw(text_button_end);
        window.draw(text_button_start);
        window.display();
    }
}

void menu_great() {

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
                        menu_main();
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

void menu_result() {
    //шрифт и картинки
    sf::Font font;
    font.loadFromFile("shriftu\\Shrift.ttf");

    sf::Texture fon4;
    fon4.loadFromFile("foto\\menu4.2.jpg");
    sf::Sprite img_menu4(fon4);
    img_menu4.setPosition(0, 0);

    sf::Texture Tabl;
    Tabl.loadFromFile("foto\\tabl.png");
    sf::Sprite img_tabl(Tabl);
    img_tabl.setPosition(1400, 750);
    img_tabl.setScale(2.30, 2.30);

    //блоки
    sf::RectangleShape button_menu(sf::Vector2f(200, 70));
    button_menu.setPosition(1540, 780);
    button_menu.setFillColor(sf::Color::Transparent);

    sf::Text text_button_menu(L"МЕНЮ", font, 60);
    text_button_menu.setPosition(1550, 780);
    text_button_menu.setFillColor(sf::Color(255, 235, 205));

    sf::RectangleShape button_rest(sf::Vector2f(220, 70));
    button_rest.setPosition(1540, 880);
    button_rest.setFillColor(sf::Color::Transparent);

    //текст
    sf::Text text_button_rest(L"ДРУГИЕ", font, 60);
    text_button_rest.setPosition(1545, 870);
    text_button_rest.setFillColor(sf::Color(255, 235, 205));

    //счётчики
    sf::Text num_man_scarier40_higher_yes("", font, 60);
    num_man_scarier40_higher_yes.setPosition(505, 555);
    num_man_scarier40_higher_yes.setFillColor(sf::Color(255, 235, 205));

    sf::Text num_women_younger30_average_no("", font, 60);
    num_women_younger30_average_no.setPosition(1050, 555);
    num_women_younger30_average_no.setFillColor(sf::Color(255, 235, 205));

    sf::Text num_man_younger25_initial_yes("", font, 60);
    num_man_younger25_initial_yes.setPosition(1630, 555);
    num_man_younger25_initial_yes.setFillColor(sf::Color(255, 235, 205));

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                window.close();
            }
            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    if (button_menu.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                        menu_main();
                    }
                }
            }
            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    if (button_rest.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                        menu_choice();
                    }
                }
            }
        }
        //цифры для счёта
        std::string str_1_card = std::to_string(Man_scarier40_higher_yes());
        std::string str_2_card = std::to_string(Women_younger30_average_no());
        std::string str_3_card = std::to_string(Man_younger25_initial_yes());
        num_man_scarier40_higher_yes.setString(str_1_card);
        num_women_younger30_average_no.setString(str_2_card);
        num_man_younger25_initial_yes.setString(str_3_card);

        window.clear();
        window.draw(img_menu4);
        window.draw(img_tabl);
        window.draw(button_menu);
        window.draw(text_button_menu);
        window.draw(button_rest);
        window.draw(text_button_rest);
        window.draw(num_man_scarier40_higher_yes);
        window.draw(num_women_younger30_average_no);
        window.draw(num_man_younger25_initial_yes);
        window.display();
    }
}

void menu_choice() {

    //блоки
    sf::RectangleShape button_woman(sf::Vector2f(265, 100));
    button_woman.setPosition(350, 810);
    button_woman.setFillColor(sf::Color::Transparent);

    sf::RectangleShape button_man(sf::Vector2f(150, 90));
    button_man.setPosition(1440, 850);
    button_man.setFillColor(sf::Color::Transparent);

    //шрифт и картинки
    sf::Font font;
    font.loadFromFile("shriftu\\Shrift.ttf");

    sf::Texture foto_m;
    foto_m.loadFromFile("foto\\man.png");
    sf::Sprite img_menu_man(foto_m);
    img_menu_man.setPosition(1300, 400);
    img_menu_man.setScale(0.40, 0.40); // Уменьшение 

    sf::Texture foto_w;
    foto_w.loadFromFile("foto\\woman.png");
    sf::Sprite img_menu_woman(foto_w);
    img_menu_woman.setPosition(300, 370);
    img_menu_woman.setScale(0.55, 0.55); // Уменьшение 
    //текст

    sf::Text text_button_man(L"man", font, 75);
    text_button_man.setPosition(1440, 840);
    text_button_man.setFillColor(sf::Color::White);

    sf::Text text_button_woman(L"woman", font, 75);
    text_button_woman.setPosition(350, 810);
    text_button_woman.setFillColor(sf::Color::White);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                window.close();
            }
            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    if (button_man.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                        menu_m();
                    }
                    if (button_woman.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                        menu_w();
                    }
                }
            }
        }

        window.clear(sf::Color(0,0,0));
        window.draw(button_woman);
        window.draw(button_man);
        window.draw(img_menu_man);
        window.draw(img_menu_woman);
        window.draw(text_button_man);
        window.draw(text_button_woman);
        window.display();
    }

}

void menu_m() {

    //блоки



    //шрифт и картинки
    sf::Font font;
    font.loadFromFile("shriftu\\Shrift.ttf");

    sf::Texture fon;
    fon.loadFromFile("foto\\м.jpg");
    sf::Sprite img_menu_m(fon);


    //текст

    sf::Text text_button_menu(L"", font, 75);
    text_button_menu.setPosition(500, 500);
    text_button_menu.setFillColor(sf::Color::White);

    sf::Text  num_man_scarier50_averaeg_yes("", font, 50);
    num_man_scarier50_averaeg_yes.setPosition(678, 385);
    num_man_scarier50_averaeg_yes.setFillColor(sf::Color(255, 235, 205));

    sf::Text num_man_younger25_initial_no("", font, 50);
    num_man_younger25_initial_no.setPosition(400, 385);
    num_man_younger25_initial_no.setFillColor(sf::Color(255, 235, 205)); 

    sf::Text num_man_scarier25_initial_yes("", font, 50);
    num_man_scarier25_initial_yes.setPosition(412, 873);
    num_man_scarier25_initial_yes.setFillColor(sf::Color(255, 235, 205));

    sf::Text num_man_scarier50_average_no("", font, 50);
    num_man_scarier50_average_no.setPosition(992, 388);
    num_man_scarier50_average_no.setFillColor(sf::Color(255, 235, 205));

    sf::Text num_man_scarier25_initial_no("", font, 50);
    num_man_scarier25_initial_no.setPosition(735, 873);
    num_man_scarier25_initial_no.setFillColor(sf::Color(255, 235, 205));

    sf::Text num_man_younger50_average_no("", font, 50);
    num_man_younger50_average_no.setPosition(1310, 385);
    num_man_younger50_average_no.setFillColor(sf::Color(255, 235, 205));

    sf::Text num_man_younger50_average_yes("", font, 50);
    num_man_younger50_average_yes.setPosition(1622, 385);
    num_man_younger50_average_yes.setFillColor(sf::Color(255, 235, 205));

    sf::Text num_man_scarier40_higher_no("", font, 50);
    num_man_scarier40_higher_no.setPosition(1040, 870);
    num_man_scarier40_higher_no.setFillColor(sf::Color(255, 235, 205));

    sf::Text num_man_younger40_higher_yes("", font, 50);
    num_man_younger40_higher_yes.setPosition(1340, 870);
    num_man_younger40_higher_yes.setFillColor(sf::Color(255, 235, 205));

    sf::Text num_man_younger40_higher_no("", font, 50);
    num_man_younger40_higher_no.setPosition(1620, 872);
    num_man_younger40_higher_no.setFillColor(sf::Color(255, 235, 205));

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                window.close();
            }

        }
        std::string str_scarier50_average_no = std::to_string(Man_scarier50_average_no());
        std::string str_scarier25_initial_yes = std::to_string(Man_scarier25_initial_yes());
        std::string str_scarier50_averaeg_yes = std::to_string(Man_scarier50_averaeg_yes());
        std::string str_younger25_initial_no = std::to_string(Man_younger25_initial_no());
        std::string str_scarier25_initial_no = std::to_string(Man_scarier25_initial_no());
        std::string str_younger50_average_no = std::to_string(Man_younger50_average_no());
        std::string str_younger50_average_yes = std::to_string(Man_younger50_average_yes());
        std::string str_scarier40_higher_no = std::to_string(Man_scarier40_higher_no());
        std::string str_younger40_higher_yes = std::to_string(Man_younger40_higher_yes());
        std::string str_younger40_higher_no = std::to_string(Man_younger40_higher_no());

        num_man_scarier50_average_no.setString(str_scarier50_average_no);
        num_man_scarier25_initial_yes.setString(str_scarier25_initial_yes);
        num_man_younger25_initial_no.setString(str_younger25_initial_no);
        num_man_scarier50_averaeg_yes.setString(str_scarier50_averaeg_yes);
        num_man_scarier25_initial_no.setString(str_scarier25_initial_no);
        num_man_younger50_average_no.setString(str_younger50_average_no);
        num_man_younger50_average_yes.setString(str_younger50_average_yes);
        num_man_scarier40_higher_no.setString(str_scarier40_higher_no);
        num_man_younger40_higher_yes.setString(str_younger40_higher_yes);
        num_man_younger40_higher_no.setString(str_younger40_higher_no);

        window.clear();
        window.draw(img_menu_m);
        window.draw(text_button_menu);
        window.draw(num_man_scarier50_average_no);
        window.draw(num_man_scarier25_initial_yes);
        window.draw(num_man_younger25_initial_no);
        window.draw(num_man_scarier50_averaeg_yes);
        window.draw(num_man_scarier25_initial_no);
        window.draw(num_man_younger50_average_no);
        window.draw(num_man_younger50_average_yes);
        window.draw(num_man_scarier40_higher_no);
        window.draw(num_man_younger40_higher_yes);
        window.draw(num_man_younger40_higher_no);
        window.display();
    }

}

void menu_w() {

    //блоки



    //шрифт и картинки
    sf::Font font;
    font.loadFromFile("shriftu\\Shrift.ttf");

    sf::Texture fon;
    fon.loadFromFile("foto\\ж.jpg");
    sf::Sprite img_menu_w(fon);


    //текст

    sf::Text text_button_menu(L"", font, 75);
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
        window.draw(img_menu_w);
        window.draw(text_button_menu);
        window.display();
    }

}

void menu_settings() {

    //блоки
    sf::RectangleShape button_admin(sf::Vector2f(490, 100));
    button_admin.setPosition(690, 150);
    button_admin.setFillColor(sf::Color::Transparent); // Прозрачный цвет заливки
    button_admin.setOutlineColor(sf::Color::Black); // Черный цвет контура
    button_admin.setOutlineThickness(2); // Толщина контура


    sf::RectangleShape button_music(sf::Vector2f(490, 100));
    button_music.setPosition(690, 350);
    button_music.setFillColor(sf::Color::Transparent);
    button_music.setOutlineColor(sf::Color::Black);
    button_music.setOutlineThickness(2);

    sf::RectangleShape button_app(sf::Vector2f(490, 100));
    button_app.setPosition(690, 550);
    button_app.setFillColor(sf::Color::Transparent);
    button_app.setOutlineColor(sf::Color::Black);
    button_app.setOutlineThickness(2);

    sf::RectangleShape button_end(sf::Vector2f(490, 100));
    button_end.setPosition(690, 750);
    button_end.setFillColor(sf::Color::Transparent);
    button_end.setOutlineColor(sf::Color::Black);
    button_end.setOutlineThickness(2);

    //шрифт и картинки
    sf::Font font;
    font.loadFromFile("shriftu\\pirat.otf");

    sf::Texture fon;
    fon.loadFromFile("foto\\menu_na.jpg");
    sf::Sprite img_menu(fon);
    img_menu.setPosition(0, 0);
    img_menu.setScale(1.30, 1.30);

    //текст

    sf::Text text_button_admin(L"ДЛЯ АДМИНА", font, 65);
    text_button_admin.setPosition(755, 155);
    text_button_admin.setFillColor(sf::Color::Black);

    sf::Text text_button_music(L"МУЗЫКА", font, 65);
    text_button_music.setPosition(820, 355);
    text_button_music.setFillColor(sf::Color::Black);

    sf::Text text_button_app(L"О ПРИЛОЖЕНИИ", font, 65);
    text_button_app.setPosition(710, 555);
    text_button_app.setFillColor(sf::Color::Black);

    sf::Text text_button_end(L"НАЗАД", font, 65);
    text_button_end.setPosition(840, 755);
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
                        menu_main();
                    }
                    if (button_admin.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                        menu_admin();
                    }
                }
            }
        }

        window.clear();
        window.draw(img_menu);
        window.draw(button_admin);
        window.draw(button_music);
        window.draw(text_button_music);
        window.draw(button_end);
        window.draw(text_button_end);
        window.draw(text_button_admin);
        window.draw(button_app);
        window.draw(text_button_app);
        window.display();
    }

}

void menu_admin() {


    //блоки

    sf::RectangleShape button_send(sf::Vector2f(490, 100));
    button_send.setPosition(690, 550);
    button_send.setFillColor(sf::Color::Transparent);
    button_send.setOutlineColor(sf::Color::Black);
    button_send.setOutlineThickness(2);

    sf::RectangleShape button_end(sf::Vector2f(490, 100));
    button_end.setPosition(690, 750);
    button_end.setFillColor(sf::Color::Transparent);
    button_end.setOutlineColor(sf::Color::Black);
    button_end.setOutlineThickness(2);

    //шрифт и картинки
    sf::Font font;
    font.loadFromFile("shriftu\\pirat.otf");

    sf::Texture fon;
    fon.loadFromFile("foto\\menu_na.jpg");
    sf::Sprite img_menu(fon);
    img_menu.setPosition(0, 0);
    img_menu.setScale(1.30, 1.30);

    //текст
    sf::Text text_button_start(L"Вход в аккаунт", font, 65);
    text_button_start.setPosition(700, 355);
    text_button_start.setFillColor(sf::Color::Black);

    sf::Text text_button_settings(L"Отправить", font, 65);
    text_button_settings.setPosition(770, 555);
    text_button_settings.setFillColor(sf::Color::Black);

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
                    
                }
            }
        }

        window.clear();
        window.draw(img_menu);
        window.draw(button_send);
        window.draw(button_send);
        window.draw(text_button_settings);
        window.draw(button_end);
        window.draw(text_button_end);
        window.draw(text_button_start);
        window.display();
    }
}
