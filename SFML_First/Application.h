#pragma once
#include "SFML/Graphics.hpp"


class Application
{
protected:
	sf::RenderWindow m_window;

public:
	Application(unsigned int width, unsigned int height);
	void run();

private:
	void update();
};

