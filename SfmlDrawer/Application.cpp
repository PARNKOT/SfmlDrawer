#include "Application.h"

Application::Application(unsigned int width, unsigned int height) : m_window(sf::VideoMode(width, height),  "Test") {
	m_window.setFramerateLimit(60);
}

void Application::run() {
	while (m_window.isOpen()) {
		sf::Event event;

		while (m_window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				m_window.close();

			}
		}
		m_window.clear();
		update();
		m_window.display();
	}
}

void  Application::update() {

}