#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <sstream>
#include <SpriteManager.hpp>
#include <utils.hpp>

std::map<std::string, sf::Texture> SpriteManager::loadedTextures;


//objets
SpriteManager::SpriteManager(const std::string& s): spritename(s), actualSpriteCounter(0)
{
	std::stringstream ss;
	ss << "../../sprites/" << spritename << ".cfg";
	std::cout << "config file location :" << ss.str() << std::endl;
	std::ifstream infile(ss.str(), std::ifstream::in);
	std::cout << "config file loaded" << std::endl;
	std::string line;
	std::getline(infile, line);
	w = str_to<int>(line);
	std::cout << line << std::endl;		
	std::getline(infile, line);
	std::cout << line << std::endl;
	h = str_to<int>(line);
	
	ss.str("");
	ss << "../../sprites/" << spritename << ".png";

	sprite.setTexture(loadedTextures[spritename]);
	/*
	sf::Vector2u v = loadedTextures[spritename].getSize();
	w_total = v.x;
	h_total = v.y;
	*/
}

void SpriteManager::display(sf::RenderWindow& window, int& x, int& y){
	sprite.setPosition(sf::Vector2f(x, y));
	window.draw(sprite);
}


void SpriteManager::update_texture(int actualState, int oldState, int dir){
	if(actualState == oldState)
		actualSpriteCounter++;
	else{
		oldState = actualState;
		actualSpriteCounter = 0;
	}
	if(actualSpriteCounter > nbSpriteMax[actualState*4+dir])
		actualSpriteCounter = 0;

	sprite.setTextureRect(sf::IntRect(nbSpriteMax[actualState*4+dir]*w, actualSpriteCounter*h, w, h));
}

SpriteManager::~SpriteManager(){

}

//static map
void SpriteManager::loadAllTextures(){
	std::ifstream infile("load/textureToLoad.cfg", std::ifstream::in);	
	std::string texturename;
	while(infile >> texturename){
		std::stringstream texturepath;
		texturepath << "../../sprites/" << texturename << ".png";
		//std::cout << texturename << "\t" << texturepath.str() << std::endl; //afficher nom et chemin des textures
		loadedTextures[texturename].loadFromFile(texturepath.str());
	}
}