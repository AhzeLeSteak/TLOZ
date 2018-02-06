#include <SFML/Graphics.hpp>
#include <iostream>

#include <Game.hpp>
#include <Player.hpp>
#include <SpriteManager.hpp>
#include <Item.hpp>
//#include <KeyConfig.hpp>

Game::Game(int fps){
	window = new sf::RenderWindow(sf::VideoMode(800, 800), "TLOZTMC");
    window->setKeyRepeatEnabled(false);
	window->setFramerateLimit(fps);
    SpriteManager::loadAllTextures();
    //startmenu
    std::string name = "Ahze", spriteName = "dude";
    player = new Player(name, spriteName);  
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
                    std::cout << "rod 1" << std::endl;
                	break;
                case SECOND_ROD:
                    std::cout << "rod 2" << std::endl;
                	break;
                case THIRD_ROD:
                    std::cout << "rod 3" << std::endl;
                	break;
                case FOURTH_ROD:
                    std::cout << "rod 4" << std::endl;
                	break;



                case LEFT_KEY:
                	player->set_dir(Direction::left);
                    std::cout << "left" << std::endl;
                	break;

                case -LEFT_KEY: //release
                    player->unset_dir(Direction::left);
                    std::cout << "left released" << std::endl;
                    break;



                case RIGHT_KEY:
                	player->set_dir(Direction::right);
                    std::cout << "right" << std::endl;
                	break;

                case -RIGHT_KEY: //release
                    player->unset_dir(Direction::right);
                    std::cout << "right released" << std::endl;
                    break;



                case UP_KEY:
                	player->set_dir(Direction::up);
                    std::cout << "up" << std::endl;
                    std::cout << "up released" << std::endl;
                	break;

                case -UP_KEY:
                    player->unset_dir(Direction::up);
                    break;


                case DOWN_KEY:
                	player->set_dir(Direction::down);
                	std::cout << "down" << std::endl;
                    std::cout << "down released" << std::endl;
                    break;

                case -DOWN_KEY:
                    player->unset_dir(Direction::down);
                    break;



                case ROLL:
                    std::cout << "roll" << std::endl;
                	break;


                case RUN:
                    player->run();
                    std::cout << "run" << std::endl;
                	break;
                case -RUN:
                    player->stop_run();
                    std::cout << "run released" << std::endl;
                    break;

                case OPEN_INVENTORY:
                    std::cout << "inventory" << std::endl;
                	break;
                case OPEN_PAUSE:
                    std::cout << "pause" << std::endl;
                	break;
                case NULL_KEY:
                default:
                	break;
            }
        }


        player->move();
        player->display(window);
        
        window->display();
    }

}

void Game::quit_game(){
	//save();
	window->close();
}