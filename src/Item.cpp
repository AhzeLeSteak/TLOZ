#include <string>
#include <Item.hpp>

Item::Item(std::string nName): name(nName)
{
	load_texture(name);
}

Item::~Item(){

}

void Item::load_texture(std::string& s){
	//delete spriteM;
	spriteM = new SpriteManager(s);
}