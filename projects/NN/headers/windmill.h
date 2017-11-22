#ifndef WINDMILL_H
#define WINDMILL_H

#include <iostream>
#include <string>
#include "network.h"
#include <stdlib.h>
namespace Windmill{	
	
	network generateNetwork();
	int evaluateNetwork(network n);
	
	void startTraining(){
		
		std::cout << "============|Commencing training|===========" << std::endl;
		int pop = atoi(information::Instance()->returnPopulation().c_str());
		for(int i = 0; i < pop; i++){
			information::Instance()->insertNetwork(generateNetwork());
		}
		
	}
	
	//Returns a network
	network generateNetwork(){
		network n;
		n.setGeneration(information::Instance()->returnGeneration());
		n.setFitness(0);
		//http://www.webpages.uidaho.edu/range357/notes/diversity.pdf
		n.setSpecies(0);
		
	}
	
	//Returns Fitness value
	int evaluateNetwork(network n){
		
	}

};



#endif // WINDMILL_H
