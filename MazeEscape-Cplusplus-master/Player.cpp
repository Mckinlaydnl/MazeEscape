// Project Includes
#include "Player.h"
#include "AssetManager.h"
#include "Wall.h"

// Constants
#define SPEED 500.0f


Player::Player()
	: MovingObject() // Initialise base class
	, m_score(0)
	, KeyPickedUp(false)
{
	m_sprite.setTexture(AssetManager::GetTexture("graphics/PlayerWalkDown1.png"));
}

void Player::Update(sf::Time _frameTime)
{
	// First, assume no keys are pressed
	m_velocity.x = 0.0f;
	m_velocity.y = 0.0f;

	// Use the keyboard function to check 
	// which keys are currently held down
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		m_velocity.y = -SPEED;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		m_velocity.x = -SPEED;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		m_velocity.y = SPEED;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		m_velocity.x = SPEED;
	}

	// Call the update function manually on 
	// the parent class
	// This will actually move the character
	MovingObject::Update(_frameTime);
}

void Player::Collide(GameObject& _collider)
{
	// Only do something if the thing
	// we touched was the player

	// Dynamic Cast the GameObjec ref
	// into a Wall pointer
	// if it suceeds, it was a wall
	Wall* wallCollider = dynamic_cast<Wall*>(&_collider);

	// If it was a wall we hit, we need to move ourselves
	// outside the wall's bounds, aka back where we were
	if (wallCollider != nullptr)
	{
		// We did hit a wall!!!

		// Return to our previous position that we just
		// moved away from this frame
		m_sprite.setPosition(m_previousPosition);

		// clumsy - results in "sticky" walls
		// but good enough for this game
	}
}

int Player::GetScore()
{
	return m_score;
}

void Player::ChangeScore(int _changeBy)
{
	m_score += _changeBy;
}
bool Player::IsKeyPickedUp()
{
	KeyPickedUp = true;
	return KeyPickedUp;
}