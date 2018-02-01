#include <SFML/Graphics.hpp>
#include "enums.hpp"

#ifndef SMHPP
#define SMHPP

class SpriteManager
{
private:
	int h;
	int w;
	std::vector<int> nbSpriteMax;
	int actualSpriteCounter;
	StateEntity actualState;
	std::string spritename;
	sf::Sprite sprite;
	
	static std::map<std::string, sf::Texture> loadedTextures;


public:
	SpriteManager(const std::string& s);
	~SpriteManager();
	void display(sf::RenderWindow* window, int& x, int& y);
	void update_texture(int actualState, int dir);
	void update_texture(int actualState);
	static void loadAllTextures();
	
};

#endif	