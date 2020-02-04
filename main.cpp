#include <SFML/Graphics.hpp>
#include <cstdio>
#include<cmath>

double SIZE = 900.0;
int MAX_N = 11;
int n_verts = 4;

int increment(int &n)
{
	n = n + 1 <= MAX_N ? n + 1 : MAX_N;
	n_verts = 4 * pow(4, n - 1);
	return n;
}

int decrement(int &n)
{
	n = n - 1 >= 1 ? n - 1 : 1;
	n_verts = 4 * pow(4, n - 1);
	return n;
}

void
HilbertCurve(int n, sf::VertexArray &curve, double x0 = 0.0, double y0 = 0.0, double xi = 0.0, double xj = 1.0, double yi = 1.0, double yj = 0.0)
{
	if (n <= 0) {
		double X = x0 + (xi + yi) / 2.0;
		double Y = y0 + (xj + yj) / 2.0;
		// Output the coordinates of the curve
		sf::Color color(
			255 - 128 * curve.getVertexCount() / n_verts,
			128 + 128 * curve.getVertexCount() / n_verts,
			128 * curve.getVertexCount() / n_verts);

		curve.append(sf::Vertex(sf::Vector2f(SIZE * X, SIZE * Y), color));
		return;
	}
	HilbertCurve(n - 1, curve, x0, y0, yi / 2.0, yj / 2.0, xi / 2.0, xj / 2.0);
	HilbertCurve(n - 1, curve, x0 + xi / 2.0, y0 + xj / 2.0, xi / 2.0, xj / 2.0, yi / 2.0, yj / 2.0);
	HilbertCurve(
		n - 1, curve,
		x0 + xi / 2.0 + yi / 2.0, y0 + xj / 2.0 + yj / 2.0, xi / 2.0, xj / 2.0, yi / 2.0, yj / 2.0);
	HilbertCurve(n - 1, curve, x0 + xi / 2.0 + yi, y0 + xj / 2.0 + yj, -yi / 2.0, -yj / 2.0, -xi / 2.0, -xj / 2.0);

}
int main()
{
	sf::RenderWindow window(sf::VideoMode(SIZE, SIZE), "Hilbert Curve", sf::Style::Default);
	window.setFramerateLimit(30);

	int n = 1;
	sf::VertexArray curve(sf::LineStrip);

	HilbertCurve(n, curve);
//	printf("Actual: %d\tCalculated: %d\n", curve.getVertexCount(), n_verts);

	while (window.isOpen()) {
		sf::Event event = {};
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
				break;

			} else if (event.type == sf::Event::KeyPressed) {
				if (event.key.code == sf::Keyboard::Up) {
					curve.clear();
					HilbertCurve(increment(n), curve);
				} else if (event.key.code == sf::Keyboard::Down) {
					curve.clear();
					HilbertCurve(decrement(n), curve);
				}
//				printf("Actual: %d\tCalculated: %d\n", curve.getVertexCount(), n_verts);
				break;
			}
		}
		window.clear();
		window.draw(curve);
		window.display();
	}
	return 0;
}