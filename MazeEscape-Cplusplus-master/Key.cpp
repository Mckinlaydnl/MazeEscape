// Project Includes
#include "Key.h"
#include "AssetManager.h"

Key::Key()
	: Pickup()
{
	m_sprite.setTexture(AssetManager::GetTexture("graphics/Key.png"));
	// TEMP: Position coin
	m_sprite.setPosition(400.0f, 400.0f);
}


void Key::OnPickup(Player& _player)
{
	_player.IsKeyPickedUp();
}