#include "headers/player.hpp"
#include "headers/portCityArea.hpp"
#include "headers/playState.hpp"
#include "headers/area.hpp"

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <stack>

playState::playState(Game * g, std::string name){
	game = g;

	//Create player
	
	
	view.setSize(game->returnWindowX(),game->returnWindowY());
	//view.zoom(0.5f);
	
	changeArea(new portCityArea());
	player = new Player(name,returnArea());

	float X = player->returnX();
	float Y = player->returnY();

	view.setCenter(X,Y);
	
}

playState::~playState(){
	
}

void playState::drawState(sf::RenderWindow & window){
	
	float X = player->returnX();
	float Y = player->returnY();
	view.setCenter(X,Y);
	window.setView(view);

	areas.top()->draw(window);
	player->entityLoop();
	player->drawEntity(window);
	//Draw the entities
	for (auto & element : areas.top()->returnEntities()) {
		element->entityLoop();
		element->drawEntity(window);
	}
	
}

void playState::update(){
	
}

void playState::event(sf::RenderWindow & window){
	sf::Event event;
	while(window.pollEvent(event)){
		if(event.type == sf::Event::Resized){
			view.setSize(event.size.width, event.size.height);
			window.setView(view);
		}
		if(event.type == sf::Event::Closed){
			window.close();
		}
	}
}

void playState::pushArea(Area * area){
	this->areas.push(area);
	if(!theme.openFromFile(areas.top()->returnTheme())){}
	theme.play();
	theme.setLoop(true);
	theme.setVolume(game->returnMusicVolume());
	return;
}

void playState::popArea(){
	delete this->areas.top();
	return;
}

void playState::changeArea(Area * area){
	if(! this->areas.empty())
		popArea();
	pushArea(area);
	return;
}


Area * playState::returnArea(){
	return this->areas.top();
}

Player * playState::returnPlayer(){
	return player;
}

