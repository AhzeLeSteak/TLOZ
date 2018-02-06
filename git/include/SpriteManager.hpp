#pragma once

#include <SFML/Graphics.hpp>
#include <enums.hpp>

class SpriteManager
{
private:
	int x, y, w, h; 
	std::vector<int> nbSpriteMax;
	int actualSpriteCounter;
	StateEntity actualState;
	std::string spritename;
	sf::Sprite sprite;
	
	static std::map<std::string, sf::Texture> loadedTextures;


public:
	SpriteManager(const std::string& s);
	~SpriteManager();
	void draw(sf::RenderWindow* window) const ;
	void move(int dx, int dy);
	void set_position(int& new_x, int& new_y);
	void update_texture(int actualState, int dir);
	void update_texture(int actualState);
	static void loadAllTextures();
	
};