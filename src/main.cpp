#include <SFML/Graphics.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Angle.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <iostream>

enum directions {down, right, up, left};
int main() {

    unsigned int width = 800;
    unsigned int height = 600;

    //inisialisasi windows atau display
    sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode({width, height /*ukuran layar diplay bisa di ganti dengan variable*/}), "Tutorial");
    window->setFramerateLimit(60);

    sf::Texture texture;


    if(!texture.loadFromFile("assets/Sprites/Sprite.png")){

    std::cerr << "ERROR : CANNOT LOAD FILE FROM : assets/sprite.png" <<std::endl;
    return -1;
    }

    sf::Sprite sprite(texture);

    sf::IntRect(dir[4]);
    //looping untuk pemilihan frame yang di jadikan array 
    for (int i = 0; i < 4 ; ++i) { 
        dir[i] = sf::IntRect({{31*i,0},{32,32}});
    }

    sprite.setTextureRect(dir[down]); //menentukan frame dari sprite awal atau default nya 
    sprite.setOrigin({16,16});      //titik orginal atau bisa di bilang pivot dari sebuah obejek berguna klo emng objeknya di puter dll
    sprite.setPosition({width / 2.0f , height /2.0f});         //memntukan posisi sprite dengan sumbu X dan sumbuY

    //kondisi untuk looping layar display
    while(window->isOpen()){
        while (const std::optional event = window->pollEvent()){
            if (event->is<sf::Event::Closed>()){
                window-> close();
            }
            else if (const auto* keyPressed = event-> getIf<sf::Event::KeyPressed>()) {
                if ( keyPressed->scancode == sf::Keyboard::Scancode::Escape){
                    window->close();
                }
            }
        

        }
        sprite.rotate(sf::Angle(sf::degrees(1)));

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::W)) {
            sprite.move({0.0f,-1.0f});
            sprite.setTextureRect(dir[up]);
        }else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::S)) {
            sprite.move({0.0f,1.0f});
            sprite.setTextureRect(dir[down]);
        }else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::A)) {
            sprite.move({-1.0f,0.0f});
            sprite.setTextureRect(dir[left]);
        }else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::D)) {
            sprite.move({1.0f,0.0f});
            sprite.setTextureRect(dir[right]);
        }

        //render display asset 
        window->clear();


        //area untuk mengisi window atau memanggil objek 
        window->draw(sprite);

        window->display();

    }
    delete window;
    return 0;

}
