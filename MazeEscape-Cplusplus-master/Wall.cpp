
// Project Includes
#include "Wall.h"
#include "AssetManager.h"

Wall::Wall()
	: SpriteObject() // Initialise parent class
{
	m_sprite.setTexture(AssetManager::GetTexture("graphics/BrickWall2.png"));
	// REMOVE LATER!!!
	m_sprite.setPosition(750.0f, 750.0f);
}