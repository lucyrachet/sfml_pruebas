#pragma once
#include <SFML/Graphics.hpp>
class clase1 {

public:
  clase1(); // constructor
  ~clase1(); //destructor
  void update(int direccion);
  void draw(sf::RenderWindow &window); //render
  //funciones

private:
  //variables de clase
  sf::RectangleShape cuerpo;  // rectangulo de sfml
  float velocidad = 0.10;
  sf::Texture *text; //para guardar texturas en sfml
};