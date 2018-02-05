#include <SFML/Graphics.hpp>
#include "../include/KeyConfig.hpp"

bool operator==(sf::Event e1, sf::Event e2);

KeyConfig::KeyConfig(){

	actions[PRIMARY_ROD] = static_cast<int>(sf::Mouse::Left) + static_cast<int>(sf::Mouse::ButtonCount);
	actions[SECOND_ROD] = static_cast<int>(sf::Mouse::Right) + static_cast<int>(sf::Mouse::ButtonCount);
	actions[THIRD_ROD] = static_cast<int>(sf::Keyboard::A);
	actions[FOURTH_ROD] = static_cast<int>(sf::Keyboard::E);
	actions[LEFT_KEY] = static_cast<int>(sf::Keyboard::Left);
	actions[RIGHT_KEY] = static_cast<int>(sf::Keyboard::Right);
	actions[UP_KEY] = static_cast<int>(sf::Keyboard::Up);
	actions[DOWN_KEY] = static_cast<int>(sf::Keyboard::Down);
	actions[ROLL] = static_cast<int>(sf::Keyboard::Space);
	actions[RUN] = static_cast<int>(sf::Keyboard::LShift);
	actions[OPEN_INVENTORY] = static_cast<int>(sf::Keyboard::W);
	actions[OPEN_PAUSE] = static_cast<int>(sf::Keyboard::Escape);
	actions[CLOSE_WINDOW] = -1;
	
}

KeyConfig::~KeyConfig(){

}

void KeyConfig::set_all_keys(sf::RenderWindow* window){
	for(int i = 0; i < 12; i++){
		bool isEventOk = false;
		sf::Event event;
		while(!isEventOk){
			window->waitEvent(event);
			isEventOk = (event.type == sf::Event::KeyPressed || event.type == sf::Event::MouseButtonPressed);	
		}
		
		actions[i] = event_to_int(event);
	}
}
void KeyConfig::set_a_key(sf::RenderWindow* window, int a){
	bool isEventOk = false;
	sf::Event event;
	while(!isEventOk){
		window->waitEvent(event);
		isEventOk = (event.type == sf::Event::KeyPressed || event.type == sf::Event::MouseButtonPressed);	
	}

	actions[a] = event_to_int(event);
}

 int KeyConfig::get_action_from_event(sf::Event event) const{
 	int myevt = event_to_int(event);
 	
	for(int i = 0; i < 13; i++){
		if(actions[i] == myevt)
			return i;
	}
	return NULL_KEY;
}

int KeyConfig::event_to_int(sf::Event event){
	int evToInt = -99; //valeur arbitraire représentant un événement non reconnu

	switch(event.type){
		case sf::Event::KeyPressed:
 			evToInt = static_cast<int>(event.key.code);
			break;
		case sf::Event::MouseButtonPressed:
 			evToInt = static_cast<int>(event.mouseButton.button) + static_cast<int>(sf::Mouse::ButtonCount);
 			break;
 		case sf::Event::Closed:
 			evToInt = -1;
 			break;
 		default:
 			break;
	}
 		
 	return evToInt;
}