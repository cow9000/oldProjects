#include <SFML/Audio.hpp>
#include <math.h>
#include "headers/newGameState.hpp"
#include "headers/game.hpp"
#include "headers/gui.hpp"
#include "headers/playState.hpp"
#include "headers/player.hpp"
#include "headers/portCityArea.hpp"

newGameState::newGameState(Game * g){
	game = g;
	if(!theme.openFromFile("data/music/1-10 Brazen.ogg")) 
	{//ERROR
		
	}//1-08 Puzzles.ogg
	theme.setVolume(20.0f);
	if (!font.loadFromFile("data/font/BLKCHCRY.ttf"))
	{
	    // error...
	}

	//Background texture
	if(!texture.loadFromFile("data/background/characterGen.jpg")){
		//Error
	}
	//LOAD ALL BORDER TEXTURES
	if (!top.loadFromFile("data/sprites/Borders/borderWoodTop.png")){
	    // error...
	}
	if (!topleft.loadFromFile("data/sprites/Borders/borderWoodTopLeft.png")){
	    // error...
	}
	if (!topright.loadFromFile("data/sprites/Borders/borderWoodTopRight.png")){
	    // error...
	}
	if (!left.loadFromFile("data/sprites/Borders/borderWoodLeft.png")){
	    // error...
	}
	if (!right.loadFromFile("data/sprites/Borders/borderWoodRight.png")){
	    // error...
	}
	if (!bottomleft.loadFromFile("data/sprites/Borders/borderWoodBottomLeft.png")){
	    // error...
	}
	if (!bottomright.loadFromFile("data/sprites/Borders/borderWoodBottomRight.png")){
	    // error...
	}
	if (!bottom.loadFromFile("data/sprites/Borders/borderWoodBottom.png")){
	    // error...
	}
	if (!box.loadFromFile("data/sprites/Borders/borderWood.png")){
	    // error...
	}
	if (!plus.loadFromFile("data/sprites/Borders/borderWoodPlus.png")){
	    // error...
	}
	if (!minus.loadFromFile("data/sprites/Borders/borderWoodMinus.png")){
	    // error...
	}
	if (!def.loadFromFile("data/sprites/Borders/borderWoodDefault.png")){
	    // error...
	}
	if (!scroll.loadFromFile("data/sprites/Borders/borderWoodScroll.png")){
	    // error...
	}
	text.setFont(font); // font is a sf::Font
	text.setString("Character Name");
	text.setCharacterSize(48); // in pixels, not points!
	sf::FloatRect textRect = text.getLocalBounds();
	text.setOrigin(textRect.left + textRect.width/2.0f,
	textRect.top  + (textRect.height + 10)/2.0f);
	text.setPosition(400,120);
	pm.setSize(sf::Vector2f(32, 32));
	theme.play();
	theme.setLoop(true);
	charGenPart = 0;
	tempForward = 0;
	gender = 0;
	select = 0;
	con = 0;
	intel = 0;
	dex = 0;
	str = 0;
	cha = 0;
	wis = 0;
	points = 6;
	scrollbar = 200;
	select = 1;
	//for + and - buttons in stats
	highlight = 0;
	viewx = 400;
	viewy = 320;
	fade = 0;

}

newGameState::~newGameState(){
	delete &clock;
	delete &theme;
	delete &text;
	delete &font;
	delete &view;
	delete &charGenPart;
	delete &plus;
	delete &minus;
	delete &texture;
	delete &top;
	delete &topright;
	delete &topleft;
	delete &left;
	delete &right;
	delete &bottom;
	delete &def;
	delete &scroll;
	delete &characterName;
	delete &gender;
	delete &con;
	delete &dex;
	delete &intel;
	delete &str;
	delete &wis;
	delete &cha;
	delete &points;
	delete &scrollbar;
	delete &move;
	delete &scrollbar;
	delete &tempGender;
	delete &tempForward;
	delete &highlight;
	delete &charname;
	delete &female;
	delete &male;
	delete &back;
	delete &next;
	delete &textRect;
	delete &stat;
	delete &statRect;
	delete &race;
	delete &raceRect;
	delete &stats;
	delete &races;
	delete &point;
	delete &pointRect;
	delete &pm;
}

void newGameState::drawState(sf::RenderWindow & window){

	back.setFont(font); // font is a sf::Font
	back.setString("Back");
	back.setCharacterSize(24); // in pixels, not points!
	back.setPosition(69,545 + (view.getCenter().y - 320));

	next.setFont(font); // font is a sf::Font
	next.setString("Next");
	next.setCharacterSize(24); // in pixels, not points!
	next.setPosition(669,545 + (view.getCenter().y - 320));

	sf::Sprite background(texture);

	sf::Vector2u TextureSize = texture.getSize(); //Get size of texture.
	sf::Vector2u WindowSize = window.getSize();             //Get size of window.

	float ScaleX = (float) WindowSize.x / TextureSize.x;
	float ScaleY = (float) WindowSize.y / (TextureSize.y - 20);     //Calculate scale.

	background.setTexture(texture);
	background.setScale(ScaleX, ScaleY); 
	background.setPosition((view.getCenter().x - 400),(view.getCenter().y - 320));

	window.draw(background);

	switch(charGenPart){
		case 0:
			if(tempForward == 0){
				gui::drawBox(&top, &topright, &topleft, &left, &right, &bottom, &bottomleft, &bottomright, &box, window, 128,64, 700,560,0);	
			}else if(tempForward == 2){
				gui::drawBox(&top, &topright, &topleft, &left, &right, &bottom, &bottomleft, &bottomright, &box, window, 128,64, 700,560,1);	
			}
			window.draw(next);


			charname.setFont(font);
			charname.setString("Insert Character Name");
			if(characterName.size() > 0)
				charname.setString(characterName);
			charname.setCharacterSize(26);
			textRect = charname.getLocalBounds();
			charname.setOrigin(textRect.left + textRect.width/2.0f,
				       textRect.top  + (textRect.height + 10)/2.0f);
			charname.setPosition(sf::Vector2f(800/2.0f,195));
			gui::drawBox(&top, &topright, &topleft, &left, &right, &bottom, &bottomleft, &bottomright, &box, window, (round(textRect.width/32) * 32 + 64) ,96, 400,160,0);
			gui::drawBox(&top, &topright, &topleft, &left, &right, &bottom, &bottomleft, &bottomright, &box, window, 32*12,96, 400,120,0);

			
			male.setFillColor(sf::Color::White);
			female.setFillColor(sf::Color::White);
			male.setFont(font); // font is a sf::Font
			male.setString("Male");
			male.setCharacterSize(24); // in pixels, not points!
			male.setPosition(275,252);

			
			female.setFont(font); // font is a sf::Font
			female.setString("Female");
			female.setCharacterSize(24); // in pixels, not points!
			female.setPosition(463,252);

			//GENDER BOXES
			if(gender == 0){
				gui::drawBox(&top, &topright, &topleft, &left, &right, &bottom, &bottomleft, &bottomright, &box, window, 96,64, 300,270,1);
				if(tempGender == 2){
				gui::drawBox(&top, &topright, &topleft, &left, &right, &bottom, &bottomleft, &bottomright, &box, window, 96,64, 500,270,2);
				}else{
					gui::drawBox(&top, &topright, &topleft, &left, &right, &bottom, &bottomleft, &bottomright, &box, window, 96,64, 500,270,0);
				}
				male.setFillColor(sf::Color::Green);
			}else{
				if(tempGender == 1){
					gui::drawBox(&top, &topright, &topleft, &left, &right, &bottom, &bottomleft, &bottomright, &box, window, 96,64, 300,270,2);
				}else{
					gui::drawBox(&top, &topright, &topleft, &left, &right, &bottom, &bottomleft, &bottomright, &box, window, 96,64, 300,270,0);
				}
				gui::drawBox(&top, &topright, &topleft, &left, &right, &bottom, &bottomleft, &bottomright, &box, window, 96,64, 500,270,1);
				female.setFillColor(sf::Color::Green);
			}
			
			
			
			view = window.getDefaultView();
			//view.zoom(0.5f);
			view.setCenter(400,320);
			window.setView(view);
			window.draw(female);
			window.draw(male);
			window.draw(text);
			window.draw(charname);
			break;
		/*
		STATS.
		
		*/
		case 1:

			if(tempForward == 0){
				gui::drawBox(&top, &topright, &topleft, &left, &right, &bottom, &bottomleft, &bottomright, &box, window, 128,64, 100,560,0);
				gui::drawBox(&top, &topright, &topleft, &left, &right, &bottom, &bottomleft, &bottomright, &box, window, 128,64, 700,560,0);	
			}else if(tempForward == 1){
				gui::drawBox(&top, &topright, &topleft, &left, &right, &bottom, &bottomleft, &bottomright, &box, window, 128,64, 100,560,1);
				gui::drawBox(&top, &topright, &topleft, &left, &right, &bottom, &bottomleft, &bottomright, &box, window, 128,64, 700,560,0);	
			}else if(tempForward == 2){
				gui::drawBox(&top, &topright, &topleft, &left, &right, &bottom, &bottomleft, &bottomright, &box, window, 128,64, 100,560,0);
				gui::drawBox(&top, &topright, &topleft, &left, &right, &bottom, &bottomleft, &bottomright, &box, window, 128,64, 700,560,1);	
			}
			

			gui::drawBox(&top, &topright, &topleft, &left, &right, &bottom, &bottomleft, &bottomright, &box, window, 32*10,460, 400,300,0);
			gui::drawBox(&top, &topright, &topleft, &left, &right, &bottom, &bottomleft, &bottomright, &box, window, 32*12,96, 400,120,0);

			stat.setFont(font); // font is a sf::Font
			stat.setString("Stats");
			stat.setCharacterSize(36); // in pixels, not points!
			statRect = stat.getLocalBounds();
			stat.setOrigin(statRect.left + statRect.width/2.0f,
			statRect.top  + (statRect.height + 10)/2.0f);
			stat.setPosition(400,110);

			point.setFont(font);
			point.setString("Points to spend - " + std::to_string(points));
			point.setCharacterSize(24); // in pixels, not points!
			pointRect = point.getLocalBounds();
			point.setOrigin(pointRect.left + pointRect.width/2.0f,
			pointRect.top  + (pointRect.height + 10)/2.0f);
			point.setPosition(400,145);
			
			//PLUS AND MINUS
			for(int i = 0; i < 6; i++){
				stats.setString("Constitution:");

				if(i == 0) stats.setString("Constitution: " + std::to_string(con));
				else if(i == 1) stats.setString("Dexterity: " + std::to_string(dex));
				else if(i == 2) stats.setString("Intelligence: " + std::to_string(intel));
				else if(i == 3) stats.setString("Strength: " + std::to_string(str));
				else if(i == 4) stats.setString("Wisdom: " + std::to_string(wis));
				else if(i == 5) stats.setString("Charisma: " + std::to_string(cha));

				

				stats.setFont(font); // font is a sf::Font
				stats.setCharacterSize(24); // in pixels, not points!
				stats.setPosition(270,200 + (48*i));
				window.draw(stats);
				pm.setFillColor(sf::Color::White);
				pm.setTexture(&plus);
				pm.setPosition(450,200 + (48*i));
				//1 + Con
				//-1 - Con
				if(highlight == i+1 && i == highlight-1) pm.setFillColor(sf::Color::Green);

				window.draw(pm);
				

				pm.setFillColor(sf::Color::White);
				pm.setTexture(&minus);
				pm.setPosition(498,200 + (48*i));

				if(highlight == (i+1) * -1 && i == (highlight * -1) - 1) pm.setFillColor(sf::Color::Green);

				window.draw(pm);
			}
			view = window.getDefaultView();
			//view.zoom(0.5f);
			view.setCenter(400,320);
			window.setView(view);

			
			window.draw(next);
			window.draw(back);
			window.draw(stat);
			window.draw(point);
			break;
		case 2:
			view = window.getDefaultView();
			//view.zoom(0.5f);
			view.setCenter(viewx,viewy);
			window.setView(view);
			gui::drawBox(&top, &topright, &topleft, &left, &right, &bottom, &bottomleft, &bottomright, &box, window, 32*10,600, 400,460 + (view.getCenter().y - 320),0);


			next.setString("Start");
			if(tempForward == 0){
				gui::drawBox(&top, &topright, &topleft, &left, &right, &bottom, &bottomleft, &bottomright, &box, window, 128,64, 100,560 + (view.getCenter().y - 320),0);
				gui::drawBox(&top, &topright, &topleft, &left, &right, &bottom, &bottomleft, &bottomright, &box, window, 128,64, 700,560 + (view.getCenter().y - 320),0);	
			}else if(tempForward == 1){
				gui::drawBox(&top, &topright, &topleft, &left, &right, &bottom, &bottomleft, &bottomright, &box, window, 128,64, 100,560 + (view.getCenter().y - 320),1);
				gui::drawBox(&top, &topright, &topleft, &left, &right, &bottom, &bottomleft, &bottomright, &box, window, 128,64, 700,560 + (view.getCenter().y - 320),0);	
			}else if(tempForward == 2){
				gui::drawBox(&top, &topright, &topleft, &left, &right, &bottom, &bottomleft, &bottomright, &box, window, 128,64, 100,560 + (view.getCenter().y - 320),0);
				gui::drawBox(&top, &topright, &topleft, &left, &right, &bottom, &bottomleft, &bottomright, &box, window, 128,64, 700,560 + (view.getCenter().y - 320),1);	
			}

			//RACE select
			
			race.setFont(font); // font is a sf::Font
			race.setString("Race");
			race.setCharacterSize(36); // in pixels, not points!
			raceRect = race.getLocalBounds();
			race.setOrigin(raceRect.left + raceRect.width/2.0f,
			raceRect.top  + (raceRect.height + 10)/2.0f);
			race.setPosition(400,110  + (view.getCenter().y - 320));

			//25 races aye?


			for(int i = 0; i < 25; i++){
				races.setString("Human");
				if(i == 1){races.setString("Elf");}
				else if(i == 2){races.setString("Orc");}
				else if(i == 3){races.setString("Goblin");}
				else if(i == 4){races.setString("Gnome");}
				else if(i == 5){races.setString("Dwarf");}
				else if(i == 6){races.setString("Halfling");}
				else if(i == 7){races.setString("Pixie/Fairy");}
				else if(i == 8){races.setString("Draconian");}
				else if(i == 9){races.setString("Vampire");}
				else if(i == 10){races.setString("Werewolf");}
				else if(i == 11){races.setString("Giant");}
				else if(i == 12){races.setString("Centaur");}
				else if(i == 13){races.setString("Minotaur");}
				else if(i == 14){races.setString("Satyr");}
				else if(i == 15){races.setString("Harpie");}
				else if(i == 16){races.setString("Naga");}
				else if(i == 17){races.setString("Magical Construct");}
				else if(i == 18){races.setString("Merfolk");}
				else if(i == 19){races.setString("Lacertan");}
				else if(i == 20){races.setString("Bastes");}
				else if(i == 21){races.setString("Lupusen");}
				else if(i == 22){races.setString("Odenet");}
				else if(i == 23){races.setString("Gargoyle");}
				else if(i == 24){races.setString("Aranea");}

				races.setFont(font); // font is a sf::Font
				races.setCharacterSize(24); // in pixels, not points!
				races.setPosition(320,200 - (2.5*(scrollbar - 200)) + (48*i));
				

				pm.setFillColor(sf::Color::White);
				pm.setTexture(&def);
				pm.setPosition(260,200 - (2.5*(scrollbar - 200)) + (48*i));


				if(highlight == i+1 && i == highlight-1) pm.setFillColor(sf::Color::Green);
				if(select == i+1) pm.setFillColor(sf::Color::Blue);

				
				if(2.5*(scrollbar - 200) - (48*(i) + 128) < 0){
					window.draw(races);
					window.draw(pm);
				}
			}

			pm.setFillColor(sf::Color::White);
			pm.setTexture(&scroll);
			pm.setPosition(543,scrollbar);
			if(highlight == 27) pm.setFillColor(sf::Color::Green);
			if(move == 1) pm.setFillColor(sf::Color::Blue);
			window.draw(pm);

			//RACE Text box
			gui::drawBox(&top, &topright, &topleft, &left, &right, &bottom, &bottomleft, &bottomright, &box, window, 32*12,96, 400,120 + (view.getCenter().y - 320),0);
			window.draw(race);
			window.draw(next);
			window.draw(back);
			if(fade == 1){
				sf::RectangleShape rectangle(sf::Vector2f(800, 700));
				elapsed = clock.getElapsedTime();
				rectangle.setFillColor(sf::Color(0, 0, 0, elapsed.asMilliseconds()/1.90));
				window.draw(rectangle);
				theme.setVolume(20.0f - (elapsed.asMilliseconds() / 100));
				if(elapsed.asSeconds() >= 0.5f){
					//PASS ALL VARIABLES NEEDED TO PLAYSTATE
					theme.stop();
					game->changeState(new playState(game, str, con, intel, cha, dex, wis, select));
				}
			}
			break;
			
			
	}
}

void newGameState::event(sf::RenderWindow & window){
	sf::Event event;
	while(window.pollEvent(event)){
		if(event.type == sf::Event::Closed){
			window.close();
		}

		if (event.type == sf::Event::MouseMoved){
			//128,64, 700,560,
			if(gui::enteredGUI( 100, 560, 128, 64, event.mouseMove.x, event.mouseMove.y) && charGenPart != 0){
				tempForward = 1;
			}else if(gui::enteredGUI( 700, 560, 128, 64, event.mouseMove.x, event.mouseMove.y)){
				tempForward = 2;
			}else{
				tempForward = 0;
			}
		}

		//NEXT AND BACK
		if (event.type == sf::Event::MouseButtonPressed){
			if(event.mouseButton.button == sf::Mouse::Left){
				if(tempForward == 1) {tempForward = 0; charGenPart -= 1;}
			}
			if(event.mouseButton.button == sf::Mouse::Left){
				if(tempForward == 2 && charGenPart != 2) {tempForward = 0; charGenPart ++;}
				else if(tempForward == 2 && charGenPart == 2){
					clock.restart();
					fade = 1;
				}
				
			}
		}

			//Tempgender here is going to be used as the back button, 3 = back, 4 = forward

		if(charGenPart == 0){	
			if (event.type == sf::Event::TextEntered)
			{
				if(event.text.unicode == 13){
					clock.restart();
					charGenPart = 1;	
				}
				else if(event.text.unicode == 8){
					if(characterName.size() > 0)			
						characterName.erase( characterName.size() - 1 );
				}
			    else if (event.text.unicode < 128){
					if(characterName.size() < 30)
						characterName += (char)event.text.unicode;
				}
			}
			if (event.type == sf::Event::MouseMoved)
			{
				
				if(gender == 0){	
					if(gui::enteredGUI(500, 270, 96, 64,event.mouseMove.x, event.mouseMove.y)){
						tempGender = 2;
					}else{
						tempGender = 0;
					}
				}
				else if (gender == 1){	
					if(gui::enteredGUI(300, 270, 96, 64,event.mouseMove.x, event.mouseMove.y)){
						tempGender = 1;
					}else{
						tempGender = 0;
					}
				}
			}
			if (event.type == sf::Event::MouseButtonPressed){
				if(event.mouseButton.button == sf::Mouse::Left){
					if(tempGender == 2) {gender = 1; tempGender = 0;}
					else if(tempGender == 1) {gender = 0; tempGender = 0;}
				}
			}
		}else if(charGenPart == 1){
			//128,64, 100,560
			if (event.type == sf::Event::MouseMoved){
				
				for(int i = 0; i < 6; i++){
					
					if(gui::enteredBox(450,200 + (48*i), 32, 32, event.mouseMove.x, event.mouseMove.y)){
						highlight = i + 1;
						i = 6;
					}else if(gui::enteredBox(498,200 + (48*i), 32, 32, event.mouseMove.x, event.mouseMove.y)){
						highlight = (i + 1) * -1;
						i = 6;
					}else{
						highlight = 0;
					}
				}
			}
			if (event.type == sf::Event::MouseButtonPressed){
				if(event.mouseButton.button == sf::Mouse::Left){
					if(highlight == 1) {if(points != 0){con += 1; points -=1;}}
					else if(highlight == 2) {if(points != 0){dex += 1; points -=1;}}
					else if(highlight == 3) {if(points != 0){intel += 1; points -=1;}}
					else if(highlight == 4) {if(points != 0){str += 1; points -=1;}}
					else if(highlight == 5) {if(points != 0){wis += 1; points -=1;}}
					else if(highlight == 6) {if(points != 0){cha += 1; points -=1;}}
					else if(highlight == -1) {if(con!=-3){con -= 1; points++;}}
					else if(highlight == -2) {if(dex!=-3){dex -= 1; points++;}}
					else if(highlight == -3) {if(intel!=-3){intel -= 1; points++;}}
					else if(highlight == -4) {if(str!=-3){str -= 1; points++;}}
					else if(highlight == -5) {if(wis!=-3){wis -= 1; points++;}}
					else if(highlight == -6) {if(cha!=-3){cha -= 1; points++;}}
				}
			}
		}else if(charGenPart == 2){
			if (event.type == sf::Event::MouseMoved){
				
				for(int i = 0; i < 26; i++){
					
					if(gui::enteredBox(260,200 - (2.5*(scrollbar - 200)) +(48*i) - (view.getCenter().y - 320), 32, 32, event.mouseMove.x, event.mouseMove.y)){
						highlight = i + 1;
						i = 26;
					}else if(gui::enteredBox(543,scrollbar, 32, 32, event.mouseMove.x, event.mouseMove.y)){
						highlight = 27;
					}else{
						highlight = 0;
						move = 0;
					}
				}
				//Scrollbar movement
				if(move == 1){
					if(scrollbar >= 200 && scrollbar <= 580 && event.mouseMove.y >= 200 && event.mouseMove.y + 20 <= 580) {
						scrollbar = event.mouseMove.y;
					}
				}
			}
			if (event.type == sf::Event::MouseButtonPressed){
				//RACE AND SCROLLBAR
				//SCROLL BAR IS HIGHLIGHT 27
				if(event.mouseButton.button == sf::Mouse::Left){
					if(highlight==27){
						move = 1;
					}else{
						if(highlight != 0) select = highlight;
					}
				}
			}
			if (event.type == sf::Event::MouseButtonReleased){
				if(event.mouseButton.button == sf::Mouse::Left){
					if(highlight==27){
						move = 0;
					}
				}
			}
		}
	}
}
