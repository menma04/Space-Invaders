#include<SFML/Graphics.hpp>
int main()
{
    // Define the video mode (dimensions)
    sf::VideoMode videoMode = sf::VideoMode(800, 600);

    // Create a window object with specific dimensions and a title
    sf::RenderWindow window(videoMode, "SFML Window");



    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            // Check for window closure
            if (event.type == sf::Event::Closed)
                window.close();
        }


        // Clear the window
        window.clear(sf::Color::Black);

        sf::CircleShape circle(50);
        circle.setFillColor(sf::Color::Green);
        circle.setPosition(0, 0);

        sf::CircleShape traingle(50);
        traingle.setPointCount(3);
        traingle.setFillColor(sf::Color::Blue);
        traingle.setPosition(400, 300);

        sf::CircleShape square(50);
        square.setPointCount(4);
        square.setFillColor(sf::Color::Red);
        square.setPosition(sf::Vector2f(600,300));

        window.draw(circle);
        window.draw(traingle);
        window.draw(square);
        // Display whatever you draw
        window.display();
    }
    return 0;
}