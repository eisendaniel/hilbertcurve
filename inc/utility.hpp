//
// Created by Daniel on 15/02/2020.
//

#ifndef _UTILITY_HPP_
#define _UTILITY_HPP_

#include <SFML/Graphics.hpp>
#include <cmath>

#define SIZE 900.0
#define MAX_N 11

int increment(int &n, int &vertices);
int decrement(int &n, int &vertices);

sf::Color colorGradient(sf::Image &colors, float x);

void zoomViewAt(sf::Vector2i pixel, sf::RenderWindow &window, sf::View &view, float factor);
#endif //_UTILITY_HPP_
