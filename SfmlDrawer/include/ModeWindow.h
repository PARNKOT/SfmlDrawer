#pragma once
#include <string.h>
#include "SFML/Graphics.hpp"
#include "Modes.h"


class ModeWindow : public sf::Transformable, public sf::Drawable
{
protected:
	sf::Text m_title;
	sf::RectangleShape m_rectangle;
	MODES m_mode;
	bool isFocused;
	bool isSelected;

	void switchColor();

public:
	ModeWindow(int width, int height, MODES mode);
	const sf::Vector2f getPosition();
	const MODES getMode();
	bool getFocus();
	bool getSelect();
	void setPosition(float x, float y);
	void setFillColor(sf::Color color);
	void setText(std::string msg, const sf::Font& font);
	void setFocus(bool value);
	void setSelect(bool value);
	bool contains(sf::Vector2f point);

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

};

