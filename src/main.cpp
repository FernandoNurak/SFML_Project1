#include <SFML/Graphics.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Angle.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <optional>scancode


int main() {

    unsigned int width = 800;
    unsigned int height = 600;

    //inisialisasi windows atau display
    sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode({width, height /*ukuran layar diplay bisa di ganti dengan variable*/}), "Tutorial");
    window->setFramerateLimit(60);

    sf::CircleShape circle(66.0f);                          //initialisasi obejek
    circle.setOrigin(circle.getGeometricCenter());                 //pivot atau titik rotate/expand  dari objek 
    circle.setPosition({width / 2.0f, height / 2.0f});        //menentuka posisi objek dengan membagi 2 nilai dari panjang dan lebar diplay agar dapat posisi di tengah display
    circle.setFillColor(sf::Color::Red);                    //menetukan warna isi obejek 
    circle.setOutlineThickness(2.0f);                   //memnetukan ketebalan garis luar
    circle.setOutlineColor(sf::Color::Cyan);                //menentukan warna garis luar 
    //circle.setPointCount(3);                                     //membuat sudut dari sebuah objek 


    sf::RectangleShape kotak({60.0f,60.0f});
    kotak.setOrigin(kotak.getSize() / 1.0f);
    kotak.setPosition({width/2.0f, height / 2.0f});
    kotak.setFillColor(sf::Color::Yellow);
    kotak.setOutlineColor(sf::Color::Green);
    kotak.setOutlineThickness(2.0f);

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
        //render display asset 
        circle.rotate(sf::degrees(2));
        circle.move({1.0f, 2.0f});    
        kotak.rotate(sf::degrees(4));
        
        window->clear();


        //area untuk mengisi window atau memanggil objek 
        window->draw(circle);
        window->draw(kotak);

        window->display();

    }
    delete window;
    return 0;

}
