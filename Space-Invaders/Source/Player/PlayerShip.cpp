#include"../../Header/Player/PlayerShip.h"
#include"../../Header/Player/PlayerController.h"

namespace Player {
	PlayerShip::PlayerShip()
	{
		player_controller = new PlayerController();
	}

	PlayerShip::~PlayerShip()
	{
		delete (player_controller);
	}

	void PlayerShip::initialize()
	{
		player_controller->initialize();
	}

	void PlayerShip::update()
	{
		player_controller->update();
	}

	void PlayerShip::render()
	{
		player_controller->render();
	}
}