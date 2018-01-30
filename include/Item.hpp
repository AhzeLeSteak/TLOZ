#include <SFML/Graphics.hpp>
#include <SpriteManager.hpp>

class Item{
private:
	std::string name;
	bool obtained;
	int dmg;
	SpriteManager *spriteM;

public:
	Item(std::string nName);
	~Item();
	void display_use(sf::RenderWindow window);
	void display_inventory(sf::RenderWindow window);
	void load_texture(std::string& s);
	void use();
};