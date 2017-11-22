#ifndef NEWGAMESTATE_HPP
#define NEWGAMESTATE_HPP

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <string>
#include "gamestate.hpp"

class Game;

class newGameState : public gamestate{
	public:	
		newGameState(Game * g);
		~newGameState();
		void drawState(sf::RenderWindow & window);
		void event(sf::RenderWindow & window);
	private:
		Game* game;
		sf::Clock clock;
		sf::Music theme;
		sf::Text text;
		sf::Font font;
		sf::View view;
		int charGenPart;
		sf::Time elapsed;
		sf::Texture plus;
		sf::Texture minus;

		sf::Texture texture;
		sf::Texture top;
		sf::Texture topright;
		sf::Texture topleft;
		sf::Texture left;
		sf::Texture right;
		sf::Texture bottom;
		sf::Texture bottomleft;
		sf::Texture bottomright;
		sf::Texture box;
		sf::Texture def;
		sf::Texture scroll;
		//Character
		std::string characterName;
		int gender; // 0 = Male, 1 = Female
		
		int con;
		int dex;
		int intel;
		int str;
		int wis;
		int cha;
		int points;
		
		int scrollbar;
		int move;
		int select;

		//TEMP VARS
		int tempGender;
		int tempForward;
		
		int highlight;

		sf::Text charname;
		sf::Text female;
		sf::Text male;
		sf::Text back;
		sf::Text next;
		sf::FloatRect textRect;
		sf::Text stat;
		sf::FloatRect statRect;
		sf::Text race;
		sf::FloatRect raceRect;
		sf::Text stats;
		sf::Text races;
		sf::Text point;
		sf::FloatRect pointRect;
		sf::RectangleShape pm;
		int viewx;
		int viewy;
		int fade;
};

#endif
