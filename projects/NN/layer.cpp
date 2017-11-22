#include "headers/layer.h"
#include "headers/network.h"
#include <string>
std::string layer::returnName(){
	return name;
}
std::vector<neuron> layer::returnNeuronsInLayer(){
	return neuronsInLayer;
}
network layer::returnNetworkConnectedTo(){
	return networkConnectedTo;
}
