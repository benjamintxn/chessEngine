#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 800), "Chess Game");

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear(sf::Color::White); // Clear the window with a white background

        const int squareSize = 100; // Size of each square
        sf::Color darkColor(51, 51, 51); // Dark square color
        sf::Color lightColor(204, 204, 204); // Light square color

        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                sf::RectangleShape square(sf::Vector2f(squareSize, squareSize));
                square.setPosition(i * squareSize, j * squareSize);

                // Alternate colors for dark and light squares
                if ((i + j) % 2 == 0) {
                    square.setFillColor(lightColor);
                } else {
                    square.setFillColor(darkColor);
                }

                window.draw(square);
            }
        }

        window.display();
    }

    return 0;
}
