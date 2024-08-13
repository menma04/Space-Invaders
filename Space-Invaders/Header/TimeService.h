#pragma once
#include<chrono>

class TimeService {
private:
	std::chrono::time_point<std::chrono::steady_clock> previous_time;

	float delta_time;

	float calculateDeltaTime();
	void updateDeltaTime();
	void updatePreviousTime();

public:
	void initialize();
	void update();
	float getDeltaTime();
};
