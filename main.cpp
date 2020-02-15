#include "utility.hpp"

int vertices = 4;

void
HilbertCurve(int n, sf::VertexArray &curve, sf::Image &gradient, double x0 = 0.0, double y0 = 0.0, double xi = 0.0, double xj = 1.0, double yi = 1.0, double yj = 0.0)
{
	if (n <= 0) {
		// Calculate the coordinates of the curve in terms of percentage of canvas (0.0 -> 1.0)
		double X = x0 + (xi + yi) / 2.0;
		double Y = y0 + (xj + yj) / 2.0;

//		sf::Color color(
//			255 - 128 * curve.getVertexCount() / vertices,
//			128 + 128 * curve.getVertexCount() / vertices,
//			128 * curve.getVertexCount() / vertices);

		sf::Color color = colorGradient(gradient, (float)curve.getVertexCount() / (float)vertices);
		// Output the coordinates of the curve, scaling X,Y by SIZE
		curve.append(sf::Vertex(sf::Vector2f(SIZE * X, SIZE * Y), color));
		return;
	}
	HilbertCurve(n - 1, curve, gradient, x0, y0, yi / 2.0, yj / 2.0, xi / 2.0, xj / 2.0);
	HilbertCurve(n - 1, curve, gradient, x0 + xi / 2.0, y0 + xj / 2.0, xi / 2.0, xj / 2.0, yi / 2.0, yj / 2.0);
	HilbertCurve(
		n - 1, curve, gradient,
		x0 + xi / 2.0 + yi / 2.0, y0 + xj / 2.0 + yj / 2.0, xi / 2.0, xj / 2.0, yi / 2.0, yj / 2.0);
	HilbertCurve(
		n - 1, curve, gradient,
		x0 + xi / 2.0 + yi, y0 + xj / 2.0 + yj, -yi / 2.0, -yj / 2.0, -xi / 2.0, -xj / 2.0);

}

int main()
{
	sf::RenderWindow window(sf::VideoMode(SIZE, SIZE), "Hilbert Curve");
	window.setFramerateLimit(60);

	sf::View view(sf::FloatRect(0, 0, SIZE, SIZE));
	window.setView(view);

	int n = 1;
	bool updated = true;
	bool held = false;
	float zoom = 1.0;

	sf::Vector2i pos = sf::Mouse::getPosition(window);
	sf::Vector2i old_pos = pos;

	sf::Image gradient;
	gradient.loadFromFile("../res/color.jpg");

	sf::VertexArray curve(sf::LineStrip);
	HilbertCurve(n, curve, gradient);

	while (window.isOpen()) {
		sf::Event event = {};
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
				break;

			} else if (event.type == sf::Event::Resized) {
				// update the view to the new size of the window
				view.setSize(float(event.size.width), float(event.size.height));
				window.setView(view);
				zoom = 1.0;
				updated = true;

			} else if (event.type == sf::Event::KeyPressed) {
				if (event.key.code == sf::Keyboard::Up) {
					updated = true;
					curve.clear();
					HilbertCurve(increment(n, vertices), curve, gradient);
				} else if (event.key.code == sf::Keyboard::Down) {
					updated = true;
					curve.clear();
					HilbertCurve(decrement(n, vertices), curve, gradient);
				}
				break;
			} else if (event.type == sf::Event::MouseButtonPressed) {
				old_pos = sf::Mouse::getPosition(window);
				held = true;
			} else if (event.type == sf::Event::MouseButtonReleased) {
				held = false;
			} else if (event.type == sf::Event::MouseMoved && held) {
				updated = true;
				pos = sf::Mouse::getPosition(window);
				view.move(sf::Vector2f{old_pos - pos} * zoom);
				window.setView(view);
				old_pos = pos;
			} else if (event.type == sf::Event::MouseWheelScrolled) {
				updated = true;
				if (event.mouseWheelScroll.delta > 0) {
					zoomViewAt({event.mouseWheelScroll.x, event.mouseWheelScroll.y},
						   window, view, (1.f / 1.3f));
					zoom /= 1.3;
				} else if (event.mouseWheelScroll.delta < 0) {
					zoomViewAt({event.mouseWheelScroll.x, event.mouseWheelScroll.y},
						   window, view, 1.3f);
					zoom *= 1.3;
				}
			}
		}
		if (updated) {
			window.clear(sf::Color::White);
			window.draw(curve);
			window.display();
			updated = false;
		}
	}
	return 0;
}