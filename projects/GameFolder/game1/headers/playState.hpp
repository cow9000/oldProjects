#ifndef PLAYSTATE_HPP
#define PLAYSTATE_HPP

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <string>
#include <stack>
#include "gamestate.hpp"

class Area;
class Player;
class Game;
class Entity;

class playState : public gamestate{
	public:	
		playState(Game * g, std::string name);
		~playState();
		void drawState(sf::RenderWindow & window);
		void event(sf::RenderWindow & window);
		void update();
		//Entities have been removed from the playState and have been added to the Area. As to only draw a certain amount of entities.
		void pushArea(Area * area);
		void popArea();
		void changeArea(Area * area);
		Area * returnArea();
		Player * returnPlayer();
		

	private:
		sf::Music theme;
		std::stack<Area*> areas;
		Player * player;
		Game * game;
		sf::View view;
	

};

#endif		
