#ifndef KEYCONFIGHPP
#define KEYCONFIGHPP

enum Action{
	primary_rod,
	second_rod,
	third_rod,
	forth_rod,
	left,
	right,
	up,
	down,
	roll,
	run,
	open_inventory,
	LENGTH,
	open_pause,
	close_window,
	null
};

class KeyConfig{
private:
	sf::Event::Event* actions; 

public:
	KeyConfig();
	~KeyConfig();
	void set_all_keys(sf::RenderWindow* window);
	void set_a_key(sf::RenderWindow*window, Action a);
	Action get_action_from_event(sf::Event);

	static bool operator==(sf::Event e1, sf::Event e2){
		
	}

#endif