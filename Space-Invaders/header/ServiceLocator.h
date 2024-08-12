#pragma once

class ServiceLocator {
private:
	ServiceLocator();
	~ServiceLocator();

	void createAllClasses();
	void destroyAllClasses();

public:
	static ServiceLocator* getInstance();
	void initialize();
	void update();
	void render();
};