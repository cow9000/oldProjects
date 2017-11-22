#ifndef LINK_H
#define LINK_H
//Link.h is for the defining of the links;

#include "neuron.h"
#include "network.h"

class link{

	public:
		//This will set neuron from and to.
		link(neuron n, neuron n2);
		int returnWeight();
		neuron returnFromneuron();
		neuron returnToneuron(); 
		
	private:
		int weight;
		//Incase you want to have some deactivation links between neurons
		bool deactivated;
		neuron fromNeuron;
		neuron toNeuron;
		network connectedNetwork;
};

#endif //LINK_H
