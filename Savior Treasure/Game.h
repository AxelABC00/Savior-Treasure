#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

class Game {
private:
    sf::RenderWindow window;
    sf::Texture arkaplanTexture;
    sf::Sprite arkaplanSprite;
    sf::Event event;
    Character character;
    Enemy enemy;
    Enemy enemy2;
    Enemy enemy3;
    Enemy enemy4;
    Gemi gemi;
    TextBox textBox;

    sf::Text introText, optionText1, optionText2, optionText3, responseText;
    int choice = 0;
    int count = 0;
    bool isTextVisible = false;
    std::vector<sf::Text> optionTexts;
    std::vector<sf::Text> introTexts;

public:
    Game()
        : window(sf::VideoMode(1280, 960), "SFML"),
        character(100.0f, 100.0f, 820.0f, 2150.0f, 0.7f),
        enemy(100.0f, 50.0f, 2450.0f, 2350.0f),
        enemy2(100.0f, 50.0f, 900.0f, 3200.0f),
        enemy3(100.0f, 50.0f, 900.0f, 3250.0f),
        enemy4(100.0f, 50.0f, 900.0f, 3300.0f),
        gemi("ana_harita.jpeg", "gemi.png", "character.png", 20.0f, 800.0f, 0.5f),
        textBox() {

        try {
            if (!arkaplanTexture.loadFromFile("ana_harita.jpeg")) {
                throw std::runtime_error("Failed to load background texture");
            }
        }
        catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
            exit(-1);
        }

        // Arka plan sprite'ýný ayarlama
        arkaplanSprite.setTexture(arkaplanTexture);
        arkaplanSprite.setPosition(0, 0);
    }

    void setOptionText(sf::Text& text, const sf::Font& font, int characterSize, const sf::Color& fillColor, const std::string& content) {
        text.setFont(font);
        text.setCharacterSize(characterSize);
        text.setFillColor(fillColor);
        text.setString(content);
    }

    

    int myCode(int count, sf::Event event) {
        bool isTextVisible = false;
        setlocale(LC_ALL, "Turkish");

        window.setFramerateLimit(1000);

        sf::Font font;
        try {
            if (!font.loadFromFile("04B_30__.TTF")) {
                throw std::runtime_error("Error loading font!");
            }
        }
        catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
            exit(EXIT_FAILURE);
        }

        Talk character1("", "", "", "", "", "", "");
        Baslangic baslangic;
        Muhafiz muhafiz;
        Muhtar1 muhtar1;
        Muhtar2 muhtar2;
        Muhtar3 muhtar3;
        Muhtar4 muhtar4;
        Muhtar5 muhtar5;
        Muhtar6 muhtar6;
        FinalChoice sonsecim;
        Bitis bitis;

        sf::Text introText, optionText1, optionText2, optionText3, responseText;
        

        std::vector<sf::Text> optionTexts;
        std::vector<sf::Text> introTexts;
        int choice = 0;
        sf::Vector2f characterPosition = character.getPosition();

        //her bir yaziyi karakterin konumuna gore ayarlama
        sf::Vector2f contentPosition(characterPosition.x - textBox.getWidth() / 2.2, characterPosition.y + textBox.getHeight() / 30);
        introText.setPosition(contentPosition.x, contentPosition.y + 40);
        optionText1.setPosition(contentPosition.x, contentPosition.y + 100);
        optionText2.setPosition(contentPosition.x, contentPosition.y + 150);
        optionText3.setPosition(contentPosition.x, contentPosition.y + 200);
        responseText.setPosition(contentPosition.x, contentPosition.y + 40);

        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    window.close();
                }
                else if (event.type == sf::Event::KeyPressed) {
                    if (event.key.code == sf::Keyboard::E) {
                        choice = 0;
                        isTextVisible = true;
                        if (count == 1) {
                            character1 = baslangic;
                        }
                        if (count == 2) {
                            character1 = muhafiz;
                        }
                        else if (count == 3) {
                            character1 = muhtar1;
                        }
                        else if (count == 4) {
                            character1 = muhtar2;
                        }
                        else if (count == 5) {
                            character1 = muhtar3;
                        }
                        else if (count == 6) {
                            character1 = muhtar4;
                        }
                        else if (count == 7) {
                            character1 = muhtar5;
                        }
                        else if (count == 8) {
                            character1 = muhtar6;
                        }
                        else if (count == 9) {
                            character1 = sonsecim;
                        }
                        else if (count == 10) {
                            character1 = bitis;
                        }

                    }

                    setOptionText(introText, font, 20, sf::Color::White, character1.introText);
                    setOptionText(optionText1, font, 20, sf::Color::White, character1.option1);
                    setOptionText(optionText2, font, 20, sf::Color::White, character1.option2);
                    setOptionText(optionText3, font, 20, sf::Color::White, character1.option3);

                    setOptionText(responseText, font, 24, sf::Color::Blue, "");

                    introTexts.push_back(introText);
                    optionTexts.push_back(optionText1);
                    optionTexts.push_back(optionText2);
                    optionTexts.push_back(optionText3);


                    if (event.key.code == sf::Keyboard::Num1) {
                        choice = 1;
                    }
                    else if (event.key.code == sf::Keyboard::Num2) {
                        choice = 2;
                    }
                    else if (event.key.code == sf::Keyboard::Num3) {
                        choice = 3;
                    }

                    if (choice != 0 && !optionTexts.empty()) {
                        std::string response = character1.getResponse(choice);
                        responseText.setString(response);

                        optionTexts.clear();
                    }
                    if (choice != 0) {
                        // Draw the response text only if a choice has been made
                        window.draw(responseText);
                    }
                    if (event.key.code == sf::Keyboard::A) {
                        // Clear intro text, option texts and response text
                        introTexts.clear();
                        optionTexts.clear();
                        responseText.setString("");

                        // Clear the text box content
                        textBox.setString("");

                        textBox.clear();
                        isTextVisible = false;
                        return count;
                    }


                }

                if (isTextVisible) {
                    // Draw the text box
                    textBox.draw(window);
                    for (auto& optionText : optionTexts) {
                        window.draw(introText);
                        window.draw(optionText);
                    }

                    if (choice != 0) {
                        window.draw(responseText);
                    }

                }


                window.display();

            }

        }
    }


    void pencerecontrol() { //kullanýcýnýn pencereyle etkileþimde bulunduðu olaylarýn kontrolü
        sf::Event event;
        bool isTextVisible = false;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::E) {
                    std::cout << "Textbox is opened.";
                    count++;
                    myCode(count, event);
                    isTextVisible = false;
                }
            }
        }
    }


    void update() {
        character.updateAnimation();
        enemy.updateAnimation();
        enemy2.updateAnimation();
        enemy3.updateAnimation();
        enemy4.updateAnimation();
        control();
        gemi.direction_(window, character); // Gemi yönlendirme fonksiyonunu çaðýr
        gemi.guncel_animation();
    }

    void control() {

        sf::FloatRect bulletBounds = character.mermi.getGlobalBounds();//*düþman mermi çarpýþmasý kontrolü
        sf::FloatRect enemyBounds = enemy.sprite.getGlobalBounds();
        if (bulletBounds.intersects(enemyBounds) && character.is_Firing) {
            enemy.health -= 2.0f;
            character.is_Firing = false;
        }
        sf::FloatRect enemy2Bounds = enemy2.sprite.getGlobalBounds();
        if (bulletBounds.intersects(enemy2Bounds) && character.is_Firing) {
            enemy2.health -= 2.0f;
            character.is_Firing = false;
        }
        sf::FloatRect enemy3Bounds = enemy3.sprite.getGlobalBounds();
        if (bulletBounds.intersects(enemy3Bounds) && character.is_Firing) {
            enemy3.health -= 2.0f;
            character.is_Firing = false;
        }
        sf::FloatRect enemy4Bounds = enemy4.sprite.getGlobalBounds();
        if (bulletBounds.intersects(enemy4Bounds) && character.is_Firing) {
            enemy4.health -= 2.0f;
            character.is_Firing = false;
        }
        //düsman karakter çarpýþmasý kontrolü
        if (character.sprite.getGlobalBounds().intersects(enemy.sprite.getGlobalBounds())) {
            character.health -= 0.1f;
        }
        if (character.sprite.getGlobalBounds().intersects(enemy2.sprite.getGlobalBounds())) {
            character.health -= 0.1f;
        }
        if (character.sprite.getGlobalBounds().intersects(enemy3.sprite.getGlobalBounds())) {
            character.health -= 0.1f;
        }
        if (character.sprite.getGlobalBounds().intersects(enemy4.sprite.getGlobalBounds())) {
            character.health -= 0.1f;
        }
        if (character.health <= 0.0f) {
            window.close();
        }

    }

    void drawHealthBars(Character& character, Enemy& enemy, sf::RenderWindow& window) {
        // Karakterin can çubuðunu çizme kýsmý
        character.healthBar.setSize(sf::Vector2f((character.health / character.maxHealth) * 100.0f, 10.0f));
        character.healthBar.setPosition(character.x - 30.0f, character.y - 20.0f); // Can çubuðunu karakterin üstüne yerleþtir
        window.draw(character.healthBar);

        //  düþman caný 0'dan büyükse düþmanýn can çubuðunu çiz
        if (enemy.health > 0.0f) {
            enemy.healthBar.setSize(sf::Vector2f((enemy.health / enemy.maxHealth) * 50.0f, 5.0f));
            enemy.healthBar.setPosition(enemy.x, enemy.y - 10.0f); // Can çubuðunu düþmanýn üstüne yerleþtir
            window.draw(enemy.healthBar);
        }
    }

    void render() {
        window.clear();

        window.draw(arkaplanSprite);
        character.draw(window);
        enemy.draw(window);
        enemy2.draw(window);
        enemy3.draw(window);
        enemy4.draw(window);


        if (enemy.health <= 0.0f) {
            enemy.deadEnemySprite.setPosition(enemy.x, enemy.y);
            window.draw(enemy.deadEnemySprite);
        }
        if (enemy2.health <= 0.0f) {
            enemy2.deadEnemySprite.setPosition(enemy2.x, enemy2.y);
            window.draw(enemy2.deadEnemySprite);
        }
        if (enemy3.health <= 0.0f) {
            enemy3.deadEnemySprite.setPosition(enemy3.x, enemy3.y);
            window.draw(enemy3.deadEnemySprite);
        }
        if (enemy4.health <= 0.0f) {
            enemy4.deadEnemySprite.setPosition(enemy4.x, enemy4.y);
            window.draw(enemy4.deadEnemySprite);
        }

        drawHealthBars(character, enemy, window);
        drawHealthBars(character, enemy2, window);
        drawHealthBars(character, enemy3, window);
        drawHealthBars(character, enemy4, window);
        if (gemi.isVisible()) {
            gemi.draw(window);
        }

        window.display();
    }

    void moveCharacter() {


        if (!gemi.isVisible()) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                character.move(sf::Vector2f(0.f, -character.speed));

            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                character.move(sf::Vector2f(0.f, character.speed));
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                character.move(sf::Vector2f(character.speed, 0.f));
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                character.move(sf::Vector2f(-character.speed, 0.f));
            }
        }
    }

    void handleZoom(TextBox& textBox) {
        const float zoomSpeed = 0.01f;

        sf::View view = window.getView();
        float currentZoom = view.getSize().x / window.getSize().x;

        // t tuşuna basıldıysa (zoom in)
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::T)) {
            view.zoom(1.f - zoomSpeed);
        }
        // y tuşuna basıldıysa (zoom out)
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y)) {
            view.zoom(1.f + zoomSpeed);
        }

        // Character nesnesinden konumunu alıp view'i bu konuma odaklama
        sf::Vector2f characterPosition = character.getPosition();
        view.setCenter(characterPosition);

        // Metin kutusunun konumunu karaktere gore ayarlama
        sf::Vector2f textBoxPosition(characterPosition.x - textBox.getWidth() / 2, characterPosition.y + textBox.getHeight() /400);
        textBox.setPosition(textBoxPosition);

        window.setView(view);
    }


    void run() {

        while (window.isOpen()) {

            pencerecontrol();
            update();
            handleZoom(textBox);
            render();

        }
    }

    
};