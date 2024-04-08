#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <string>
#include <fstream>
#include <windows.h> 
#include "man_woman.h"
#include "menu_and_list.h"


List* u = NULL;
sf::Music music;
sf::RenderWindow window(sf::VideoMode(1920, 1080), "no HUESOS", sf::Style::Fullscreen);

int main()
{
    music.openFromFile("music\\kahoot2.wav");
    music.play();
    music.setLoop(true);
    load_file();
    menu_main();
}