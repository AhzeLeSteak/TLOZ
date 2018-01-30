#include <SFML/Graphics.hpp>
#include <enums.hpp>

#ifndef SMHPP
#define SMHPP

class SpriteManager
{
private:
	int h;
	int w;
	int nbSpriteMax[];
	int actualSpriteCounter;
	StateEntity actualState;
	StateEntity oldState;
	std::string spritename;
	sf::Sprite sprite;
	
	static std::map<std::string, sf::Texture> loadedTextures;


public:
	SpriteManager(const std::string& s);
	~SpriteManager();
	void display(sf::RenderWindow& window, int& x, int& y);
	//template<typename en> 
	void update_texture(int actualState, int oldState, int dir);
	static void loadAllTextures();
	
};

#endif	