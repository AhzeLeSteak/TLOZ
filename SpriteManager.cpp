#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <sstream>
#include "SpriteManager.hpp"
#include "utils.hpp"

#define STATE_NUMBER StateEntity::NB_OF_STATE

std::map<std::string, sf::Texture> SpriteManager::loadedTextures;


//objets
SpriteManager::SpriteManager(const std::string& s): spritename(s), actualSpriteCounter(0)
{
	std::stringstream ss;
	ss << "sprites/" << spritename << ".cfg";
	
	std::cout << "config file location :" << ss.str() << std::endl;
	
	std::ifstream infile(ss.str(), std::ifstream::in);
	infile >> w;		
	infile >> h;

	std::cout << w << "x" << h <<std::endl;
	
	int i;
	while(infile >> i){
		nbSpriteMax.push_back(i);
	}
	
	ss.str("");
	ss << "sprites/" << spritename << ".png";

	sprite.setTexture(loadedTextures[spritename]);

	
}

void SpriteManager::display(sf::RenderWindow* window, int& x, int& y){
	sprite.setPosition(sf::Vector2f(x, y));
	window->draw(sprite);
}


void SpriteManager::update_texture(int actualState, int dir){
	static int oldState = -1;
	if(actualState == oldState)
		actualSpriteCounter++;
	else{
		oldState = actualState;
		actualSpriteCounter = 0;
	}
	if(actualSpriteCounter > nbSpriteMax[actualState*STATE_NUMBER+dir])
		actualSpriteCounter = 0;

	sprite.setTextureRect(sf::IntRect(actualState*STATE_NUMBER*w, actualSpriteCounter*h, w, h));
}

void SpriteManager::update_texture(int actualState){
	static int oldState = -1;
	if(actualState == oldState)
		actualSpriteCounter++;
	else{
		oldState = actualState;
		actualSpriteCounter = 0;
	}
	if(actualSpriteCounter > nbSpriteMax[actualState])
		actualSpriteCounter = 0;

	sprite.setTextureRect(sf::IntRect(actualSpriteCounter*h, actualState*w, w, h));
}


SpriteManager::~SpriteManager(){

}

//static map
void SpriteManager::loadAllTextures(){
	std::ifstream infile("load/textureToLoad.cfg", std::ifstream::in);	
	std::string texturename;
	while(infile >> texturename){
		std::stringstream texturepath;
		texturepath << "sprites/" << texturename << ".png";
		loadedTextures[texturename].loadFromFile(texturepath.str());
	}
}