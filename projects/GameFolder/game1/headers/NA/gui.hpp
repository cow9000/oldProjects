#ifndef GUI_HPP
#define GUI_HPP

#include <SFML/Graphics.hpp>

namespace gui{

	void drawBox(sf::Texture* top, sf::Texture* topright, sf::Texture* topleft,
	sf::Texture* left, sf::Texture* right, sf::Texture* bottom, sf::Texture* bottomleft,
	sf::Texture* bottomright, sf::Texture* box, sf::RenderWindow & window, int width, int height, int x, int y, int type){
				
		//WIDTH
		for(int cordx = 0; cordx - 1 < width/32 - 1; cordx++){
			for(int cordy = 0; cordy - 1 < height/32 - 1; cordy++){
				sf::RectangleShape rectangle(sf::Vector2f(32, 32));
				if(cordx == 0 && cordy == 0) rectangle.setTexture(topleft);
				else if(cordx == width/32 -1 && cordy == height/32 -1) rectangle.setTexture(bottomright);
				else if(cordx == 0 && cordy == height/32-1) rectangle.setTexture(bottomleft);
				else if(cordx == width/32-1 && cordy == 0) rectangle.setTexture(topright);
				else if(cordx > 0 && cordy == 0) rectangle.setTexture(top);
				else if(cordx == width/32-1 && cordy > 0) rectangle.setTexture(right);
				else if(cordx > 0 && cordy == height/32-1) rectangle.setTexture(bottom);
				else if(cordx == 0) rectangle.setTexture(left);
				else rectangle.setTexture(box);
				
				if(type == 1) rectangle.setFillColor(sf::Color::Green);
				if(type == 2) rectangle.setFillColor(sf::Color::Blue);
				
				rectangle.setPosition((cordx*32) + (x - (width/2)), (cordy*32) + (y - (height/2)));
				window.draw(rectangle);	
			}
		}
		
		
	}

	bool enteredGUI(int x, int y, int width, int height, int mousex, int mousey){
		//-20 Due to view centered on 400,320.
		y = y-20;
		if(mousex >= (x-(width/2)) && mousex <= (x+(width/2))){
			if(mousey >= (y-(height/2)) && mousey <= (y+(height/2))){
				return true;
			}
		}
		return false;
	}

	bool enteredBox(int x, int y, int width, int height, int mousex, int mousey){
		y = y-20;
		if(mousex >= x && mousex <= x+width){
			if(mousey >= y && mousey <= y+height){
				return true;
			}
		}
		return false;
	}

};

#endif
