#include <SFML/Graphics.hpp>
#include <iostream>

#include "../include/Game.hpp"
#include "../include/Player.hpp" 
#include "../include/SpriteManager.hpp"
#include "../include/Item.hpp"
#include "../include/KeyConfig.hpp"

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
        while(window->pollEvent(event))
        {
            std::cout << keyConfig.event_to_int(event) << std::endl;
            switch(keyConfig.get_action_from_event(event)){
            	case CLOSE_WINDOW:
                    std::cout << "fermer" << std::endl;
                	quit_game();
                	break;
                case PRIMARY_ROD:
                    std::cout << "baton 1" << std::endl;
                	break;
                case SECOND_ROD:
                    std::cout << "baton 2" << std::endl;
                	break;
                case THIRD_ROD:
                    std::cout << "baton 3" << std::endl;
                	break;
                case FOURTH_ROD:
                    std::cout << "baton 4" << std::endl;
                	break;
                case LEFT_KEY:
                	//player.move(Direction::left);
                    std::cout << "gauche" << std::endl;
                	break;
                case RIGHT_KEY:
                	//player.move(Direction::right);
                std::cout << "droite" << std::endl;
                	break;
                case UP_KEY:
                	//player.move(Direction::up);
                std::cout << "haut" << std::endl;
                	break;
                case DOWN_KEY:
                	//player.move(Direction::down);
                	std::cout << "bas" << std::endl;
                    break;
                case ROLL:
                    std::cout << "rouler" << std::endl;
                	break;
                case RUN:
                    std::cout << "courir" << std::endl;
                	break;
                case OPEN_INVENTORY:
                    std::cout << "inventaire" << std::endl;
                	break;
                case OPEN_PAUSE:
                    std::cout << "pause" << std::endl;
                	break;
                case NULL_KEY:
                default:
                	break;
            }
        }
        
        window->display();
    }

}

void Game::quit_game(){
	//save();
	window->close();
}