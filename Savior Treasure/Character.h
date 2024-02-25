#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
class Character {
private:

    sf::Texture upTexture, downTexture, rightTexture, leftTexture;

public:
    
    sf::Sprite sprite;
    sf::RectangleShape mermi;
    sf::Vector2f fireDirection;
    sf::RectangleShape healthBar;
    float x, y;
    float speed;
    bool is_Firing;
    float health = 100.0f;
    float maxHealth = 100.0f;
    int cerceve_Width, cerceve_Height, numFrames, currentFrame;
    float animationSpeed;
    sf::Clock clock;
    Character(float health, float max_Health, float x_direction, float y_direction, float speed)
        : health(health), maxHealth(max_Health), x(x_direction), y(y_direction), speed(speed), is_Firing(false), currentFrame(0) {
        try {
            if (!upTexture.loadFromFile("Walk Up.png") || !downTexture.loadFromFile("Walk Down.png") ||
                !rightTexture.loadFromFile("Walk Right.png") || !leftTexture.loadFromFile("Walk Left.png")) {
                throw std::runtime_error("Failed to load character's textures");
            }
        }
        catch (const std::exception& e) {
            std::cout << "Error: " << e.what() << std::endl;
            exit(-1);
        }

        sprite.setTexture(rightTexture);
        cerceve_Width = 24;
        cerceve_Height = 24;
        numFrames = 8;
        animationSpeed = 0.37f;

        mermi.setSize(sf::Vector2f(6, 6));//mermi boyut renk
        mermi.setFillColor(sf::Color::Black);

        healthBar.setSize(sf::Vector2f(100.0f, 10.0f));// Can çubuðu boyut renk
        healthBar.setFillColor(sf::Color::Green);
    }

    sf::Vector2f getPosition() const {
        return sf::Vector2f(x, y);
    } //karakterin konumunu alan fonksiyon

    void updateDirection() {  // tuþ yönleri kontrolü

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            move(sf::Vector2f(0.0f, -speed));
            sprite.setTexture(upTexture);
            fireDirection = sf::Vector2f(0.0f, -1.0f);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            move(sf::Vector2f(0.0f, speed));
            sprite.setTexture(downTexture);
            fireDirection = sf::Vector2f(0.0f, 1.0f);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            move(sf::Vector2f(speed, 0.0f));
            sprite.setTexture(rightTexture);
            fireDirection = sf::Vector2f(1.0f, 0.0f);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            move(sf::Vector2f(-speed, 0.0f));
            sprite.setTexture(leftTexture);
            fireDirection = sf::Vector2f(-1.0f, 0.0f);
        }
    }

    void firing() { // Ateþ etme kontrolü

        if (is_Firing) {
            mermi.move(fireDirection * 4.f);


            if (mermi.getPosition().y < 0) {
                is_Firing = false;
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && !is_Firing) {
            // Bir sonraki ateþe izin vermesi için
            is_Firing = true;
            mermi.setPosition(x + cerceve_Width / 2, y);
        }


        if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
            is_Firing = false;
        }
    }
    void updateAnimation() {
        if (clock.getElapsedTime().asSeconds() > animationSpeed) {
            currentFrame = (currentFrame + 1) % numFrames;
            clock.restart();
        }
        updateDirection();

        int textureRectLeft = currentFrame * cerceve_Width;//animasyon çerçeve kontrolü
        sf::IntRect textureRect(textureRectLeft, 0, cerceve_Width, cerceve_Height);
        sprite.setTextureRect(textureRect);
        firing();
    }

    void move(sf::Vector2f direction) {
        x += direction.x * speed;
        y += direction.y * speed;
    }

    void draw(sf::RenderWindow& window) {
        sprite.setPosition(x, y);
        window.draw(sprite);
        window.draw(mermi);
        window.draw(healthBar);
    }
};