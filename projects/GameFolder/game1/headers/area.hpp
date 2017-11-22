#ifndef AREA_HPP
#define AREA_HPP

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <iostream>
#include <cmath>

#include "entity.hpp"
#include "map.hpp"


class Area{
	public:
		virtual std::string returnTheme(){
			return theme;
		}

		virtual std::vector<Entity*> returnEntities(){
			return entities;
		}

		virtual void draw(sf::RenderWindow & window){
			window.draw(map);
			//window.draw(layerTwo);
		}
		virtual int returnTyleType(int _x, int _y, int _width, int _height){
			
			int tileX = std::ceil((_x)/32);
			int tileY = std::floor((_y + _height)/32);
			std::cout << "Tile X" << tileX << std::endl;
			int returnTile = 0;
			if(!level[tileX + tileY * widthOfArray] == 0)
				if(tileX < widthOfArray)
					if(tileY < heightOfArray)
						if(_x  > 0)
							if(_y > 0)
								returnTile = level[tileX + tileY * widthOfArray];
				
	
			
			std::cout << _x << std::endl;
			return returnTile;
		}
	protected:
		Map map;
		std::string path;
		std::string theme;
		std::vector<Entity*> entities;
		int *level;
		int sizeOfArray;
		int widthOfArray;
		int heightOfArray;
};

#endif
