#include <SFML/Graphics.hpp>

int main(int argc, char **argv)
{
	int width = 300, height = 300;

	// RENDER DEMO : DISPLAYS LOGO
	//--------------------------------------
	sf::Texture texture;
	sf::Sprite logo;
	texture.loadFromFile("../res/sfml.png");
	logo.setTexture(texture);
	width = texture.getSize().x;
	height = texture.getSize().y;
	//--------------------------------------

	sf::RenderWindow window(sf::VideoMode(width, height), "SFML");
	window.setFramerateLimit(30);

	while (window.isOpen()) {
		sf::Event event = {};
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
				break;
			}
		}
		window.clear();
		window.draw(logo);
		window.display();
	}
	return 0;
}