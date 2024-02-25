#include <SFML/Graphics.hpp>
#include <iostream>
#include <locale.h>
#include "TextBox.h"
#include "Talk.h"
#include "Character.h"
#include "Enemy.h"
#include "Gemi.h"
#include "Game.h"
#include "TextWithOutline.h"
#include "AbstractMenu.h"
//#include "Collision.h"

int main() {

    Menu menu;
    sf::Font font;
    menu.setFont(font);
    menu.run();
    return 0;
}

