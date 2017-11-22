#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include "headers/portCityArea.hpp"
#include "headers/map.hpp"

portCityArea::portCityArea(){
	theme = "data/music/1-05 Port Town.ogg";
	std::string background = "data/background/background.png";

	if (!backgroundF.loadFromFile(background)){}
	
	std::fstream file("data/mapData/map.txt");
	
	sizeOfArray = 0;
	widthOfArray = 0;
	heightOfArray = 0;
	std::string line;

	if(file.is_open()){
		while(getline(file, line)){
			sizeOfArray += line.length();
			widthOfArray = line.length();
		}
		heightOfArray = sizeOfArray/widthOfArray;
	}
	level = new int[sizeOfArray];
	file.close();
	int i = 0;
	file.open("data/mapData/map.txt");
	if(file.is_open()){
		while(getline(file, line)){

			for(int tile = 0; tile < line.length(); tile++){

				int numb = line[tile] - '0';			

				level[i] = numb;
				std::cout << line[tile];
				i++;
			}
		}
	}
	
	
	if (!map.load("data/sprites/terrain.png", sf::Vector2u(32, 32), level, widthOfArray, heightOfArray)){}
	
	
}


portCityArea::~portCityArea(){
	
}


void portCityArea::draw(sf::RenderWindow & window){

	sf::Sprite b(backgroundF);

	sf::Vector2f targetSize(window.getView().getSize().x, window.getView().getSize().y); 
	//Fix background
	b.setScale(
	    targetSize.x / b.getLocalBounds().width, 
	    targetSize.y / b.getLocalBounds().height);
	b.setOrigin(b.getLocalBounds().width/2, b.getLocalBounds().height/2);
	b.setPosition(window.getView().getCenter());

	//Draw stuff
	window.draw(b);
	window.draw(map);
}
