#ifndef PORTCITYAREA_HPP
#define PORTCITYAREA_HPP

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include "area.hpp"
#include "entity.hpp"

class Map;


class portCityArea : public Area{
	public:
		portCityArea();
		~portCityArea();
		void draw(sf::RenderWindow & window);
	private:
		sf::Texture backgroundF;

};


#endif
