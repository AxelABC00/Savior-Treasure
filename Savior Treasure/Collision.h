#ifndef COLLISION_H
#define COLLISION_H
#include<iostream>
#include <SFML/Graphics.hpp>
#include "Character.h"

using namespace std;

class CharacterCollision {
	
protected:
    int x;  
    int y; 
    std::vector<int> boundaries;  

public:
    
/* CharacterCollision(const std::string& filename) {
    std::ifstream file(filename);

    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line) && boundaries.size() < 180) { 
            std::istringstream ss(line);
            std::string token;

            std::vector<int> row;
            while (std::getline(ss, token, ',')) {
                row.push_back(std::stoi(token));
            }
            boundaries.push_back(row);
        }
        file.close();
    }
    else {
        std::cerr << "Dosya açýlamadý: " << filename << std::endl;
    }
    x = 0;
    y = 0;
}

	bool colmove() {
		
    if (boundaries[y][x] == 0) { 

        performMove();
	return 1;
    }
    else {
        cantMove()
    }
	return 0;
}
	void setX(int newX) {
    x = newX;
}
	void setY(int newY) {
    y = newY;
}

	void performMove() {

Character::updateAnimation() 

    setX(x + speed);         
    setY(y + speed);
	}
	
	void cantMove() {

Character::updateAnimation() 

	setX(x);
    setY(y);
}

	void collisiondraw(sf::RenderWindow& window) {
		
    sprite.setPosition(x, y);
    std::string filename = "collision.txt";
    CharacterCollision Character(filename);
    Character.setX();
    Character.setY();
    Character.colmove();
}
    ~CharacterCollision();
  */
};

#endif 
