#pragma once

#define PRIMARY_ROD 0
#define SECOND_ROD 1
#define THIRD_ROD 2
#define FOURTH_ROD 3
#define LEFT_KEY 4
#define RIGHT_KEY 5
#define UP_KEY 6
#define	DOWN_KEY 7
#define ROLL 8
#define RUN 9
#define OPEN_INVENTORY 10
#define OPEN_PAUSE 11
#define CLOSE_WINDOW 12
#define NULL_KEY 13

class KeyConfig{
private:
	int actions[13]; 

public:
	KeyConfig();
	~KeyConfig();
	void set_all_keys(sf::RenderWindow* window);
	void set_a_key(sf::RenderWindow*window, int a);
	int get_action_from_event(sf::Event Event);
	int event_to_int(sf::Event event);	//converti un ev	
};

