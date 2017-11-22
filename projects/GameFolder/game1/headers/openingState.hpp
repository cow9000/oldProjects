#ifndef OPENINGSTATE_HPP
#define OPENINGSTATE_HPP
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "gamestate.hpp"

#include <vector>

class Game;
class Gui;
class Box;

class openingState : public gamestate{
	public:
		openingState(Game * g, Gui * g2);
		~openingState();
		void drawState(sf::RenderWindow & window);
		void event(sf::RenderWindow & window);
	private:
		Game* game;
		Gui* gui;

		sf::Texture background;

		sf::Font font;
		
		sf::Music theme;
		sf::View view;

		std::vector<Box*> box;
		
};

#endif
