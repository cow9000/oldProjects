#include "headers/player.hpp"
#include "headers/AnimatedSprite.hpp"
#include "headers/map.hpp"
#include "headers/game.hpp"

#include <string>

Player::Player(std::string _name, Area* _area){
	//Set race
	race = 1;

	area = _area;

	maxHealth = 1;
	health = maxHealth;
	x = 1.0f;
	y = -200.0f;

	height = 64;
	width = 32;
	jumping = false;

	weight = 1.04;
	
	maxAccelerationX = 5;
	maxAccelerationY = 60;

	speed = 120;
	tempSpeed = 0;

	GRAVITY = 9.0f;
	MAX_VELOCITY = -10.0f;
	MAX_AIR_TIME = 1.2f;

	timeInAir = 0.0f;
	jumpImpulseTime = 0.2f;
	jumpImpulseVel = -10.0f; 
	jumpAccel = -1.0f;


	if (!texture.loadFromFile("data/player/mvSatyr.png")){}
	walkingAnimation.setSpriteSheet(texture);
	walkingAnimation.addFrame(sf::IntRect(32,0,width,height));
	walkingAnimation.addFrame(sf::IntRect(64,0,width,height));
	walkingAnimation.addFrame(sf::IntRect(96,0,width,height));
	walkingAnimation.addFrame(sf::IntRect(128,0,width,height));
	walkingAnimation.addFrame(sf::IntRect(160,0,width,height));

	crouchingAnimation.setSpriteSheet(texture);
	crouchingAnimation.addFrame(sf::IntRect(64,0,width,height/2));
	crouchingAnimation.addFrame(sf::IntRect(96,0,width,height/2));

	jumpingAnimation.setSpriteSheet(texture);
	jumpingAnimation.addFrame(sf::IntRect(8*32,64,width,height));

	AnimatedSprite animatedTemp(sf::seconds(8/speed),true,false);
	animatedSprite = animatedTemp;
	

	//Screen Dimensions?
	animatedSprite.setPosition(x,y);
	

	currentAnimation = &walkingAnimation;

	animatedSprite.play(*currentAnimation);
	animatedSprite.stop();
	
}

void Player::entityLoop(){

	isTouchingGround = touchingGround();

	animatedSprite.setOrigin(animatedSprite.getLocalBounds().width/2, 0);
	if(health <= 0) eventDeath();
	eventMove();

}

void Player::eventMove(){
	sf::Vector2f movement(0.f,0.f);
	sf::Time frameTime = frameClock.restart();
	animatedSprite.setOrigin(animatedSprite.getLocalBounds().width/2, 0);

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::S) && isTouchingGround){
		currentAnimation = &crouchingAnimation;
		animatedSprite.setOrigin(animatedSprite.getLocalBounds().width/2,(-1*(animatedSprite.getLocalBounds().height/2)));
		animatedSprite.play(*currentAnimation);
	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)){

		velocity.x = -1 * speed;

		//Animation
		currentAnimation = &walkingAnimation;
		animatedSprite.play(*currentAnimation);
		animatedSprite.setScale(-1,1);
		noKeyWasPressed = false;
	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
		velocity.x = speed;

		//Animation
		currentAnimation = &walkingAnimation;
		animatedSprite.play(*currentAnimation);
		animatedSprite.setScale(1,1);
		noKeyWasPressed = false;
	}else{
		currentAnimation = &walkingAnimation;
		animatedSprite.play(*currentAnimation);
	}

	if(noKeyWasPressed){
		animatedSprite.stop();
		velocity.x = velocity.x/weight;
	}

	noKeyWasPressed = true;
	
	if(isTouchingGround){
		
		if(velocity.y > 0){
			currentAnimation = &walkingAnimation;
			animatedSprite.play(*currentAnimation);
			animatedSprite.stop();
			velocity.y = 0;
		}
	}else{
		if(MAX_VELOCITY * 10 < velocity.y)
			velocity.y += GRAVITY;

		currentAnimation = &jumpingAnimation;
		animatedSprite.play(*currentAnimation);
	}

	//Check if player will collide into wall.
	//if(!collideWithWall(x,y)){
		movement.x += velocity.x + acceleration.x;
		x = animatedSprite.getPosition().x;

		movement.y += velocity.y + acceleration.y;
		y = animatedSprite.getPosition().y;
	//}else{
	//	x = x-movement.x;
	//	y = y-movement.y;
	//}

	animatedSprite.move(movement * frameTime.asSeconds());
	animatedSprite.update(frameTime);
}



Player::~Player(){

}
