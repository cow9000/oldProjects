#ifndef NEWGAMESTATE_HPP
#define NEWGAMESTATE_HPP
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include <vector>

#include "gamestate.hpp"

class Game;
class Gui;
class Box;

class newGameState : public gamestate{
	public:
		newGameState(Game * g, Gui * g2);
		~newGameState();
		void drawState(sf::RenderWindow & window);
		void event(sf::RenderWindow & window);
	private:
		Game* game;
		Gui* gui;
		sf::Music theme;
		sf::View view;
		sf::Font font;
		sf::Texture background;
		
		std::vector<Box*> box;
		std::string playerName;
};

#endif
