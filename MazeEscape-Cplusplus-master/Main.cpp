// Library Includes
#include <SFML/Window.hpp>	
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <cstdlib>
#include <ctime>

// Project Includes
#include "AssetManager.h"
#include "Wall.h"
#include "Exit.h"
#include "Player.h"
#include "Baddy.h"
#include "Score.h"
#include "Coin.h"
#include "Key.h"

// The main() Function - entry point for our program
int main()
{
	// -----------------------------------------------
	// Game Setup
	// -----------------------------------------------

	// Window - to draw to the screen
	sf::RenderWindow gameWindow;
	gameWindow.create(sf::VideoMode::getDesktopMode(), "Button Masher", sf::Style::Titlebar | sf::Style::Close);

	// Seed our random number generator 
	srand(time(NULL));

	// Create AssetManager
	AssetManager assets;

	// Game Clock - to keep track of time passed each frame
	sf::Clock gameClock;

	// Game state
	bool playing = false;

	// Game camera
	sf::View camera = gameWindow.getDefaultView();

	// Create test objects
	Player ourPlayer;
	ourPlayer.SetPosition(750.0f, 750.0f);
	Coin ourCoin;
	ourCoin.SetPosition(100.0f, 100.0f);
	Score ourScore;
	Key ourKey;
	ourKey.SetPosition(200.0f, 200.0f);
	Exit ourExit;
	ourExit.SetPosition(500.0f, 500.0f);
	ourScore.SetPlayer(&ourPlayer);
	Wall ourWall;
	ourWall.SetPosition(400.0f, 400.0f);

	// -----------------------------------------------
	// Game Loop
	// -----------------------------------------------
	while (gameWindow.isOpen())
	{
		// -----------------------------------------------
		// Input Section
		// -----------------------------------------------

		// Check all events since the last frame and process 
		// each one until there are no more
		sf::Event gameEvent;
		while (gameWindow.pollEvent(gameEvent))
		{
			// TODO: Pass event to input objects


			// Did the player try to close the window?
			if (gameEvent.type == sf::Event::Closed)
			{
				// If so, call the close function on the window.
				gameWindow.close();
			}

		} // End event polling loop

		// -----------------------------------------------
		// Update Section
		// -----------------------------------------------
		// Get the time passed since the last frame and restart our game clock
		sf::Time frameTime = gameClock.restart();

		// TODO: Update all game objects
		if (ourPlayer.IsActive())
			ourPlayer.Update(frameTime);
		if (ourCoin.IsActive())
			ourCoin.Update(frameTime);
		if (ourScore.IsActive())
			ourScore.Update(frameTime);
		if (ourExit.IsActive())
			ourExit.Update(frameTime);
		

		// -----------------------------------------------
		// Collision Section
		// -----------------------------------------------

		// TODO: Collision detection
		if (ourCoin.IsActive() && ourPlayer.IsActive())
		{
			if (ourCoin.GetBounds().intersects(ourPlayer.GetBounds()))
			{
				ourCoin.Collide(ourPlayer);
			}
		}
		if (ourKey.IsActive() && ourPlayer.IsActive())
		{
			if (ourKey.GetBounds().intersects(ourPlayer.GetBounds()))
			{
				ourKey.Collide(ourPlayer);
				ourExit.IsDoorOpen();
				
			}
		}
		if (ourWall.IsActive() && ourPlayer.IsActive())
		{
			if (ourWall.GetBounds().intersects(ourPlayer.GetBounds()))
			{
				ourPlayer.Collide(ourWall);
			}
		}
		
		


		// -----------------------------------------------
		// Draw Section
		// -----------------------------------------------
		// Clear the window to a single colour
		gameWindow.clear(sf::Color::Black);

		// Draw game world to the window
		gameWindow.setView(camera);
		// TODO: Draw game object
		if (ourCoin.IsActive())
			ourCoin.Draw(gameWindow);
		if (ourPlayer.IsActive())
			ourPlayer.Draw(gameWindow);
		if (ourKey.IsActive())
			ourKey.Draw(gameWindow);
		if (ourExit.IsActive())
			ourExit.Draw(gameWindow);
		if (ourWall.IsActive())
			ourWall.Draw(gameWindow);

		// Draw UI to the window
		gameWindow.setView(gameWindow.getDefaultView());
		// TODO: Draw UI objects
		if (ourScore.IsActive())
			ourScore.Draw(gameWindow);
		// Display the window contents on the screen
		gameWindow.display();

	} // End of Game Loop
	return 0;

} // End of main() Function