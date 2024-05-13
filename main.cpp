#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <string>
#include <fstream>
#include "man_woman.h"
#include "menu_and_list.h"
#include <vector>

List* u = NULL;
sf::Music music;
sf::RenderWindow window(sf::VideoMode(1920, 1080), "Hello World", sf::Style::Fullscreen);

int main()
{
    //взятие музыки 
    music.openFromFile("music\\kahoot2.wav");

    music.play();

    //бесконечное повторение
    music.setLoop(true);

    load_file();
    menu_main();
}