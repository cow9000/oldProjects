#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include "AnimatedSprite.hpp"
#include "playState.hpp"
#include "area.hpp"
#include "map.hpp"

class Animation;
class AnimatedSprite;
class Area;
class playState;
class Map;
class Inventory;
class Dialog;

//All interactable things will be inheritted from this.
class Entity{
	public:
		//Entity main loop
		virtual void entityLoop();

		//Health and Mana
		virtual double returnMaxHealth();
		virtual double returnHealth();
		virtual double returnHealthRegen();

			virtual void setMaxHealth(double mh);
			virtual void setHealth(double h);
			virtual void setHealthRegen(double h);
	
		virtual double returnMaxMana();
		virtual double returnMana();
		virtual double returnManaRegen();
		
			virtual void setMaxMana(double mm);
			virtual void setMana(double m);
			virtual void setManaRegen(double m);

		//Level and Experience
		virtual int returnLevel();
		virtual int returnExperience();



		//Gender and race
		virtual int returnRace();
		virtual int returnGender();

			virtual void setRace(int r);
			virtual void setGender(int g);
		
		//POSITIONING
		virtual int returnDirection(); // 1-8, 1=North, 2=North-east, 3=East, etc
		virtual float returnX(); // X on map
		virtual float returnY();// Y on map

			virtual void setX(int X);
			virtual void setY(int Y);

		virtual float returnSpeed();

		//Inventory
		virtual Inventory * returnInventory();

		//Graphics
		virtual sf::Texture returnTexture();

		//Sounds
		virtual std::vector<sf::Sound*> returnSounds();

		//Skills
		virtual int returnSkillValue(int skillId);


		//Events
		virtual void eventAttack();
		virtual void eventDeath();
		virtual void eventLevel();
		virtual void eventPlaySound(int soundId);
		virtual void eventUse();
		virtual void eventExperience(int e);
		virtual void eventHealth(double _health, Entity & e, int type);
		virtual void eventMana(int _mana);

		
		//THIS IS FOR SMOOTH MOVEMENT!!!!
		virtual void eventMove();
		virtual bool collideWithWall(int _x, int _y);

		//THIS IS FOR GRAPHICS
		virtual void drawEntity(sf::RenderWindow & window);
		virtual bool touchingGround();
		
	protected:
		
		
		//Health, Mana
		double maxHealth;
		double health;
		double maxMana;
		double mana;

		double healthRegen;
		double manaRegen;

		//for map
		Area * area;

		//Item stuff
		Inventory * inventory;

		//Dialog, if any
		Dialog * dialog;

		//Damage Reduction each is -1 to damage;
		int dr;

		int tempDr;
		
		//Experience
		int level;
		int experience;
		
		//Info
		int race;
		int gender;
		std::string name;		
		
		//Map stuff
		float x; //X on map
		float y; //Y on map

		bool moving;
		bool jumping;
		int direction; // 1=left, 2=right

		//Graphics
		sf::Texture texture;
		Animation walkingAnimation;
		Animation jumpingAnimation;
		Animation crouchingAnimation;
		AnimatedSprite animatedSprite;
		Animation* currentAnimation;
		
		int width;
		int height;
		
		//Sounds
		std::vector<sf::Sound*> sounds;


		//Skills
		//This vector is laid out like x.y
		//x = skill identity.
		//y = value
		std::vector<double> skills;

		//Skill tree? How to do that? Possibly a string laid out like this
		//SkillTreeID:Value,SkillTreeID:Value,etc
		std::string skillTree;

		//POINTS
		int skillPoints;
		int skillTreePoints;
		int statPoints;

		//ATTACKS
		double attackCooldown;
		double magicCooldown;

		//Moving
		float speed;
		float tempSpeed;

		sf::Vector2f acceleration;
		sf::Vector2f velocity;

		float maxAccelerationX;
		float maxAccelerationY;

		float weight;

		float GRAVITY;
		float MAX_VELOCITY;
		float MAX_AIR_TIME;

		float timeInAir;
		float jumpImpulseTime;
		float jumpImpulseVel;
		float jumpAccel;

		bool isTouchingGround;

		//CLOCK
		sf::Clock regenHealthClock;
		sf::Clock regenManaClock;
		sf::Clock movementClock;
		sf::Clock attackClock;
		sf::Clock jumpClock;
		sf::Clock frameClock;

		sf::Time jumpTime;
};

#endif
