#pragma once

#include <SFML/Graphics.hpp>
#include "Player.hpp" 
#include "SpriteManager.hpp"
#include "Item.hpp"
#include "KeyConfig.hpp"

class Game{
private:
	sf::RenderWindow* window;
	KeyConfig keyConfig;
	//Player player;
	//std::vector<Mob*> mobs;
	//std::vector<NPC*> npcs;


public:
	Game(int fps);
	~Game();
	void start();
	void quit_game();

};