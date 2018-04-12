#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <math.h>
#include "Lista2D.hpp"
#include "Fisica.hpp"

//caminho arquivo
#define caminho ""
#define width 800
#define heith 600

int main() {
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    float angle = 0;
    float x = width/2;
    float y = heith/2;
    double dx;
    double dy;
    double xTiro;
    double yTiro;
    sf::Texture fundo;
    sf::Texture texnave;
    sf::Texture laser;
    sf::Sprite fundao;
    int aclfrontal = 0;
    //int aclre = 0;
    Lista2D vetores;

    int FoiAtirado = 0;
    int EstaPressionado = 0;

    Inicializar(&vetores);

    if(!texnave.loadFromFile("assets/ships.png")){
        printf("deu ruim na nave\n");
    }

    if(!fundo.loadFromFile("assets/starfield.png", sf::IntRect(0,0,width,heith))){
        printf("deu ruim no fundo\n");
    }

    if(!laser.loadFromFile("assets/beams.png")){
        printf("deu ruim no laser\n");
    }


    fundao.setTexture(fundo);

    sf::Event event;
    sf::RenderWindow window(sf::VideoMode(width, heith), "ASTEROIDS", sf::Style::Default, settings);
    //window.setVersticalSyncEnabled(true);
    window.setFramerateLimit(120);

    sf::RectangleShape person(sf::Vector2f(48,72));
    person.setOrigin(24,36);
    person.setPosition(x, y);
    person.setTexture(&texnave);
    person.setTextureRect(sf::IntRect(0,2560,256,384));
    sf::RectangleShape propulsor(sf::Vector2f(48,72));
    propulsor.setOrigin(24,36);
    propulsor.setPosition(x,y);
    propulsor.setTexture(&texnave);
    propulsor.setTextureRect(sf::IntRect(256,2560,256,384));


    sf::RectangleShape tiro(sf::Vector2f(12,48));
    tiro.setOrigin(6,24);
    tiro.setTexture(&laser);
    tiro.setTextureRect(sf::IntRect(230,90,60,128));
    //tiro.setPosition(x,y);


    while(window.isOpen() && !sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)){
        while(window.pollEvent(event)){
            switch (event.type){
                case sf::Event::Closed:
                    window.close();
                    break;

                default:
                    break;
            }
        }

        y = 0;
        EstaPressionado = 0;

        //if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) x-=15;
        //if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) x+=15;
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)){
            if(aclfrontal<100)
                aclfrontal++;
            EstaPressionado = 1;
        }else{
            if(aclfrontal>0)
                aclfrontal--;
        }

        /*if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)){
            if(aclre<100)
                aclre++;
        }else{
            if(aclre>0)
                aclre--;
        }*/

        if(aclfrontal)
        {
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)){
                angle+=3;
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)){
                angle-=3;
            }
        }

        angle = (int)angle % 360;

        y -= aclfrontal;
        //y += aclre;

        Atualiza(&vetores, y, angle);

        if(person.getPosition().x < 0)
        {
            person.setPosition(width,person.getPosition().y);
            propulsor.setPosition(width,propulsor.getPosition().y);
        }
        if(person.getPosition().y < 0)
        {
            person.setPosition(person.getPosition().x, heith);
            propulsor.setPosition(propulsor.getPosition().x,heith);
        }
        if(person.getPosition().x > width)
        {
            person.setPosition(0,person.getPosition().y);
            propulsor.setPosition(0,propulsor.getPosition().y);
        }
        if(person.getPosition().y > heith)
        {
            person.setPosition(person.getPosition().x, 0);
            propulsor.setPosition(propulsor.getPosition().x,0);
        }

        person.setRotation(angle);
        propulsor.setRotation(angle);

        if(!FoiAtirado && sf::Keyboard::isKeyPressed(sf::Keyboard::Q)){
            tiro.setPosition(person.getPosition().x,person.getPosition().y);
            tiro.setRotation(angle);
            xTiro = 15*sin(tiro.getRotation()*3.141592/180);
            yTiro = -15*cos(tiro.getRotation()*3.141592/180);
            FoiAtirado = 1;
        }

        vetores.resultante.norma != 0 ? dx = vetores.resultante.x/vetores.resultante.norma * sqrt(vetores.resultante.norma)/2 : dx = 0;
        vetores.resultante.norma != 0 ? dy = vetores.resultante.y/vetores.resultante.norma * sqrt(vetores.resultante.norma)/2 : dy = 0;

        if(tiro.getPosition().x < 0 || tiro.getPosition().x > width || tiro.getPosition().y < 0 || tiro.getPosition().y > heith)
            FoiAtirado = 0;

        person.move(dx,dy);
        propulsor.move(dx,dy);
        if(FoiAtirado)
            tiro.move(xTiro,yTiro);

        window.clear();
        window.draw(fundao);
        if(EstaPressionado)
            window.draw(propulsor);
        if(FoiAtirado)
            window.draw(tiro);
        window.draw(person);
        window.display();
    }
    window.close();

    return 0;
}