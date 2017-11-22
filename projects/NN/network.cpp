#include "headers/network.h"
#include "headers/link.h"
#include "headers/neuron.h"
void network::setGeneration(int n) { generation = n; }
void network::setSpecies(int n) { species = n; }
void network::setFitness(int n) { species = n; }
void network::generateLink(neuron n, neuron n2){
	link l(n, n2);
	insertIntoLinks(l);
}
void insertIntoLinks(link l){
	
}
