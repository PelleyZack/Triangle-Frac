// Copyright 2021 <Zachary Pelley>
#ifndef _TRIANGLE
#define _TRIANGLE
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <vector>
#include <iostream>
#include <sstream>
#include <string>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class Triangle : public sf::Drawable {
 public:
    sf::CircleShape tri;
    int H , L;
    int xAdj;
    int yAdj;
    sf::VertexArray triangle;

    Triangle(int rad , sf::Vector2f& s);
    ~Triangle();
 private:
    virtual void draw(sf::RenderTarget& target , sf::RenderStates states) const;
};
#endif  // _TRIANGLE
