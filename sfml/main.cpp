#include <SFML/Graphics.hpp>
#include<math.h>
#include<iostream>
#include<random>
#include <cstdlib>
#include <ctime>
int main()
{   //variables for the calculatoins
    float r1 = 200; //length of pendulam 1
    float r2 = 200; //length of pendulam 2
    float m1 = 40;
    float m2 = 80;
    float a1 = 90;
    float a2 = 45;
    float a1V = 0;  //velocity of pendulam 1
    float a2V = 0;  //velocity of pendulam 2
    float g = .8;
    float t = 3;
    ////clock to decrease the speed
    sf::Clock clock;
    //sf::Time prevTime = clock.getElapsedTime();
    /////////////////////////////////////////////
    sf::Vector2i wRatio = sf::Vector2i(1280, 800);
    sf::Vector2i new00 = sf::Vector2i(wRatio.x / 2, 300);
    sf::RenderWindow window(sf::VideoMode(wRatio.x, wRatio.y), "DOUBLE PENDULAM", sf::Style::Close | sf::Style::Titlebar);
    window.setFramerateLimit(120);
    sf::CircleShape shape1(10);
    sf::CircleShape shape2(10);
    shape1.setOrigin(shape1.getRadius(), shape1.getRadius());
    shape2.setOrigin(shape2.getRadius(), shape2.getRadius());
    shape1.setFillColor(sf::Color::Red);
    shape2.setFillColor(sf::Color::Red);
    float x1 = r1 * sin(a1);
    float y1 = r1 * cos(a1);
    float x2 = x1 + r2 * sin(a2);
    float y2 = y1 + r2 * cos(a2);
    sf::VertexArray trail(sf::LinesStrip);
    sf::Vertex line1[2]{
        sf::Vertex(sf::Vector2f(new00.x,new00.y),sf::Color::Black),
        sf::Vertex(sf::Vector2f(new00.x + x1,new00.y + y1),sf::Color::Black)
    };
    sf::Vertex line2[2]{
        sf::Vertex(sf::Vector2f(new00.x + x1,new00.y + y1),sf::Color::Black),
        sf::Vertex(sf::Vector2f(new00.x + x2,new00.y + y2),sf::Color::Black)
    };
    shape1.setPosition(new00.x + x1, new00.y + y1);
    shape2.setPosition(new00.x + x2, new00.y + y2);
    std::cout << new00.x + x1 << " " << new00.y + y1 << std::endl;
    std::cout << new00.x + x2 << " " << new00.y + y2 << std::endl;
    //diff color for trail
    int red = rand() % 255;
    int green = rand() % 255;
    int blue = rand() % 255;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            else if (event.type == sf::Event::MouseButtonPressed) {
                std::cout << trail.getVertexCount() << std::endl;
            }
            //else if (window.isOpen()) {
            //    ////////FORMULA/////////
            //    float num1 = -g * (2 * m1 + m2) * sin(a1);
            //    float num2 = -m2 * g * sin(a1 - 2 * a2);
            //    float num3 = -2 * sin(a1 - a2) * m2;
            //    float num4 = (a2V * a2V * r2) + (a1V * a1V * r1 * cos(a1 - a2));
            //    float den = r1 * (2 * m1 + m2 - m2 * cos(2 * a1 - 2 * a2));
            //    float a1A = (num1 + num2 + num3 * num4) / den;
            //    num1 = 2 * (sin(a1 - a2));
            //    num2 = a1V * a1V * r1 * (m1 + m2);
            //    num3 = g * (m1 + m2) * cos(a1);
            //    num4 = a2V * a2V * r2 * m2 * cos(a1 - a2);
            //    den = r2 * (2 * m1 + m2 - m2 * cos(2 * a1 - 2 * a2));
            //    float a2A = (num1 * (num2 + num3 + num4)) / den;
            //    /*std::cout << a1A << std::endl;
            //    std::cout << a2A << std::endl;*/
            //    ////////////////////////
            //    x1 = r1 * sin(a1);
            //    y1 = r1 * cos(a1);
            //    x2 = x1 + r2 * sin(a2);
            //    y2 = y1 + r2 * cos(a2);
            //    red = rand() % 255;
            //    green = rand() % 255;
            //    blue = rand() % 255;
            //    a1V += a1A;
            //    a2V += a2A;
            //    a1 += a1V;
            //    a2 += a2V;
            //    ////////////////////////
            //    line1[0].position = sf::Vector2f(new00.x, new00.y);
            //    line1[1].position = sf::Vector2f(new00.x + x1, new00.y + y1);
            //    line2[0].position = sf::Vector2f(new00.x + x1, new00.y + y1);
            //    line2[1].position = sf::Vector2f(new00.x + x2, new00.y + y2);
            //    shape1.setPosition(new00.x + x1, new00.y + y1);
            //    shape2.setPosition(new00.x + x2, new00.y + y2);
            //    /*std::cout << new00.x + x1 << " " << new00.y + y1 << std::endl;
            //    std::cout << new00.x + x2 << " " << new00.y + y2 << std::endl;*/
            //    //std::cout << red << " " << green << " " << blue << std::endl;
            //    trail.append(sf::Vertex(sf::Vector2f(new00.x + x2, new00.y + y2), sf::Color(red, green, blue)));
            //}
        }
        sf::Time time = clock.getElapsedTime();
        ////////FORMULA/////////
        float num1 = -g * (2 * m1 + m2) * sin(a1);
        float num2 = -m2 * g * sin(a1 - 2 * a2);
        float num3 = -2 * sin(a1 - a2) * m2;
        float num4 = (a2V * a2V * r2) + (a1V * a1V * r1 * cos(a1 - a2));
        float den = r1 * (2 * m1 + m2 - m2 * cos(2 * a1 - 2 * a2));
        float a1A = ((num1 + num2 + num3 * num4) / den) * time.asSeconds()*t;
        num1 = 2 * (sin(a1 - a2));
        num2 = a1V * a1V * r1 * (m1 + m2);
        num3 = g * (m1 + m2) * cos(a1);
        num4 = a2V * a2V * r2 * m2 * cos(a1 - a2);
        den = r2 * (2 * m1 + m2 - m2 * cos(2 * a1 - 2 * a2));
        float a2A = ((num1 * (num2 + num3 + num4)) / den) * time.asSeconds()*t;
        clock.restart().asSeconds();
        /*std::cout << a1A << std::endl;
        std::cout << a2A << std::endl;*/
        ////////////////////////
        x1 = r1 * sin(a1);
        y1 = r1 * cos(a1);
        x2 = x1 + r2 * sin(a2);
        y2 = y1 + r2 * cos(a2);
        red = rand() % 255;
        green = rand() % 255;
        blue = rand() % 255;
        a1V += a1A;
        a2V += a2A;
        a1 += a1V;
        a2 += a2V;
        a1V *= .9999;
        a2V *= .9999;
        ////////////////////////
        line1[0].position = sf::Vector2f(new00.x, new00.y);
        line1[1].position = sf::Vector2f(new00.x + x1, new00.y + y1);
        line2[0].position = sf::Vector2f(new00.x + x1, new00.y + y1);
        line2[1].position = sf::Vector2f(new00.x + x2, new00.y + y2);
        shape1.setPosition(new00.x + x1, new00.y + y1);
        shape2.setPosition(new00.x + x2, new00.y + y2);
        /*std::cout << new00.x + x1 << " " << new00.y + y1 << std::endl;
        std::cout << new00.x + x2 << " " << new00.y + y2 << std::endl;*/
        //std::cout << red << " " << green << " " << blue << std::endl;
        trail.append(sf::Vertex(sf::Vector2f(new00.x + x2, new00.y + y2), sf::Color(red, green, blue)));
        window.clear(sf::Color::White);
        window.draw(line1, 2, sf::PrimitiveType::Lines);
        window.draw(line2, 2, sf::PrimitiveType::Lines);
        window.draw(trail);
        window.draw(shape1);
        window.draw(shape2);
        window.display();
    }

    return 0;
}