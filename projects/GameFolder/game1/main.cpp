#include <SFML/Graphics.hpp>
#include "headers/game.hpp"
#include "headers/openingState.hpp"
#include "headers/playState.hpp"
#include "headers/gui.hpp"
//https://opengameart.org/content/whispers-of-avalon-grassland-tileset
//Art, give proper credit.
int main(){
	//sf::RenderWindow w(sf::VideoMode(800,800), "Infinite");
	Game g;
	Gui g2;
	g.pushState(new openingState(&g, &g2));
	while(g.returnWindow().isOpen()){
		g.returnGameState()->event(g.returnWindow());
		g.update();
		g.render();
	}
}	
