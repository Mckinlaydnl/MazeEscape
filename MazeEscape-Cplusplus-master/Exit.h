#pragma once

// Project Includes
#include "SpriteObject.h"
#include "Player.h"

class Exit : public SpriteObject
{
public:
	Exit();
	//Overriding methods
	virtual void Update(sf::Time _frameTime);

	bool IsDoorOpen();
	bool DoorOpen = false;

	// Public Score Methods
	void SetPlayer(Player* _player);

private:
	Player * m_player;
};