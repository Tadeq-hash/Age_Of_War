#include <iostream>
#include "MainMenu.h"


int main()
{

    std::cout << "Age of War\n\nCreated by:\n@Tadeusz Bugalski\n@Wojciech Ciesiolka\n";

    //RENDERING MAIN MENU WINDOW
    MainMenu menu;

    //MENU LOOP
    while (menu.getWindowIsOpen())
    {
        //Updating menu
        menu.update();

        //Render menu
        menu.render();


        //GIT HUB UPLOADED TEST
    }
}
