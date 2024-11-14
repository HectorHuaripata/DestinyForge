#include "Character.h"

Character::Character()
{
	this->shape.setSize(sf::Vector2f(50.0f,50.0f));
	this->shape.setFillColor(sf::Color::Red);
}

Character::~Character()
{
}

void Character::move(const float& dt, const float dir_x, const float dir_y)
{
	this->shape.move(dir_x * this->movementSpeed * dt, dir_y * this->movementSpeed * dt);
}

void Character::update(const float& dt)
{
	
}

void Character::render(sf::RenderTarget* target)
{
	target->draw(this->shape);
}
