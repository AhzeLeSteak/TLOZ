#include <SFML/Graphics.hpp>
#include "KeyConfig.hpp"

KeyConfig::KeyConfig(){
	actions = (sf::Event::EventType*)malloc(Action::LENGTH-1);
	
}

KeyConfig::~KeyConfig(){

}

void KeyConfig::set_all_keys(sf::RenderWindow* window){
	for(int i = 0; i < Action::LENGTH-1; i++){
		bool isEventOk = false;
		sf::Event event;
		while(!isEventOk){
			window->waitEvent(event);
			isEventOk = (event.type == sf::Event::KeyPressed || event.type == sf::Event::MouseButtonPressed);	
		}
		actions[i] = event.type;
	}
}
void KeyConfig::set_a_key(sf::RenderWindow*window, Action a){
	bool isEventOk = false;
		sf::Event event;
		while(!isEventOk){
			window->waitEvent(event);
			isEventOk = (event.type == sf::Event::KeyPressed || event.type == sf::Event::MouseButtonPressed);	
		}
		actions[(int)a] = event.type;
}

Action KeyConfig::get_action_from_event(sf::Event event){
	for(int i = 0; i < Action::LENGTH-1; i++){
		if(actions[i] == event.type)
			return (Action)i;
	}
	return Action::null;
}