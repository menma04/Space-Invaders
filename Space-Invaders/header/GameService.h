#pragma once

class GameService
{
private:
	void initialize();
	void destructor();

public:
	GameService();
	~GameService();

	void ignite();
	void update();
	bool isRunning();
	void render();
};

