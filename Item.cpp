#include <string>
#include "Item.hpp"
#include "SpriteManager.hpp"

Item::Item(std::string nName)
	:name(nName), actualState(charging)
{
	load_texture(name);
}

void Item::display(sf::RenderWindow* window, int& x, int& y){
	spriteM->display(window, x, y);
}

void Item::update_texture(){
	spriteM->update_texture((int)actualState);
}

void Item::load_texture(std::string& s){
	spriteM = new SpriteManager(s);
}

Item::~Item(){

}