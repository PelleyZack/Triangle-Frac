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

// Constructor for triangle
Triangle::Triangle(int length , sf::Vector2f& s) {
    // Length variable
    L = length;
    // height through origin
    H = (((sqrt(3) * L)/2));
    // Setting the VertexArray to hold linesstrips
    triangle.setPrimitiveType(sf::LinesStrip);
    // Resizing to 4 as linestrip needs to point to the last point
    triangle.resize(4);
    // x,y of origin s
    xAdj = s.x;
    yAdj = s.y;
    // setting the triangle relative of the origin
    triangle[0].position = sf::Vector2f(xAdj-(L/2), yAdj-(H/2));
    triangle[1].position = sf::Vector2f(xAdj+(L/2), yAdj-(H/2));
    triangle[2].position = sf::Vector2f(xAdj, yAdj+(H/2));
    triangle[3].position = sf::Vector2f(xAdj-(L/2), yAdj-(H/2));
}
// Destructor
Triangle::~Triangle() {
}
// Overriden draw command so the triangle can be drawn
void Triangle::draw(sf::RenderTarget& target , sf::RenderStates states) const {
    target.draw(triangle , states);
    }
