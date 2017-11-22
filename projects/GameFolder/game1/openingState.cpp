#include "headers/openingState.hpp"
#include "headers/newGameState.hpp"
#include <SFML/Audio.hpp>
#include <math.h>
#include "headers/gui.hpp"
#include "headers/game.hpp"

openingState::openingState(Game * g, Gui * g2){
	//Allow us to point to the main part of the game.
	game = g;
	gui = g2;


	//load the background
	if (!background.loadFromFile("data/background/background.png"))
	{
	    // error...
	}
	//Load background music
	if(!theme.openFromFile("data/music/3-05 A Day's Rest.ogg")){}
	theme.play();
	theme.setVolume((game->returnMusicVolume()/2));

	//Load font
	if (!font.loadFromFile("data/font/BLKCHCRY.ttf"))
	{
	    // error...
	}


	box.push_back(new Box(game->returnWindowX(), 120,500,80,21,gui, "Lands of Evolution", 36, sf::Color::White, font,true));
	box.push_back(new Box(game->returnWindowX(), 320,300,64,19,gui, "Continue Game", 24, sf::Color::White, font,true));
	box.push_back(new Box(game->returnWindowX(), 520,300,64,19,gui, "New Game", 24, sf::Color::White, font,true));
	box.push_back(new Box(game->returnWindowX(), 720,300,64,19,gui, "Settings", 24, sf::Color::White, font,true));
	box.push_back(new Box(game->returnWindowX(), 920,300,64,19,gui, "Quit Game", 24, sf::Color::White, font,true));

	view.setSize(game->returnWindowX(), game->returnWindowY());

}

openingState::~openingState(){
}

void openingState::drawState(sf::RenderWindow & window){
	//Resize picture
	sf::Sprite back(background);

	sf::Vector2f targetSize(view.getSize().x, view.getSize().y); 

	back.setScale(
	    targetSize.x / back.getLocalBounds().width, 
	    targetSize.y / back.getLocalBounds().height);
	
	//Draw the background and set the view
	
	view.setCenter(window.getSize().x/2, window.getSize().y/2);
	window.setView(view);
	window.draw(back);
	
	//Update mainTitle placement;
	
	//Draw
	for (auto & element : box) {
	    element->draw(window);
	}

	
}

void openingState::event(sf::RenderWindow & window){
	sf::Event event;
	while(window.pollEvent(event)){
		if(event.type == sf::Event::Resized){
			view.setSize(event.size.width,event.size.height);
			game->updateSize(event.size.width,event.size.height);
			for (auto & element : box) {
			    //element->setX(event.size.width);
				if(element->isCentered())
					element->setX(event.size.width);
			}

		}
		else if(event.type == sf::Event::Closed){
			window.close();
		}else if(event.type == sf::Event::MouseMoved){
			//CHECK IF ENTERED BUTTONS AND SUCH
		}

		if(event.type == sf::Event::MouseButtonPressed){
			//CHECK IF BUTTONS HAVE BEEN PRESSED
			//event.mouseButton.x
			int i = 0;
			for (auto & element : box) {
				i++;	
				if(element->mouseInside(event.mouseButton.x, event.mouseButton.y)){
					
					if(i == 2){
						//Continue game
						
					}else if(i == 3){
						//New game
						theme.stop();
						game->changeState(new newGameState(game, gui));
					}else if(i == 4){
						//Settings
					}else if(i == 5){
						//Quit game
						window.close();
					}
					
				}
			}
		}
	}
}
