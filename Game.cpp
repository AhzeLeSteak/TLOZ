#include <SFML/Graphics.hpp>
#include <iostream>

#include "Game.hpp"
#include "Player.hpp" 
#include "SpriteManager.hpp"
#include "Item.hpp"

Game::Game(int fps){
	window = new sf::RenderWindow(sf::VideoMode(800, 800), "TLOZTMC");
	window->setFramerateLimit(fps);
    SpriteManager::loadAllTextures();
    keyConfig = KeyConfig();
    //startmenu
    //créer partie
}

Game::~Game(){

}

void Game::start(){
		

	while(window->isOpen())
    {
        window->clear(sf::Color::White);
        sf::Event event;
        while (window->pollEvent(event))
        {
            switch(keyConfig.get_action_from_event(event)){
            	case close_window:
                	quit();
                	break;
                case primary_rod:

                	break;
                case second_rod:

                	break;
                case third_rod:

                	break;
                case forth_rod:

                	break;
                case left:
                	player.move(Direction::left);
                	break;
                case right:
                	player.move(Direction::right);
                	break;
                case up:
                	player.move(Direction::up);
                	break;
                case down:
                	player.move(Direction::down);
                	break;
                case roll:

                	break;
                case run:

                	break;
                case open_inventory:

                	break;
                case open_pause:

                	break;
                case null:
                case default:
                	break;
            }
        }
        
        window->display();
    }

}

Game::quit(){
	save();
	window->close();
}