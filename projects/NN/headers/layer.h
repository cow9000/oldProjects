#ifndef LAYER_H
#define LAYER_H

#include "network.h"
#include "neuron.h"
#include <vector>
#include <string>

class layer{
	public:
		
		std::string returnName();
		std::vector<neuron> returnNeuronsInLayer();
		network returnNetworkConnectedTo();
	private:
		std::string name;
		std::vector<neuron> neuronsInLayer;
		network networkConnectedTo;
};


#endif //LAYER_H
