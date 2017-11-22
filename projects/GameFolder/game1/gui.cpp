#include <SFML/Graphics.hpp>
#include <math.h>
#include <string>
#include "headers/gui.hpp"

Gui::Gui(){
	//LOAD THE SPRITESHEETS
	if (!Arrows.loadFromFile("data/sprites/ui/Arrows/_sheet_arrows.png")){
		
	}
	if (!Bars.loadFromFile("data/sprites/ui/Bars/_bar_sheet.png")){
		
	}
	if (!Buttons.loadFromFile("data/sprites/ui/Buttons/Add & Subtract/_button_sheet.png")){
		
	}
	if (!Checkmarks.loadFromFile("data/sprites/ui/Checkmarks/_checkmark_sheet.png")){
		
	}
	if (!Dividers.loadFromFile("data/sprites/ui/Dividers/_sheet_dividers.png")){
		
	}
	if (!Equipment.loadFromFile("data/sprites/ui/Equipment/_equipment_sheet.png")){
		
	}
	if (!Hearts.loadFromFile("data/sprites/ui/Hearts/_hearts_sheet.png")){
		
	}
	if (!Scrolling.loadFromFile("data/sprites/ui/Scrolling/_scrolling_sheet.png")){
		
	}

	for(int i = 1; i < 31; i++){
		//if (!Windows.loadFromFile("data/sprites/ui/Windows/_sheet_window.png")){}
		if (!w.loadFromFile("data/sprites/ui/Windows/_sheet_window_" + std::to_string((i)) + ".png")){}
		Windows.push_back(w);

	}

}

void Gui::setTexture(int type, int block, int spritesheet){
	if(spritesheet == 9){
		//16 by 16
		//Type corresponds with the type or style of thing being displayed. 
		
		//80x64 1 through 26 excluding 25
		if(type > 0 && type <= 26 && type != 25){
			//The sprite is 80 by 64
			//5 blocks by 4 blocks
			
			

			//Check if the block is not more then allowed by the sprite sheet
			if(block/20 > 0) return;

			int x = block*16 - (std::floor(block/5) * 80);
			int y = std::floor(block/5) * 16;
			
			texture.loadFromImage(Windows[type - 1], sf::IntRect(x, y, 16, 16));
		}else if (type == 29){
			//Sprite size is 224 by 64
			//IGNORE FOR NOW, MAY PUT IN LATER
		}else{
			//Sprite size is 64 x 64
			//4 by 4
			if(block/20 > 0) return;

			int x = block*16 - (std::floor(block/4) * 64);
			int y = std::floor(block/4) * 16;
			
			texture.loadFromImage(Windows[type - 1], sf::IntRect(x, y, 16, 16));
		}
	}
}

sf::Texture & Gui::returnTexture(){
	return texture;
}

sf::Sprite & Gui::returnSprite(){
	sprite.setTexture(texture);
	return sprite;
}

//BOX CLASS INFORMATION
//spritesheet is 9
Box::Box(int _x, int _y, int _width, int _height, int _type, Gui* _gui, std::string _text, int _textSize, sf::Color _color, sf::Font & _font, bool _centered){
	x = _x;
	y = _y;
	width = _width;
	height = _height;
	type = _type;
	gui = _gui;
	textString = _text;
	textSize = _textSize;
	color = _color;
	font = _font;
	//How many blocks are in this 
	spriteWidth = width/16;
	spriteHeight = height/16;

	text.setFont(font);
	text.setString(textString);
	text.setCharacterSize(textSize);
	text.setFillColor(color);
	text.setOutlineColor(sf::Color::Black);
	text.setOutlineThickness(1);

	centered = _centered;

	textRect = text.getLocalBounds();
	
	rectangle.setSize(sf::Vector2f(std::ceil(spriteWidth) * 16 + 8, std::ceil(spriteHeight) * 16 + 8));
}

void Box::setX(int _x){
	x = _x;
}
void Box::setY(int _y){
	y = _y;
}

int Box::returnX(){
	return x;
}
int Box::returnY(){
	return y;
}
int Box::returnWidth(){
	return width;
}
int Box::returnHeight(){
	return height;
}

void Box::setPosition(int _x, int _y){
	setX(_x);
	setY(_y);
}

void Box::setArea(int _width, int _height){
	width = _width;
	height = _height;
}

void Box::setString(std::string _textString){
	textString = _textString;
	text.setString(textString);
}

void Box::draw(sf::RenderWindow & window){
	//Update
	spriteWidth = width/16;
	spriteHeight = height/16;
	rectangle.setSize(sf::Vector2f(std::ceil(spriteWidth) * 16 + 8, std::ceil(spriteHeight) * 16 + 8));
	//x and y are the center of the object
	//width and height are dimensions of said object
	//type is the type of box it is
	
	//CALCULATIONS FOR THE HEIGHT AND WIDTH OF BOX	
	//16x16 sprites for each seperate box sprite
	//ASSUMING BLOCK IS 80x64
	if(type > 0 && type <= 26 && type != 25){
		for(int blockw = 0; blockw < std::ceil(spriteWidth)+1; blockw++){
			for(int blockh = 0; blockh < std::ceil(spriteHeight)+1; blockh++){
				//Set texture

				//Top left of box
				if(blockw == 0 && blockh == 0) gui->setTexture(type,0,9);
				//Top right of box			
				else if(blockw == std::ceil(spriteWidth) && blockh == 0) gui->setTexture(type,2,9);
			
				//Top middle
				else if(blockh == 0 && blockw != 0 && blockw != std::ceil(spriteWidth)) gui->setTexture(type,1,9);
				//Left middle
				else if(blockh != 0 && blockw == 0 && blockh != std::ceil(spriteHeight)) gui->setTexture(type,5,9);
				//Right middle
				else if(blockh != 0 && blockw == std::ceil(spriteWidth) && blockh != std::ceil(spriteHeight)) gui->setTexture(type,7,9);
				//Bottom middle
				else if(blockh == std::ceil(spriteHeight) && blockw != std::ceil(spriteWidth) && blockw != 0) gui->setTexture(type,11,9);

				//Bottom left of box
				else if(blockw == 0 && blockh == std::ceil(spriteHeight)) gui->setTexture(type,10,9);
				//Bottom right of box
				else if(blockw == std::ceil(spriteWidth) && blockh == std::ceil(spriteHeight)) gui->setTexture(type,12,9);
				//Center of box
				else gui->setTexture(type,6,9);
				//set texture of sprite
				s.setTexture(gui->returnTexture());
				//sf::Vector2f(SCRWIDTH/2.0f,SCRHEIGHT/2.0f)
			
				s.setPosition(x + blockw*16, y + blockh*16);
				s.setOrigin(x/2 + rectangle.getSize().x/2,y/2 + rectangle.getSize().y/2);

				rectangle.setPosition(x/2 - (std::ceil(spriteWidth) * 16)/2,y/2 - (std::ceil(spriteHeight) * 16)/2);
				window.draw(s);
				//window.draw(rectangle);
			}
		}
	}else{
		for(int blockw = 0; blockw < std::ceil(spriteWidth); blockw++){
			for(int blockh = 0; blockh < std::ceil(spriteHeight); blockh++){
				//Set texture

				//Top left of box
				if(blockw == 0 && blockh == 0) gui->setTexture(type,0,9);
				//Top right of box			
				else if(blockw == std::ceil(spriteWidth) && blockh == 0) gui->setTexture(type,2,9);
			
				//Top middle
				else if(blockh == 0 && blockw != 0 && blockw != std::ceil(spriteWidth)) gui->setTexture(type,1,9);
				//Left middle
				else if(blockh != 0 && blockw == 0 && blockh != std::ceil(spriteHeight)) gui->setTexture(type,4,9);
				//Right middle
				else if(blockh != 0 && blockw == std::ceil(spriteWidth) && blockh != std::ceil(spriteHeight)) gui->setTexture(type,6,9);
				//Bottom middle
				else if(blockh == std::ceil(spriteHeight) && blockw != std::ceil(spriteWidth) && blockw != 0) gui->setTexture(type,9,9);

				//Bottom left of box
				else if(blockw == 0 && blockh == std::ceil(spriteHeight)) gui->setTexture(type,8,9);
				//Bottom right of box
				else if(blockw == std::ceil(spriteWidth) && blockh == std::ceil(spriteHeight)) gui->setTexture(type,10,9);
				//Center of box
				else gui->setTexture(type,5,9);
				//set texture of sprite
				s.setTexture(gui->returnTexture());
				//sf::Vector2f(SCRWIDTH/2.0f,SCRHEIGHT/2.0f)
			
				s.setPosition(x + blockw*16, y + blockh*16);
				s.setOrigin(x/2 + rectangle.getSize().x/2,y/2 + rectangle.getSize().y/2);
				//rectangle.setPosition(x + blockw*16, y + blockh*16);
				rectangle.setPosition(x/2 - (std::ceil(spriteWidth) * 16)/2,y/2 - (std::ceil(spriteHeight) * 16)/2);
				window.draw(s);
			}
		}
	}
	//text.setOrigin(textRect.left + textRect.width/2.0f, textRect.top  + textRect.height/2.0f);
	text.setPosition(sf::Vector2f(x/2 - text.getGlobalBounds().width/2,y/2 - text.getGlobalBounds().height/2));

	window.draw(text);

}

bool Box::mouseInside(int _x, int _y){
	if(rectangle.getGlobalBounds().contains(sf::Vector2f(_x,_y))) return true;
	return false;
}

bool Box::isCentered(){
	return centered;
}

