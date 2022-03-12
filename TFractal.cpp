// Copyright 2021 <Zachary Pelley>
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <vector>
#include <iostream>
#include <sstream>
#include <string>
#include "./Triangle.hpp"
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>



// function that will be called recursively to generate all the triangles
void fTree(int end, int N, int L, sf::RenderWindow &w, sf::Vector2f& s) {
    // Will always draw the triangle based on the origion s it is given
    w.draw(*new Triangle(L , s));
    // In the case of N being zero, it just draws one triangle
    if (N == 0) {
        Triangle t(L , s);
        w.draw(t);
        return;
    } else if (end == N - 1) {
        // Return case for recursion
        return;
    } else {
        // Creates origin relative to top left, righ, and bottom points
        // These are the center point of the new triangles to be made
        sf::Vector2f topLeft = sf::Vector2f(s.x - L/2 , s.y - 13.0*L/20.0);
        sf::Vector2f topRight = sf::Vector2f(s.x + 3*L/4, s.y - 11.0*L/50.0);
        sf::Vector2f botomPoint = sf::Vector2f(s.x - L/4, s.y + 13.0*L/20.0);
        // Recursively calls the function with the changed perameters
        fTree(end+1 , N, L/2 , w , topLeft);
        fTree(end+1 , N, L/2 , w , topRight);
        fTree(end+1 , N , L/2 , w , botomPoint);
    }
}
// Main function takes in command line arguments
int main(int argc, char* argv[]) {
    // Convert the two inputs to strings
    std::string l = argv[1];
    std::string n = argv[2];
    // Then converts them to int
    int L = std::stoi(l);
    int N = std::stoi(n);

    // Creating render window and event objects
    sf::RenderWindow window(sf::VideoMode(600, 600), "SFML KSGuitarSim");
    sf::Event event;

    // Creating the starting origion point that is
    // The relative center of the window
    sf::Vector2f s;
    s.x = window.getSize().x/2;
    s.y = window.getSize().y/2;

    // Main while loop, continues till window is closed
    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {window.close();}
            window.clear(sf::Color::Black);
            // calls fTree which generates all the triangls and draws them
            fTree(0 , N , L , window , s);
        window.display();
        }
    }
    return 0;
}
