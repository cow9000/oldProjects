#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP

#include <SFML/Graphics.hpp>
#include "game.hpp"
class gamestate{
	public:	
		virtual void drawState(sf::RenderWindow & window){
			//window.draw();
		}
		virtual void event(sf::RenderWindow & window){
			sf::Event event;
			while(window.pollEvent(event)){
				if(event.type == sf::Event::Closed){
					window.close();
				}
			}
		}
		virtual void update(){
			//UPDATE ALL GOES HERE
		}
	private:
		Game * game;
};


#endif
