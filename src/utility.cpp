//
// Created by Daniel on 15/02/2020.
//

#include "utility.hpp"

int increment(int &n, int &vertices)
{
	n = n + 1 <= MAX_N ? n + 1 : MAX_N;
	vertices = int(4 * pow(4, n - 1));
	return n;
}

int decrement(int &n, int &vertices)
{
	n = n - 1 >= 1 ? n - 1 : 1;
	vertices = int(4 * pow(4, n - 1));
	return n;
}

sf::Color colorGradient(sf::Image &color, float x)
{
	if (x > 0.999)
		x = 0.999;
	if (x < 0.001)
		x = 0.001;
	return color.getPixel((int)(x * color.getSize().x), 0);
}

void zoomViewAt(sf::Vector2i pixel, sf::RenderWindow &window, sf::View &view, float factor)
{
	const sf::Vector2f preZoom{window.mapPixelToCoords(pixel)};
	view.zoom(factor);
	window.setView(view);
	const sf::Vector2f postZoom{window.mapPixelToCoords(pixel)};
	view.move(sf::Vector2f{preZoom - postZoom});
	window.setView(view);
}