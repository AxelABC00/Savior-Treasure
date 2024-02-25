#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
class Gemi {
private:
    sf::Texture backgroundTexture;
    sf::Sprite background;
    sf::Texture gemiTexture;
    sf::Sprite gemi;

    float x;
    float y;
    float speed;

    int frameWidth = 16;
    int frameHeight = 18;
    int numFrames = 1;
    float animationSpeed = 0.5f;
    int currentFrame = 0;
    sf::Clock clock;
    bool gemiVisible;
    static const int numTextures = 3;
    int currentTextureIndex;
public:
    Gemi(const std::string& ana_harita, const std::string& gemi_harita, const std::string& character, float baslangicX, float baslangicY, float speed_)
        : x(baslangicX), y(baslangicY), speed(speed_), gemiVisible(true), currentTextureIndex(0) {
        try {
            if (!backgroundTexture.loadFromFile(ana_harita) || !gemiTexture.loadFromFile(gemi_harita)) {
                throw std::runtime_error("Failed to load textures for background or spaceship");
            }
        }
        catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
            exit(-1);
        }

        background.setTexture(backgroundTexture);
        gemi.setTexture(gemiTexture);
        gemi.setPosition(x, y);
    }


    void direction_(sf::RenderWindow& window, Character& character) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::L)) {
            gemiVisible = !gemiVisible;
            clock.restart();
        }
        if (gemiVisible) {
            setPosition(character.x, character.y);//gemiyi karakterin olmadýðý yerden baþlat
        }
        if (gemiVisible) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                y -= speed;
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                y += speed;
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                x += speed;
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                x -= speed;
            }
        }

        if (clock.getElapsedTime().asSeconds() > animationSpeed) {
            currentFrame = (currentFrame + 1) % numFrames;
            clock.restart();
        }

        int textureRectLeft = currentFrame * frameWidth;
        gemi.setTextureRect(sf::IntRect(textureRectLeft, 0, frameWidth, frameHeight));
    }

    void guncel_animation() {
        if (gemiVisible) {
            if (clock.getElapsedTime().asSeconds() > animationSpeed) {
                currentFrame = (currentFrame + 1) % numFrames;
                clock.restart();
            }

            int textureRectLeft = currentFrame * frameWidth;
            gemi.setTextureRect(sf::IntRect(textureRectLeft, 0, frameWidth, frameHeight));
        }
    }

    void draw(sf::RenderWindow& window) {
        window.draw(background); // Arka planý ilk çiz

        if (gemiVisible) {
            gemi.setPosition(x, y);
            window.draw(gemi); // Gemi sprite'ýný sonra çiz
        }
    }

    bool isVisible() const {
        return gemiVisible;
    }

    void setPosition(float newX, float newY) {
        x = newX;
        y = newY;
    }

    sf::Vector2f getPosition() const {
        return sf::Vector2f(x, y);
    }

    float getSpeed() const {
        return speed;
    }
};