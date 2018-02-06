#pragma once

#include <SFML/Graphics.hpp>
#include <string>	
#include <SpriteManager.hpp>
#include <enums.hpp>

class Player{
private:
	int x, y, health, damage, vx, vy;
	std::string name;
	std::map<Direction, bool> actualDirections;
	Direction firstDirection;
	StateEntity state;
	SpriteManager *spriteM;

public:
	Player(std::string nNom, std::string spriteName);
	~Player();
	void display(sf::RenderWindow* w);
	void load_texture(std::string& s);
	void update_texture();
	void move();
	void run();
	void stop_run();
	void set_dir(Direction d);
	void unset_dir(Direction d);
};