#ifndef NETWORK_H
#define NETWORK_H

#include "neuron.h"
#include "link.h"
#include "layer.h"
#include <vector>

//Network.h for creating the neurons and links between things
class network{

	public:
		void setGeneration(int n);
		void setSpecies(int n);
		void setFitness(int n);
		void generateLink(neuron n, neuron n2);
		void insertIntoLinks(link l);
	private:
		std::vector<neuron> neurons;
		std::vector<link> links;
		int generation;
		int species;
		int fitness;
		layer inputLayer;
		layer hiddenLayer;
		layer outputLayer;
};
#endif //NETWORK_H
