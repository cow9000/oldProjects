#ifndef GUI_HPP
#define GUI_HPP

#include <SFML/Graphics.hpp>
#include <string>
#include <vector>

class Gui{
	public:
		Gui();
		void setTexture(int type, int block, int spritesheet);
		sf::Sprite & returnSprite();
		sf::Texture & returnTexture();
	private:
		//Image of spritesheets
		sf::Image Arrows;
		sf::Image Bars;
		sf::Image Buttons;
		sf::Image Checkmarks;
		sf::Image Dividers;
		sf::Image Equipment;
		sf::Image Hearts;
		sf::Image Scrolling;
		std::vector<sf::Image> Windows;

		//Temp
		sf::Image w;

		//For the actual image
		sf::Texture texture;
		sf::Sprite sprite;
};

class Box{
	public:
		Gui * gui;
		Box(int _x, int _y, int _width, int _height, int _type, Gui * _gui, std::string _text, int _textSize, sf::Color _color, sf::Font & _font, bool _centered);
		void draw(sf::RenderWindow & window);

		void setX(int _x);
		void setY(int _y);

		int returnX();
		int returnY();
		int returnWidth();
		int returnHeight();

		void setPosition(int _x, int _y);
		void setArea(int _width, int _height);
		void setString(std::string _textString);

		bool mouseInside(int _x, int _y);
		bool isCentered();
		
	private:
		int x;
		int y;
		int width;
		int height;
		int type;
		
		float spriteWidth;
		float spriteHeight;

		//TEXT
		std::string textString;
		int textSize;
		sf::Text text;
		sf::Color color;
		sf::FloatRect textRect;
		sf::Font font;

		sf::Sprite s;
		sf::RectangleShape rectangle;

		bool centered;

		
};


#endif
