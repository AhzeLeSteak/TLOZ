#include <fstream>
#include <iostream>
#include "../include/Player.hpp"
#include "../include/utils.hpp"

Player::Player(std::string nName)
	:name(nName), x(0), y(0)	
{
	std::stringstream ss;
	ss << "load/" << name << ".cfg";
	std::ifstream infile(ss.str(), std::ifstream::in);
	
	infile >> damage;

	load_texture(name);
}

void Player::move(Direction dir){
	switch(dir){
		case left:

			spriteM->move(-vx, 0);
			break;
		case right:

			spriteM->move(vx, 0);
			break;
		case up:

			spriteM->move(0, -vy);
			break;
		case down:

			spriteM->move(0, vy);
			break;
		default:
			break;
	}
}

void Player::display(sf::RenderWindow* w){
	spriteM->draw(w);
}

void Player::load_texture(std::string& s){
	delete spriteM;
	spriteM = new SpriteManager(s);
}

void Player::update_texture(){
	spriteM->update_texture((int)actualState, (int)direction);
}

Player::~Player(){
	delete spriteM;
}