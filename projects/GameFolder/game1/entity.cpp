#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <vector>	
#include "headers/entity.hpp"
#include "headers/area.hpp"
#include "headers/AnimatedSprite.hpp"
#include "headers/playState.hpp"
#include "headers/entity.hpp"
#include "headers/entity.hpp"
class Inventory;

//Entity main loop
void Entity::entityLoop(){
	//First check if entity has died.
	if(health <= 0) eventDeath();
	eventMove();
}

//Health and Mana
double Entity::returnMaxHealth() {return maxHealth;}
double Entity::returnHealth() {return health;}
double Entity::returnHealthRegen() {return healthRegen;}

	void Entity::setMaxHealth(double mh){maxHealth = mh;}
	void Entity::setHealth(double h){health = h;}
	void Entity::setHealthRegen(double h){healthRegen = h;}

double Entity::returnMaxMana() {return maxMana;}
double Entity::returnMana() {return mana;}
double Entity::returnManaRegen() {return manaRegen;}

	void Entity::setMaxMana(double mm){maxMana = mm;}
	void Entity::setMana(double m){mana = m;}
	void Entity::setManaRegen(double m){manaRegen = m;}

//Level and Experience
int Entity::returnLevel() {return level;}
int Entity::returnExperience() {return experience;}



//Gender and race
int Entity::returnRace() {return race;}
int Entity::returnGender() {return gender;}

	void Entity::setRace(int r){race = r;}
	void Entity::setGender(int g){gender = g;}

//POSITIONING
int Entity::returnDirection() {return direction;} // 1-8, 1=North, 2=North-east, 3=East, etc
float Entity::returnX() {return x;} // X on map
float Entity::returnY() {return y;} // Y on map

	void Entity::setX(int X){x=X;}
	void Entity::setY(int Y){y=Y;}

float Entity::returnSpeed() {return speed + tempSpeed;}

//Inventory
Inventory * Entity::returnInventory() {return inventory;}

//Graphics
sf::Texture Entity::returnTexture() {return texture;}

//Sounds
std::vector<sf::Sound*> Entity::returnSounds() {return sounds;}

//Skills
int Entity::returnSkillValue(int skillId){
	int value = 0;
	for(int i = 0; i > skills.size(); i++){
		//NEEDED
			//SEARCH THROUGH VECTOR AND FIND THE SKILL VALUE BY SPERATING THE STRING INTO ID AND VALUE
		return value;
	} 
}


//Events
void Entity::eventAttack(){
	//Attack...	
}
void Entity::eventDeath(){
	//Kill this entity...
}
void Entity::eventLevel(){
	level += 1;
	//DO EXPERIENCE CALCULATIONS
}
void Entity::eventPlaySound(int soundId){
	//Nothing here...
	//Used for when the entity needs to play a sound
}
void Entity::eventUse(){
	//Nothing here...
	//This event is for when you right click it, like a chest
	//Might show a gui or something with items :)
}
void Entity::eventExperience(int e){
	experience += e;

	//NEEDED - 
		//Add next level experience thing
		//Add leveling 
}
void Entity::eventHealth(double _health, Entity & e, int type){
	//e is the Entity that did the effect.
	//type is the type, IE: fire, heal, light, etc;
	health += _health;
	if(health > maxHealth) health = maxHealth;
	else if(health <= 0) eventDeath();
}
void Entity::eventMana(int _mana){
	mana += _mana;
	if(mana > maxMana) mana = maxMana;
	else if(mana < maxMana) mana = 0;
}



//THIS IS FOR SMOOTH MOVEMENT!!!!
void Entity::eventMove(){
	sf::Vector2f movement(0.f,0.f);
	sf::Time frameTime = frameClock.restart();

	if(direction == 1){
		if(acceleration.x > 0){
			acceleration.x = -10;				
		}
		if(acceleration.x > -1 * maxAccelerationX);
			acceleration.x -= speed/8;
		//Animate entity
		currentAnimation = &walkingAnimation;
		animatedSprite.play(*currentAnimation);
	}
	
	movement.x += acceleration.x;
	x += acceleration.x;

	animatedSprite.move(movement * frameTime.asSeconds());
	animatedSprite.update(frameTime);
	
}

//THIS IS FOR GRAPHICS
void Entity::drawEntity(sf::RenderWindow & window){
	window.draw(animatedSprite);
}

bool Entity::touchingGround(){
	
	
	if(area->returnTyleType(animatedSprite.getPosition().x,animatedSprite.getPosition().y-1,width, height) > 0){
		return true;
	}
	return false;
}

bool Entity::collideWithWall(int _x, int _y){
	if(area->returnTyleType(_x,_y,width,height) > 0){
		return true;
	}
	return false;
}
