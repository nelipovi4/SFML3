#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <string>
#include <fstream>
#include <windows.h> 
#include "man_woman.h"
#include "menu_and_list.h"

extern List* u;

//основное задание
int Man_younger25_initial_yes() {
    int kol = 0;
    List* p = u;
    while (p)
    {
        if (p->d.age < 25 && p->d.gender == "man" && p->d.education == "initial" && p->d.answer == "yes") {
            kol++;
        }
        p = p->next;
    }
    return kol;
}

int Man_scarier40_higher_yes() {
    int kol = 0;
    List* p = u;
    while (p)
    {
        if (p->d.age > 40 && p->d.gender == "man" && p->d.education == "higher" && p->d.answer == "yes") {
            kol++;
        }
        p = p->next;
    }
    return kol;
}

int Women_younger30_average_no() {
    int kol = 0;
    List* p = u;
    while (p)
    {
        if (p->d.age < 30 && p->d.gender == "woman" && p->d.education == "average" && p->d.answer == "no") {
            kol++;
        }
        p = p->next;
    }
    return kol;
}

//доп. мужская часть
int Man_scarier50_averaeg_yes() {
    int kol = 0;
    List* p = u;
    while (p)
    {
        if (p->d.age > 51 && p->d.gender == "man" && p->d.education == "average" && p->d.answer == "yes") {
            kol++;
        }
        p = p->next;
    }
    return kol;
}

int Man_scarier50_average_no() {
    int kol = 0;
    List* p = u;
    while (p)
    {
        if (p->d.age > 51 && p->d.gender == "man" && p->d.education == "average" && p->d.answer == "no") {
            kol++;
        }
        p = p->next;
    }
    return kol;
}

int Man_younger50_average_no() {
    int kol = 0;
    List* p = u;
    while (p)
    {
        if (p->d.age < 50 && p->d.gender == "man" && p->d.education == "younger" && p->d.answer == "no") {
            kol++;
        }
        p = p->next;
    }
    return kol;
}

int Man_younger50_average_yes() {
    int kol = 0;
    List* p = u;
    while (p)
    {
        if (p->d.age < 50 && p->d.gender == "man" && p->d.education == "younger" && p->d.answer == "yes") {
            kol++;
        }
        p = p->next;
    }
    return kol;
}


int Man_younger25_initial_no() {
    int kol = 0;
    List* p = u;
    while (p)
    {
        if (p->d.age < 26 && p->d.gender == "man" && p->d.education == "initial" && p->d.answer == "no") {
            kol++;
        }
        p = p->next;
    }
    return kol;
}

int Man_scarier25_initial_yes() {
    int kol = 0;
    List* p = u;
    while (p)
    {
        if (p->d.age > 25 && p->d.gender == "man" && p->d.education == "initial" && p->d.answer == "yes") {
            kol++;
        }
        p = p->next;
    }
    return kol;
}

int Man_scarier25_initial_no() {
    int kol = 0;
    List* p = u;
    while (p)
    {
        if (p->d.age > 50 && p->d.gender == "man" && p->d.education == "initial" && p->d.answer == "no") {
            kol++;
        }
        p = p->next;
    }
    return kol;
}


int Man_scarier40_higher_no() {
    int kol = 0;
    List* p = u;
    while (p)
    {
        if (p->d.age > 40 && p->d.gender == "man" && p->d.education == "higher" && p->d.answer == "no") {
            kol++;
        }
        p = p->next;
    }
    return kol;
}

int Man_younger40_higher_yes() {
    int kol = 0;
    List* p = u;
    while (p)
    {
        if (p->d.age <= 40 && p->d.gender == "man" && p->d.education == "younger" && p->d.answer == "yes") {
            kol++;
        }
        p = p->next;
    }
    return kol;
}

int Man_younger40_higher_no() {
    int kol = 0;
    List* p = u;
    while (p)
    {
        if (p->d.age <= 40 && p->d.gender == "man" && p->d.education == "younger" && p->d.answer == "no") {
            kol++;
        }
        p = p->next;
    }
    return kol;
}

//доп. женская часть

int Women_younger50_higher_yes() {
    int kol = 0;
    List* p = u;
    while (p)
    {
        if (p->d.age <- 50 && p->d.gender == "woman" && p->d.education == "higher" && p->d.answer == "yes") {
            kol++;
        }
        p = p->next;
    }
    return kol;
}

int Women_younger50_higher_no() {
    int kol = 0;
    List* p = u;
    while (p)
    {
        if (p->d.age <= 50 && p->d.gender == "woman" && p->d.education == "higher" && p->d.answer == "no") {
            kol++;
        }
        p = p->next;
    }
    return kol;
}

int Women_scarier50_higher_yes() {
    int kol = 0;
    List* p = u;
    while (p)
    {
        if (p->d.age > 50 && p->d.gender == "woman" && p->d.education == "higher" && p->d.answer == "yes") {
            kol++;
        }
        p = p->next;
    }
    return kol;
}

int Women_scarier50_higher_no() {
    int kol = 0;
    List* p = u;
    while (p)
    {
        if (p->d.age > 50 && p->d.gender == "woman" && p->d.education == "higher" && p->d.answer == "no") {
            kol++;
        }
        p = p->next;
    }
    return kol;
}


int Women_younger25_average_yes() {
    int kol = 0;
    List* p = u;
    while (p)
    {
        if (p->d.age < 25 && p->d.gender == "woman" && p->d.education == "average" && p->d.answer == "yes") {
            kol++;
        }
        p = p->next;
    }
    return kol;
}

int Women_scarier30_average_yes() {
    int kol = 0;
    List* p = u;
    while (p)
    {
        if (p->d.age >= 30 && p->d.gender == "woman" && p->d.education == "average" && p->d.answer == "yes") {
            kol++;
        }
        p = p->next;
    }
    return kol;
}

int Women_scarier30_average_no() {
    int kol = 0;
    List* p = u;
    while (p)
    {
        if (p->d.age >= 30 && p->d.gender == "woman" && p->d.education == "average" && p->d.answer == "no") {
            kol++;
        }
        p = p->next;
    }
    return kol;
}


int Women_younger50_initial_yes() {
    int kol = 0;
    List* p = u;
    while (p)
    {
        if (p->d.age < -50 && p->d.gender == "woman" && p->d.education == "initial" && p->d.answer == "yes") {
            kol++;
        }
        p = p->next;
    }
    return kol;
}

int Women_younger50_initial_no() {
    int kol = 0;
    List* p = u;
    while (p)
    {
        if (p->d.age <= 50 && p->d.gender == "woman" && p->d.education == "initial" && p->d.answer == "no") {
            kol++;
        }
        p = p->next;
    }
    return kol;
}

int Women_scarier50_initial_yes() {
    int kol = 0;
    List* p = u;
    while (p)
    {
        if (p->d.age > 50 && p->d.gender == "woman" && p->d.education == "initial" && p->d.answer == "yes") {
            kol++;
        }
        p = p->next;
    }
    return kol;
}

int Women_scarier50_initial_no() {
    int kol = 0;
    List* p = u;
    while (p)
    {
        if (p->d.age > 50 && p->d.gender == "woman" && p->d.education == "initial" && p->d.answer == "no") {
            kol++;
        }
        p = p->next;
    }
    return kol;
}