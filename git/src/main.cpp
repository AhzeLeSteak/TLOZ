    
#include <Game.hpp>

int main()
{
    Game myGame(30);
    myGame.start();

    myGame.~Game();

    return 0;
}

void setFullScreen(sf::Window& w){
    sf::VideoMode fS = sf::VideoMode::getDesktopMode();
    w.setSize(sf::Vector2u(fS.width, fS.height));

}