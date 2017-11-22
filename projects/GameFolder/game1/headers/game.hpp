#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include <stack>
class gamestate;

class Game{
	public:
		Game();
		sf::RenderWindow& returnWindow();
		void update();
		void render();

		//Game state stuff
		void pushState(gamestate * state);
		void popState();
		void changeState(gamestate * state);
		void updateSize(int _windowX, int _windowY);

		gamestate * returnGameState();
		void changeGameState(gamestate change);

		float returnMusicVolume();
		float returnSoundVolume();

		int returnWindowX();
		int returnWindowY();

	private:
		std::stack<gamestate*> states;
		sf::RenderWindow window;
		
		//GAME OPTIONS 0 to 100
		float musicVolume;
		float soundVolume;
		
		int windowX;
		int windowY;
};

#endif
