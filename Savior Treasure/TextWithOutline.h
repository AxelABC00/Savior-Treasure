#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

class TextWithOutline : public sf::Text {
public:

    TextWithOutline() : sf::Text(), fillColor(sf::Color::White), outlineColor(sf::Color::Black), outlineThickness(0) {}


    TextWithOutline(const sf::Font& font, const std::string& text, unsigned int characterSize, const sf::Color& fillColor, const sf::Color& outlineColor, float outlineThickness)
        : sf::Text(text, font, characterSize), fillColor(fillColor), outlineColor(outlineColor), outlineThickness(outlineThickness) {
        setFillColor(fillColor);
        setOutlineColor(outlineColor);
        setOutlineThickness(outlineThickness);
    }

    void setPosition(float x, float y) {
        sf::Text::setPosition(x, y);
        updateOutline();
    }

    void setPosition(const sf::Vector2f& position) {
        sf::Text::setPosition(position);
        updateOutline();
    }

    void move(float offsetX, float offsetY) {
        sf::Text::move(offsetX, offsetY);
        updateOutline();
    }

    void move(const sf::Vector2f& offset) {
        sf::Text::move(offset);
        updateOutline();
    }

    void setString(const std::string& text) {
        sf::Text::setString(text);
        updateOutline();
    }

    void setCharacterSize(unsigned int size) {
        sf::Text::setCharacterSize(size);
        updateOutline();
    }

    void setFillColor(const sf::Color& color) {
        fillColor = color;
        sf::Text::setFillColor(color);
    }

    void setOutlineColor(const sf::Color& color) {
        outlineColor = color;
        sf::Text::setOutlineColor(color);
    }

    void setOutlineThickness(float thickness) {
        outlineThickness = thickness;
        sf::Text::setOutlineThickness(thickness);
        updateOutline();
    }

private:
    sf::Color fillColor;
    sf::Color outlineColor;
    float outlineThickness;

    void updateOutline() {
        sf::Text::setFillColor(fillColor);
        sf::Text::setOutlineColor(outlineColor);
        sf::Text::setOutlineThickness(outlineThickness);
    }
};