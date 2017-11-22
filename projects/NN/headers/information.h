#ifndef HEADERS_H
#define HEADERS_H

#define ART "art/windmill.txt"

//Used for getting information from items.
#include <stdlib.h>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <unistd.h>
#include "network.h"
class information{

	public:
		information();
		static information* Instance();
		void assignOutputVariables();
		void assignFitnessVariables();
		void assignInputVariables();
		void insertNetwork(network n);
		void removeNetwork(network n);
		//RETURNING FILE INFORMATION
		std::vector<std::string> openFile(std::string path);
		//PRINTING OUT FILE
                void openFile(std::string path, std::string print);
		std::string returnVariable(std::vector<std::string> v, std::string variableName);
		//PRINT OUT VECTOR
		void printVector(std::vector<std::string> v);
		//RETURN FUNCTIONS
		std::vector<std::string> returnOutputs();
		std::vector<std::string> returnInputdata();
		std::vector<std::string> returnFitnessdata();
		std::vector<std::string> returnEqualdata();
		std::string returnApp();
		std::string returnPopulation();
		std::string returnType();
		std::string returnDatafile();
		std::vector<std::string> returnData();
		std::string returnOutputfile();
		std::string returnFitnessfile();
		std::string returnFitness();
		std::string returnFitnesstype();
		std::string returnEquation();
		std::string returnEquals();
		std::string returnFitnessadd();
		std::string returnFitnessremove();
		int returnGeneration();
		std::vector<std::string> returnEqualinputs();
		std::vector<std::string> returnEqualoutputs();
		std::vector<network> returnNetworks();
	private:
		information(information const&){};
		information& operator=(information const&){};
		static information* m_pInformation;
		//FROM output.txt
		std::vector<std::string> inputData;
		int outputs;
		//DATA FROM VARIOUS FILES INORDER TO GIVE THE VALUES TO OTHER VARIABLES
		std::vector<std::string> outputData;
		std::vector<std::string> fitnessData;
		std::vector<std::string> equalData;
		//FROM input.txt
		std::string app;
		std::string population;
		std::string type;
		std::string datafile;
		std::vector<std::string> data;
		std::string outputfile;
		std::string fitnessfile;		

		//FROM fitness.txt
		std::string fitness;
		std::string fitnesstype;
		std::string equation;
		std::string equals;
		std::string fitnessadd;
		std::string fitnessremove;

		//FROM equal.txt
		//Inputs = outputs
		//input[0] = output[0]
		std::vector<std::string> equalinputs;
		std::vector<std::string> equaloutputs;

		//NETWORKS
		std::vector<network> networks;
		int generation;
};

#endif //HEADERS_H
