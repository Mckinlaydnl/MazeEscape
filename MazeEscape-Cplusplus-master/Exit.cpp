
// Project Includes
#include "Exit.h"
#include "AssetManager.h"


Exit::Exit()
	: SpriteObject() // Initialise parent class
	, m_player(nullptr)
{
	
	
		
			m_sprite.setTexture(AssetManager::GetTexture("graphics/DoorClosed.png"));
			m_sprite.setPosition(600.0f, 600.0f);
		
	
	
}

bool Exit::IsDoorOpen()
{
	DoorOpen = true;
	return DoorOpen;
}


void Exit::SetPlayer(Player* _player)
{
	m_player = _player;
}
void Exit::Update(sf::Time _frameTime)
{
	
		if (DoorOpen == true)
		{
			m_sprite.setTexture(AssetManager::GetTexture("graphics/DoorOpen.png"));
			m_sprite.setPosition(600.0f, 600.0f);
		}
	
	
}