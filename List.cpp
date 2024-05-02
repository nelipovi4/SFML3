#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <string>
#include <fstream>
#include <windows.h> 
#include "man_woman.h"
#include "menu_and_list.h"
#include <vector>



extern List* u;

extern sf::Music music;
extern sf::RenderWindow window;


void write_file(int age, std::string education, std::string gender, std::string answer) {
    std::ofstream write;
    write.open("data.txt", std::ios::app);

    write << gender << " ";
    write << age << " ";
    write << education << " ";
    write << answer << "\n";
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
    while (file >> data.gender >> data.age >> data.education >> data.answer) {
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