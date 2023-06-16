#include "ModeWindow.h"


ModeWindow::ModeWindow(int width, int height, MODES mode) :
	m_rectangle(sf::Vector2f(width, height)),
	m_title(),
	m_mode(mode)
{
	setFocus(false);
	setSelect(false);
}

const sf::Vector2f ModeWindow::getPosition() {
	return m_rectangle.getPosition();
}

const MODES ModeWindow::getMode() {
	return m_mode;
}

bool ModeWindow::getFocus() {
	return isFocused;
}

bool ModeWindow::getSelect() {
	return isSelected;
}

void ModeWindow::setPosition(float x, float y) {
	m_rectangle.setPosition(x, y);
}

void ModeWindow::setFillColor(sf::Color color) {
	m_rectangle.setFillColor(color);
}

void ModeWindow::setText(std::string msg, const sf::Font& font) {
	m_title.setFont(font);
	m_title.setString(msg);

	sf::Vector2f rect_pos = m_rectangle.getPosition();
	rect_pos.x += 5;
	rect_pos.y += 5;
	m_title.setPosition(rect_pos);
}

void ModeWindow::setFocus(bool value) {
	isFocused = value;
	
	switchColor();
}

void ModeWindow::setSelect(bool value) {
	isSelected = value;

	switchColor();
}

void ModeWindow::switchColor() {
	if (isSelected) {
		m_rectangle.setFillColor(sf::Color(255, 0, 0, 200));
	}
	else if (isFocused) {
		setFillColor(sf::Color(255, 0, 0, 100));
	}
	else {
		m_rectangle.setFillColor(sf::Color(169, 169, 169, 100));
	}
}

bool ModeWindow::contains(sf::Vector2f point) {
	return m_rectangle.getGlobalBounds().contains(point);
}

void ModeWindow::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(m_rectangle);
	target.draw(m_title);
 }
