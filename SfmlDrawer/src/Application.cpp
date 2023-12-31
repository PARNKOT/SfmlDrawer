#include "Application.h"


Application::Application(unsigned int width, unsigned int height) :
	m_window(sf::VideoMode(width, height), "Test", sf::Style::Close),
	m_mode(MODES::circle)
{
	m_window.setFramerateLimit(60);

	m_font.loadFromFile("../fonts/times.ttf");
	ModeWindow modeRectangle(200, 150, MODES::rectangle);
	ModeWindow modeCircle(200, 150, MODES::circle);

	modeRectangle.setPosition(20, 20);
	modeCircle.setPosition(20, 220);

	modeRectangle.setText("Rectangle", m_font);
	modeCircle.setText("Circle", m_font);
	
	modeCircle.setSelect(true);

	m_modeWindows.push_back(modeRectangle);
	m_modeWindows.push_back(modeCircle);

}

void Application::run() {
	while (m_window.isOpen()) {
		sf::Event event;

		while (m_window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				m_window.close();
			}
			else if (event.type == sf::Event::KeyPressed) {
				if (event.key.code == sf::Keyboard::Delete) {
					clearShapes();
				}

			}
			else if (event.type == sf::Event::MouseButtonPressed) {
				if (modePressed(event.mouseButton.x, event.mouseButton.y))
				{ 
					switchMode(event.mouseButton.x, event.mouseButton.y);
					continue;
				}

				if (m_mode == MODES::circle) {
 					createCircle(40.0f, sf::Vector2f(event.mouseButton.x, event.mouseButton.y));
				}
				else if (m_mode == MODES::rectangle) {
					createRectangle(80, 50, sf::Vector2f(event.mouseButton.x, event.mouseButton.y));
				}
			}
			else if (event.type == sf::Event::MouseMoved) {
				for (int i = 0; i < m_modeWindows.size(); ++i) {
					if (m_modeWindows.at(i).contains(sf::Vector2f(event.mouseMove.x, event.mouseMove.y))) {
						m_modeWindows.at(i).setFocus(true);
					}
					else {
						m_modeWindows.at(i).setFocus(false);
					}
				}
			}
		}
		m_window.clear();
		update();
		m_window.display();
	}
}

void  Application::update() {
	for (int i = 0; i < m_shapes.size(); ++i) {
		m_window.draw(*m_shapes.at(i));
	}

	for (int i = 0; i < m_modeWindows.size(); ++i) { 
		m_window.draw(m_modeWindows.at(i));
	}
}

bool Application::modePressed(int x, int y) {
	for (int i = 0; i < m_modeWindows.size(); ++i) {
		if (m_modeWindows.at(i).contains(sf::Vector2f(x, y))) {
			return true;
		}
	}

	return false;
}

void Application::switchMode(int x, int y) {
	for (int i = 0; i < m_modeWindows.size(); ++i) {
		if (m_modeWindows.at(i).contains(sf::Vector2f(x, y))) {
			m_modeWindows.at(i).setSelect(true);
			m_mode = m_modeWindows.at(i).getMode();
		}
		else {
			m_modeWindows.at(i).setSelect(false);
		}
	}

}

void Application::createCircle(float radius, sf::Vector2f pos) {
	sf::CircleShape* pcircle = new sf::CircleShape(radius);
	pcircle->setFillColor(sf::Color(255, 255, 255, 120));
	pcircle->setPosition(pos.x - radius, pos.y - radius);

	m_shapes.push_back(pcircle);
}

void Application::createRectangle(int width, int height, sf::Vector2f pos) {
	sf::RectangleShape* prectangle = new sf::RectangleShape(sf::Vector2f(width, height));
	prectangle->setFillColor(sf::Color(255, 255, 255, 120));
	prectangle->setPosition(pos.x - width / 2, pos.y - height / 2);

	m_shapes.push_back(prectangle);
}

void Application::clearShapes() {
	for (int i = 0; i < m_shapes.size(); ++i) {
		delete m_shapes.at(i);
	}

	m_shapes.clear();
}