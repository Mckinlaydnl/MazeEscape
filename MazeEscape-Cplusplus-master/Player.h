#pragma once

// Project Includes
#include "MovingObject.h"

class Player : public MovingObject
{

public:

	Player();

	// Overriding Methods
	void Update(sf::Time _frameTime);
	virtual void Collide(GameObject& _collider);

	// Public Player Methods
	int GetScore();
	void ChangeScore(int _changeBy);
	bool KeyPickedUp;
	bool IsKeyPickedUp();

private:

	int m_score;

};