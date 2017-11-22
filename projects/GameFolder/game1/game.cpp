#include "headers/game.hpp"

#include <SFML/Graphics.hpp>
#include "headers/openingState.hpp"

Game::Game(){
	windowX = 800;
	windowY = 640;
	window.create(sf::VideoMode(windowX,windowY), "Lands of Evolution");
	window.setFramerateLimit(90);
	musicVolume = 100;
	soundVolume = 100;
}

void Game::pushState(gamestate * state){
	this->states.push(state);
	return;
}

void Game::popState(){
	delete this->states.top();
	return;
}

void Game::changeState(gamestate * state){
	if(! this->states.empty())
		popState();
	pushState(state);
	return;
}


sf::RenderWindow& Game::returnWindow(){
	return window;
}

void Game::update(){
	this->states.top()->update();
}

void Game::render(){

	//THIS CODE WILL BE IN THE GAME STATE;
	window.clear(sf::Color::Black);
	//THIS IS WHERE EVERYTHING WILL BE DRAWN	
	this->states.top()->drawState(window);
	window.display();
}

void Game::updateSize(int _windowX, int _windowY){
	windowX = _windowX;
	windowY = _windowY;
}

gamestate * Game::returnGameState(){
	return this->states.top();
}


//SETTINGS
float Game::returnMusicVolume(){
	return musicVolume;
}
float Game::returnSoundVolume(){
	return soundVolume;
}
int Game::returnWindowX(){
	return windowX;
}
int Game::returnWindowY(){
	return windowY;
}



