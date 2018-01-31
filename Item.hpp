#include <SFML/Graphics.hpp>
#include "SpriteManager.hpp"

class Item{
private:
	std::string name;
	bool obtained;
	int dmg;
	SpriteManager *spriteM;
	StateItem actualState;

public:
	Item(std::string nName);
	~Item();
	void load_texture(std::string& s);
	void display(sf::RenderWindow& window, int& x, int& y);
	void update_texture();
	void use();
};	