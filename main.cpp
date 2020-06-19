#include <SFML/Graphics.hpp>
#include <iostream>


#include "NombreCarpeta/clase1.h"

#define kVel 5

int main() {

  clase1 player = clase1();
  int movimiento = 0;
  //Creamos una ventana
  sf::RenderWindow window(sf::VideoMode(1080, 720), "P0. Fundamentos de los Videojuegos. DCCIA");

  
  //Bucle del juego
  while (window.isOpen()) {
    //Bucle de obtención de eventos
    sf::Event event;
    while (window.pollEvent(event)) {

      switch (event.type) {

      //Si se recibe el evento de cerrar la ventana la cierro
      case sf::Event::Closed:
        window.close();
        break;

      //Se pulsó una tecla, imprimo su codigo
      case sf::Event::KeyPressed:

        //Verifico si se pulsa alguna tecla de movimiento
        switch (event.key.code) {

        //Mapeo del cursor
        case sf::Keyboard::Right:
              movimiento = 1;
          break;

        case sf::Keyboard::Left:
              movimiento = 2;
          break;

        case sf::Keyboard::Up:
              movimiento = 4;
          break;

        case sf::Keyboard::Down:
              movimiento = 3;
          break;

        case sf::Keyboard::Space:
              movimiento = 0;
          break;

        //Tecla ESC para salir
        case sf::Keyboard::Escape:
          window.close();
          break;

        //Cualquier tecla desconocida se imprime por pantalla su código
        default:
          std::cout << event.key.code << std::endl;
          break;
        }
      }
    }

    ////////////
    ///UPDATE///
    ////////////
  // PRIMERO SIEMPRE UPDATE   IMPORTANTE!!!!!!!!!!!!!!!!!!!!!!
  // el motivo es que si primero pintar y luego haces update, no se vera reflejada la accion hasta la siguiente iteracion y podria afectar al
  player.update(movimiento);




   ///////////////
    /////DRAW/////
    //////////////
    window.clear(); // esto se usa para borrar lo que habia antes para pintar de nuevo

   player.draw(window);

   window.display(); // para que se muestre la ventana por pantalla
  }

  return 0;
}