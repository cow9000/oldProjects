#include "headers/newGameState.hpp"
#include "headers/playState.hpp"
#include <SFML/Audio.hpp>
#include <math.h>
#include "headers/game.hpp"
#include "headers/gui.hpp"

newGameState::newGameState(Game * g, Gui * g2){
	//Allow us to point to the main part of the game.
	game = g;
	gui = g2;

	playerName = "";

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

	view.setSize(game->returnWindowX(), game->returnWindowY());

	box.push_back(new Box(game->returnWindowX(), game->returnWindowY(),game->returnWindowX() - 100,game->returnWindowY() - 100,19,gui, "Enter your name", 36, sf::Color::White, font,true));

	view.setCenter(game->returnWindowX()/2, game->returnWindowY()/2);
}

newGameState::~newGameState(){
	theme.stop();
	delete &theme;
	delete &gui;
	delete &view;
	delete &font;
	delete &background;
	delete &box;
	
	
}

void newGameState::drawState(sf::RenderWindow & window){
	
	window.setView(view);
	for (auto & element : box) {
		if(playerName != ""){
			element->setString(playerName);
		}else{
			element->setString("Enter your name");
		}
		element->draw(window);
	}
}

void newGameState::event(sf::RenderWindow & window){
	
	sf::Event event;
	while(window.pollEvent(event)){
		if(event.type == sf::Event::Resized){
			game->updateSize(event.size.width,event.size.height);
			view.setCenter(event.size.width/2,event.size.height/2);
			view.setSize(event.size.width,event.size.height);
			window.setView(view);
			for (auto & element : box) {
				element->setArea(event.size.width - 100, event.size.height - 100);
				if(element->isCentered())
					element->setPosition(event.size.width,event.size.height);
			}

		}
		else if(event.type == sf::Event::Closed){
			window.close();
		}
		//Player name -
		//
		if(event.type == sf::Event::TextEntered){
			if(event.text.unicode == 8){
				if(playerName.length() > 0){
					playerName.pop_back();
				}
			}else if(event.text.unicode == 13){
				//Enter, meaning continue to game
				theme.stop();
				game->changeState(new playState(game, playerName));
			}
			else if(playerName.length() < 20)
				playerName += static_cast<char>(event.text.unicode);
		}
	}
}
