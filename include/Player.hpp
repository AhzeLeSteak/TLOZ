#pragma once

#include <SFML/Graphics.hpp>
#include <string>	
#include "SpriteManager.hpp"
#include "enums.hpp"

class Player{
private:
	int x, y, health, damage, vx, vy;
	std::string name;
	Direction direction;
	StateEntity actualState;
	StateEntity oldState;
	SpriteManager *spriteM;

public:
	Player(std::string nNom);
	~Player();
	void display(sf::RenderWindow* w);
	void load_texture(std::string& s);
	void update_texture();
	void move(Direction dir);
};