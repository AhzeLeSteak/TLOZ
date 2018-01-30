#include <SFML/Graphics.hpp>
#include <iostream>

#include <Player.hpp> 
#include <SpriteManager.hpp>
#include <Item.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 800), "TLOZTMC");

    window.setFramerateLimit(30);

    //Player j1("Baton_portail_big");

    //SpriteManager::loadAllTextures();
    //std::cout << "textureLoaded" << std::endl;
    //Item j("Baton_boost");

    sf::Texture t; t.loadFromFile("../../sprites/Baton_boost.png");
    sf::Sprite s; s.setTexture(t);
    
    while(window.isOpen())
    {
        //window.clear(sf::Color::White);
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.draw(s);
        sf::sleep(sf::seconds(1));
    }

    return 0;
}

void setFullScreen(sf::Window& w){
    sf::VideoMode fS = sf::VideoMode::getDesktopMode();
    w.setSize(sf::Vector2u(fS.width, fS.height));

}