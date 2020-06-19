#include "clase1.h"
#include <iostream>
clase1::~clase1(){}

clase1::clase1() {
    text = new sf::Texture;
         
         
    text->loadFromFile("resources/sprites.png");
    if(!text->loadFromFile("resources/sprites.png")) std::cout << "No CARGA TEXTURA";


    cuerpo.setTextureRect(sf::IntRect(0 * 75, 0 * 75, 75, 75));
    cuerpo.setOrigin(75 / 2, 75 / 2);
    cuerpo.setSize(sf::Vector2f(75.0f,75.0f));
    cuerpo.setPosition(100,100);
    cuerpo.setTexture(text);
}



void clase1::update(int direccion){ 
    float velx = 0;
    float vely = 0;
    switch (direccion)
    {                                                                           // los intRect son los valores de "resources/sprites" en valor de pixel
    case 0: velx = 0; vely = 0;  break; 
    case 1: velx = velocidad;  cuerpo.setTextureRect(sf::IntRect(0 * 75, 2 * 75, 75, 75)); cuerpo.setScale(1,1); break;
    case 2: velx = -velocidad; cuerpo.setTextureRect(sf::IntRect(0 * 75, 2 * 75, 75, 75)); cuerpo.setScale(-1,1); break;
    case 3: vely = velocidad; cuerpo.setTextureRect(sf::IntRect(0 * 75, 0 * 75, 75, 75)); cuerpo.setScale(1,1); break;
    case 4: vely = -velocidad; cuerpo.setTextureRect(sf::IntRect(0 * 75, 3 * 75, 75, 75)); break; // setScale lo que hace es invertir el sprite si el valor es negativo
    
    default:
        break;
    }
    // esto luego se hara con deltaTime
    cuerpo.move(velx,vely);  // .move pide x e y, quiero que se mueva a la derecha +velocidad, izq -velocidad
}

void clase1::draw(sf::RenderWindow &window){
    window.draw(cuerpo);
}