#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
class AbstractMenu {
public:
    virtual void run() = 0;
    virtual void setFont(const sf::Font& newFont) = 0;
    virtual ~AbstractMenu() = default;
};

class Menu : public AbstractMenu {
public:
    Menu() : window(sf::VideoMode(1280, 960), "SFML Menu") {}

    void run() override {
        try {
            setup();
            while (window.isOpen()) {
                handleEvents();
                render();
            }
        }
        catch (const std::exception& e) {
            std::cerr << "Exception caught: " << e.what() << std::endl;
        }
        catch (...) {
            std::cerr << "An unknown exception occurred." << std::endl;
        }
    }

    void setFont(const sf::Font& newFont) override {
        font = newFont;
        for (size_t i = 0; i < 4; ++i) {
            buttonTexts[i].setFont(font);
        }
        gameTitle.setFont(font);
    }

private:
    sf::RenderWindow window;
    int selectedOption = 0;
    sf::Font font;
    sf::RectangleShape buttons[4];
    sf::Text buttonTexts[4];
    sf::Texture backgroundTexture;
    sf::Texture anamapTexture;
    sf::Sprite backgroundImage;
    sf::Text gameTitle;

    void setup() {
        if (!loadFontAndTextures()) {
            std::cerr << "Failed to load font or textures!" << std::endl;
            window.close();
        }

        createBackground();
        createButtons();
        createGameTitle();

        setFont(font);
    }

    bool loadFontAndTextures() {
        try {
            if (!font.loadFromFile("Unitblock.ttf")) {
                throw std::runtime_error("Failed to load font!");
            }

            if (!backgroundTexture.loadFromFile("menufoto.png")) {
                throw std::runtime_error("Failed to load background image!");
            }

            if (!anamapTexture.loadFromFile("ana_harita.jpeg")) {
                throw std::runtime_error("Failed to load anamap image!");
            }

            return true;
        }
        catch (const std::exception& e) {
            std::cerr << "Exception caught in loadFontAndTextures: " << e.what() << std::endl;
            return false;
        }
    }

    void createBackground() {
        backgroundImage.setTexture(backgroundTexture);
    }

    void createButtons() {
        std::vector<std::string> optionStrings = { "START", "CONTROLS", "INFORMATION", "CLOSE" };

        for (size_t i = 0; i < 4; ++i) {
            buttons[i].setSize(sf::Vector2f(200, 50));
            buttons[i].setOutlineThickness(2);
            buttons[i].setOutlineColor(sf::Color(0, 0, 0, 0));
            buttons[i].setFillColor(sf::Color(0, 0, 0, 0));
            buttons[i].setPosition(10, window.getSize().y - 100 - (3 - i) * 70);

            buttonTexts[i].setString(optionStrings[i]);
            buttonTexts[i].setCharacterSize(28);
            buttonTexts[i].setFillColor(sf::Color::White);
            buttonTexts[i].setOutlineColor(sf::Color::Black);
            buttonTexts[i].setOutlineThickness(5);
            buttonTexts[i].setPosition(20, window.getSize().y - 95 - (3 - i) * 70);
        }
    }

    void createGameTitle() {
        gameTitle.setString("SAVIOR TREASURE");
        gameTitle.setCharacterSize(48);
        gameTitle.setFillColor(sf::Color::Green);
        gameTitle.setOutlineColor(sf::Color::Black);
        gameTitle.setOutlineThickness(5);
        gameTitle.setPosition((window.getSize().x - gameTitle.getLocalBounds().width) / 20, 200);
    }

    void handleEvents() {
        try {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    window.close();
                }
                else if (event.type == sf::Event::KeyPressed) {
                    if (event.key.code == sf::Keyboard::Up) {
                        selectedOption = (selectedOption - 1 + 4) % 4;
                    }
                    else if (event.key.code == sf::Keyboard::Down) {
                        selectedOption = (selectedOption + 1) % 4;
                    }
                    else if (event.key.code == sf::Keyboard::Return) {
                        handleOptionSelected();
                    }
                }
            }
        }
        catch (const std::exception& e) {
            std::cerr << "Exception caught in handleEvents: " << e.what() << std::endl;
        }
    }

    void render() {
        window.clear();

        window.draw(backgroundImage);

        for (size_t i = 0; i < 4; ++i) {
            buttons[i].setFillColor((selectedOption == i) ? sf::Color::Green : sf::Color(0, 0, 0, 0));
            window.draw(buttons[i]);
            window.draw(buttonTexts[i]);
        }

        window.draw(gameTitle);

        window.display();
    }

    void handleOptionSelected() {
        switch (selectedOption) {
        case 0:
            std::cout << "Start button selected\n";
            startGame();
            break;
        case 1:
            std::cout << "Controls button selected\n";
            displayControls();
            break;
        case 2:
            std::cout << "Information button selected\n";
            displayInformation();
            break;
        case 3:
            window.close();
            break;
        }
    }
    void startGame() {
        sf::Font oyunFont;
        if (!oyunFont.loadFromFile("Unitblock.ttf")) {
            std::cerr << "Oyun için font yüklenemedi!" << std::endl;
            window.close();
            return;
        }
        window.close();
        Game play;
        play.run();

    }
    void displayInformation() {
        TextWithOutline infoText(font, "*****CREATORS*****\nAlperen Berke Cetinkaya\nCemanur Adiguzel\nCagla Pelin Dogan\nIdil Cansu Sahin", 32, sf::Color::White, sf::Color::Black, 5);
        infoText.setPosition(60.f, 200.f);


        TextWithOutline returnText(font, "Press the esc key to return", 30, sf::Color::White, sf::Color::Black, 5);
        returnText.setPosition(60.f, 700.f);

        sf::FloatRect textRect = returnText.getLocalBounds();
        sf::RectangleShape backgroundRect(sf::Vector2f(textRect.width + 20, textRect.height + 20));
        backgroundRect.setPosition(returnText.getPosition().x - 10, returnText.getPosition().y - 10);
        backgroundRect.setFillColor(sf::Color::Black);
        window.clear();
        window.draw(backgroundImage);
        window.draw(infoText);
        window.draw(returnText);
        window.display();

        sf::Event event;
        while (window.waitEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
                break;
            }
            else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                break;
            }
        }
    }

    void displayControls() {
        TextWithOutline controlsText(font, "******GAME CONTROLS******", 42, sf::Color::White, sf::Color::Black, 5);
        controlsText.setPosition(440.f, 30.f);


        TextWithOutline characterText(font, "CHARACTER CONTROLS\n------------------\n\nLEFT = (Left Arrow)\nUP = (Up Arrow)\nRIGHT = (Right Arrow)\nDOWN = (Down Arrow)\nSPACE = Fire\nE = Interaction(1, 2, 3)", 30, sf::Color::White, sf::Color::Black, 5);
        characterText.setPosition(280.f, 130.f);

        TextWithOutline vehicleText(font, "VEHICLE CONTROLS\n------------------\n\nLEFT = (Left Arrow)\nUP = (Up Arrow)\nRIGHT = (Right Arrow)\nDOWN = (Down Arrow)\nL= GET ON or GET OFF  ", 30, sf::Color::White, sf::Color::Black, 5);
        vehicleText.setPosition(770.f, 130.f);



        TextWithOutline returnText(font, "Press the esc key to return", 30, sf::Color::White, sf::Color::Black, 5);
        returnText.setPosition(460.f, 710.f);

        window.clear();
        window.draw(backgroundImage);
        window.draw(controlsText);
        window.draw(characterText);
        window.draw(vehicleText);
        window.draw(returnText);
        window.display();

        sf::Event event;
        while (window.waitEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
                break;
            }
            else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                break;
            }
        }
    }
};