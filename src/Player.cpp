#include <fstream>
#include <iostream>
#include <Player.hpp>
#include <utils.hpp>

Player::Player(std::string nName): name(nName), x(0), y(0)	
{
	std::stringstream ss;
	ss << "load/" << name << ".perso";
	std::ifstream infile(ss.str(), std::ifstream::in);

	std::string line;
	
	std::getline(infile, line);
	degat = str_to<int>(line);

	load_texture(name);
}

void Player::display(sf::RenderWindow& w){
	spriteM->display(w, x, y);
}

void Player::load_texture(std::string& s){
	delete spriteM;
	spriteM = new SpriteManager(s);
}

void Player::update_texture(){
	spriteM->update_texture((int)actualState, (int)oldState, (int)direction);
}

Player::~Player(){
	delete spriteM;
}