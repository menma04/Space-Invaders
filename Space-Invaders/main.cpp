#include<SFML/Graphics.hpp>
#include<iostream>

using namespace std;

class Player {
   
    int PlayerScore = 0;
    int health = 3;
    int movement_speed = 5;
    sf::Vector2f position = sf::Vector2f(200.0f,100.0f);

public:
    Player() {};

    Player(int initialHealth,int Speed ) {
        health = initialHealth;
        movement_speed = Speed;
        cout << health << movement_speed << endl;
    };

    ~Player() {
        cout << "This is the destructor" << endl;
    };
    sf::Vector2f getPosition() {
        return position;
    };

    int getMovementSpeed() {
        return movement_speed;
    };
    sf::Texture texture;
    sf::Sprite sprite;
    void takeDamage() {};
    void move(float ofsetX) {
        position.x += ofsetX;
    };
    void shootBullets() {};
};

int main()
{
    // Define the video mode (dimensions)
    sf::VideoMode videoMode = sf::VideoMode(800, 600);

    // Create a window object with specific dimensions and a title
    sf::RenderWindow window(videoMode, "SFML Window");

    Player player;
    Player player1(4, 1);
    player.texture.loadFromFile("assets/textures/player_ship.png");
    player.sprite.setTexture(player.texture);


    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            // Check for window closure
            if (event.type == sf::Event::Closed)
                window.close();

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                player.move(-1.0*player.getMovementSpeed());
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                player.move(1.0*player.getMovementSpeed());
            }
        }


        // Clear the window
        window.clear(sf::Color::Black);

        player.sprite.setPosition(player.getPosition());
        window.draw(player.sprite);
        //sf::CircleShape circle(50);
        //circle.setFillColor(sf::Color::Green);
        //circle.setPosition(0, 0);

        //sf::CircleShape traingle(50);
        //traingle.setPointCount(3);
        //traingle.setFillColor(sf::Color::Blue);
        //traingle.setPosition(400, 300);

        //sf::CircleShape square(50);
        //square.setPointCount(4);
        //square.setFillColor(sf::Color::Red);
        //square.setPosition(sf::Vector2f(600,300));

        //window.draw(circle);
        //window.draw(traingle);
        //window.draw(square);
        
        //sf::Texture outscal_texture;
        //outscal_texture.loadFromFile("assets/textures/outscal_logo.png");

        //sf::Sprite sprite;
        //sprite.setTexture(outscal_texture);
        //sprite.setRotation(45);
        //sprite.setPosition(100, 300);
        //window.draw(sprite);

        //sf::Font font;
        //font.loadFromFile("assets/fonts/OpenSans.ttf");
        //sf::Text text("SFML is Awesome!", font, 50);
        //text.setFillColor(sf::Color::White);
        //window.draw(text);



        // Display whatever you draw
        window.display();
    }
    return 0;
}