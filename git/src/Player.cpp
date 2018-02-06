#include <fstream>
#include <iostream>
#include <Player.hpp>	
#include <utils.hpp>

Player::Player(std::string nName, std::string spriteName)
	:name(nName), x(0), y(0), vx(15), vy(15)
{
	std::stringstream ss;
	ss << "../data/load/" << name << ".cfg";
	std::ifstream infile(ss.str(), std::ifstream::in);
	
	infile >> damage;
	std::cout << "damage : " << damage << std::endl;

	std::cout << "appel du contructeur de SpriteManager" << std::endl;
	load_texture(spriteName);
}

void Player::move(){
	if(actualDirections[Direction::left]){
		x -= vx;	
		spriteM->move(-vx, 0);
	}
	if(actualDirections[Direction::right]){
		x += vx;
		spriteM->move(vx, 0);
	}
	if(actualDirections[Direction::up]){
		y -= vy;
		spriteM->move(0, -vy);
	}
	if(actualDirections[Direction::down]){
		y += vy;
		spriteM->move(0, vy);
	}

}

void Player::run(){
	switch(firstDirection){
		case Direction::left:
		case Direction::right:
			vx = 30;
			break;
		case Direction::up:
		case Direction::down:
			vy = 30;
			break;
		default:
			break;
	}

	state = StateEntity::running;
}

void Player::stop_run(){
	vx=15;
	vy=15;
	state = StateEntity::walking;
}

void Player::set_dir(Direction d){
	if(state == StateEntity::standing)
		firstDirection = d;

	switch(d){
		case Direction::left:
			actualDirections[Direction::left] = true;
			actualDirections[Direction::right] = false;
			break;
		case Direction::right:
			actualDirections[Direction::right] = true;
			actualDirections[Direction::left] = false;
			break;
		case Direction::up:
			actualDirections[Direction::up] = true;
			actualDirections[Direction::down] = false;
			break;
		case Direction::down:
			actualDirections[Direction::down] = true;
			actualDirections[Direction::up] = false;
			break;
		default:
			break;

	}
}

void Player::unset_dir(Direction d){
	actualDirections[d] = false;

	if(!(actualDirections[Direction::left] || actualDirections[Direction::right] || actualDirections[Direction::up] || actualDirections[Direction::down]))
		state = StateEntity::standing;
}

void Player::display(sf::RenderWindow* w){
	spriteM->draw(w);
}

void Player::load_texture(std::string& s){
	//delete spriteM;
	spriteM = new SpriteManager(s);
}

void Player::update_texture(){
	spriteM->update_texture((int)state, (int)firstDirection);
}

Player::~Player(){
	delete spriteM;
}