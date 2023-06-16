#pragma once
#include <vector>
#include "SFML/Graphics.hpp"
#include "ModeWindow.h"
#include "Modes.h"


class Application
{
protected:
	sf::RenderWindow m_window;
	std::vector<sf::CircleShape> m_circles;
	std::vector<sf::RectangleShape> m_rectangles;
	std::vector<sf::Shape*> m_shapes;
	std::vector<ModeWindow> m_modeWindows;
	sf::Font m_font;
	MODES m_mode;


public:
	Application(unsigned int width, unsigned int height);
	void createCircle(float radius, sf::Vector2f pos);
	void createRectangle(int width, int height, sf::Vector2f pos);
	void switchMode(int x, int y);
	bool modePressed(int x, int y);
	void clearShapes();
	void run();

private:
	void update();
};

