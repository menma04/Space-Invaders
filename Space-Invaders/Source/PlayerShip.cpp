#include"../Header/PlayerShip.h"
#include"../Header/ServiceLocator.h"
#include"../Header/EventService.h"

PlayerShip::PlayerShip()
{
	game_window = nullptr;
}

PlayerShip::~PlayerShip() = default;

void PlayerShip::initialize()
{
	game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
	initializePlayerSprite();
}

void PlayerShip::update()
{
	processPlayerInput();
	player_sprite.setPosition(getPlayerPosition());
}

void PlayerShip::render()
{
	game_window->draw(player_sprite);
}

void PlayerShip::processPlayerInput()
{
	EventService* event_service = ServiceLocator::getInstance()->getEventService();
	if (event_service->isKeyboardEvent()) {
		if (event_service->pressedLeftKey())
		{
			moveLeft();
		}

		if (event_service->pressedRightKey())
		{
			moveRight();
		}
	}
}

void PlayerShip::moveLeft()
{
	position.x -= movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
}

void PlayerShip::moveRight()
{
	position.x += movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
}
void PlayerShip::initializePlayerSprite()
{
	if (player_texture.loadFromFile(player_texture_path))
	{
		player_sprite.setTexture(player_texture);
	}
}

sf::Vector2f PlayerShip::getPlayerPosition() { return position; }
float PlayerShip::getMoveSpeed() { return movement_speed; }