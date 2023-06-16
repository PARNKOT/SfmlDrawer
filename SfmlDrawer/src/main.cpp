#include <SFML/Graphics.hpp>
#include "Application.h"

class ShapeWrapper : sf::Shape {

    virtual std::size_t getPointCount() const {

    }

    virtual sf::Vector2f getPoint(std::size_t index) {

    }
};

int main()
{
    Application app(1000, 700);
    app.run();

    return 0;
}
