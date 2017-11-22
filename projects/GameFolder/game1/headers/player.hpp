#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <vector>
#include <string>

#include "entity.hpp"

class playState;
class Map;

class Player : public Entity{
	public:
		//THIS IS ONE THAT HAS BEEN CREATED BY NEW GAME
		Player(std::string _name, Area * _area);
		//NEED TO CREATE ANOTHER ONE FOR CONTINUE GAME (LOADING CHARACTER)
		~Player();
		void entityLoop();
		void eventMove();
	private:
		bool noKeyWasPressed;
		bool jumping;

};


#endif
