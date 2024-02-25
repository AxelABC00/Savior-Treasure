#pragma once
#include <SFML/Graphics.hpp>

class TextBox {
private:
	
	sf::Texture texture;
	sf::Sprite sprite;
	sf::Vector2f position;
	sf::Font font;
	bool visible;
	const std::string& texturePath;

public:
	sf::Text content;
	void setPosition(const sf::Vector2f& position);
	void setCharacterSize(unsigned int characterSize);
	void setSize(const sf::Vector2f& size);
	void setString(const std::string& text);
	void clear();
	void draw(sf::RenderWindow& window1);
	bool setVisible(bool visible);
	float getWidth() const;
	float getHeight() const;
	TextBox() : texturePath("textbox.png"), position(sf::Vector2f(40, 600)), font(), visible(true){
		if (!font.loadFromFile("04B_30__.TTF")) {
			throw std::runtime_error("Failed to load font!");
		}
		if (!texture.loadFromFile(texturePath)) {
			throw std::runtime_error("Failed to load texture!");
		}
		
		sprite.setTexture(texture);
		sprite.setPosition(position);

		content.setFont(font);
		content.setFillColor(sf::Color::Black);
		//content.setPosition(position.x + 30, position.y + 20);
	}
};

float TextBox::getWidth() const {
	return sprite.getGlobalBounds().width;
}

float TextBox::getHeight() const {
	return sprite.getGlobalBounds().height;
}

bool TextBox::setVisible(bool visible) {
	this->visible = visible;
	sprite.setColor(visible ? sf::Color::White : sf::Color::Transparent);
	content.setFillColor(visible ? sf::Color::Black : sf::Color::Transparent);
	return this->visible;
}

void TextBox::draw(sf::RenderWindow& window1) {
	window1.draw(sprite);
	window1.draw(content);
}

void TextBox::setPosition(const sf::Vector2f& position) {
	this->position = position;
	//content.setPosition(position.x + 30, position.y + 20);
	sprite.setPosition(position);
}

void TextBox::setCharacterSize(unsigned int characterSize) {
	if (characterSize > 0) {
		content.setCharacterSize(characterSize);
	}
}

void TextBox::setSize(const sf::Vector2f& size) {
	sprite.setScale(size.x / texture.getSize().x, size.y / texture.getSize().y);
}

void TextBox::setString(const std::string& text) {
	content.setString(text);
	//content.setPosition(position.x + 30, position.y + 20);
}

void TextBox::clear() {
	content.setString("");
}
