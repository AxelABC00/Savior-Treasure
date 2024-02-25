#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
class Enemy {
private:
    sf::Texture texture;
    sf::Texture deadEnemyTexture;
public:
    float health = 100.0f;
    float maxHealth = 100.0f;
    float x, y;

    sf::Sprite sprite;
    int frameWidth, frameHeight, numFrames, currentFrame;
    float animationSpeed;
    sf::Clock clock;
    sf::RectangleShape healthBar;
    sf::Sprite deadEnemySprite;

    Enemy(float health, float maxHealth, float x, float y)
        : health(health), maxHealth(maxHealth), x(x), y(y), currentFrame(0) {
        try {
            if (!texture.loadFromFile("dusman_war.png") || !deadEnemyTexture.loadFromFile("olu_dusman.png")) {
                throw std::runtime_error("Failed to load enemy texture");
            }
        }
        catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
            exit(-1);
        }

        sprite.setTexture(texture);
        frameWidth = 16;
        frameHeight = 16;
        numFrames = 6;
        animationSpeed = 0.2f;

        // düþman için can çubuðu
        healthBar.setSize(sf::Vector2f(50.0f, 5.0f));
        healthBar.setFillColor(sf::Color::Red);

        deadEnemySprite.setTexture(deadEnemyTexture);
    }

    void updateAnimation() {
        if (health > 0.0f) {
            if (clock.getElapsedTime().asSeconds() > animationSpeed) {
                currentFrame = (currentFrame + 1) % numFrames;
                clock.restart();
            }

            int textureRectLeft = currentFrame * frameWidth;
            sf::IntRect textureRect(textureRectLeft, 0, frameWidth, frameHeight);
            sprite.setTextureRect(textureRect);

            // Düþman için can çubuðu kontrolleri
            healthBar.setSize(sf::Vector2f((health / maxHealth) * 30.0f, 5.0f));
            healthBar.setPosition(x, y - 10.0f);
        }
    }

    void draw(sf::RenderWindow& window) {
        sprite.setPosition(x, y);
        window.draw(sprite);
        window.draw(healthBar);
    }
};
class Enemy2 : public Enemy {
public:
    Enemy2(float health, float maxHealth, float x, float y)
        : Enemy(health, maxHealth, x, y) {

    }
};
class Enemy3 : public Enemy {
public:
    Enemy3(float health, float maxHealth, float x, float y)
        : Enemy(health, maxHealth, x, y) {

    }
};
class Enemy4 : public Enemy {
public:
    Enemy4(float health, float maxHealth, float x, float y)
        : Enemy(health, maxHealth, x, y) {

    }
};