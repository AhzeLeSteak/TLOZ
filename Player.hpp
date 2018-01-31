#include <SFML/Graphics.hpp>
#include <string>	
#include "SpriteManager.hpp"
#include "enums.hpp"

#ifndef PlayerHPP
#define PlayerHPP

class Player{
private:
	int x;
	int y;
	int health;
	int degat;
	std::string name;
	Direction direction;
	StateEntity actualState;
	StateEntity oldState;
	SpriteManager *spriteM;

public:
	Player(std::string nNom);
	~Player();
	void display(sf::RenderWindow& w);
	void load_texture(std::string& s);
	void update_texture();
};

#endif