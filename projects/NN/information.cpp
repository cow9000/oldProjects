
//Used for getting information from items.
#include <stdlib.h>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <unistd.h>
#include <stddef.h>
#include "headers/information.h"
#include "headers/network.h"
information* information::m_pInformation = NULL;

void removeCharsFromString( std::string &str, char charsToRemove ) {
	str.erase( remove(str.begin(), str.end(), charsToRemove), str.end() );
}

	information* information::Instance(){
		if(!m_pInformation)
			m_pInformation = new information;
		return m_pInformation;
	}
	information::information(){
		//SHOW ART OF WINDMILL
		openFile(ART, "#");
		
		std::string path;
		//OPEN THE INPUTS FILE AND GIVE THE inputs VECTOR THE SAME VALUE AS openFile vector
		std::cout << "INPUT FILE NAME - ";
		std::cin >> path;
		inputData = openFile("input/" + path);
		
		if(!inputData.empty())
			std::cout << "\nDATA LOADED FROM INPUT PATH" << std::endl;
		else
			std::cout << "\nDATA UNSUCCESSFULLY LOADED" << std::endl;
		assignInputVariables();
		outputData = openFile("output/" + outputfile);
		fitnessData = openFile("fitness/" + fitnessfile);
		data = openFile("data/" + datafile);
		assignFitnessVariables();
		assignInputVariables();
	}

	void information::insertNetwork(network n){
		networks.push_back(n);
	}
	void information::removeNetwork(network n){
		//Loop through networks in the vector networks and search for the network that equals the one specified
	}

	void information::printVector(std::vector<std::string> v){
		for(std::vector<std::string>::iterator it = v.begin(); it < v.end(); it += 1 ){
			std::cout << *it << std::endl;
		}
	}
	void information::assignOutputVariables(){
		outputs = inputData.size();
	}
	void information::assignFitnessVariables(){
		fitness = returnVariable(fitnessData, "fitness");
		fitnesstype = returnVariable(fitnessData, "fitnesstype");
		equation = returnVariable(fitnessData, "equation");
		equals = returnVariable(fitnessData, "equals");
		fitnessadd = returnVariable(fitnessData, "fitnessadd");
		fitnessremove = returnVariable(fitnessData, "fitnessremove");
	}
	void information::assignInputVariables(){
		//String to int atoi(myString.c_str()); 
		app = returnVariable(inputData, "app");
		population = returnVariable(inputData, "population");
		type = returnVariable(inputData, "type");
		datafile = returnVariable(inputData, "datafile");
		outputfile = returnVariable(inputData, "outputfile");
		fitnessfile = returnVariable(inputData, "fitnessfile");
	}

	std::string information::returnVariable(std::vector<std::string> v, std::string variableName){
		std::string variableValue;
		std::string line;
		bool matches = true;

		for (std::vector<std::string>::iterator it = v.begin(); it < v.end(); it += 1 ){
			matches = true;
			if(variableName.length() > 0){
				line = *it;
				for(int i = 0; i < variableName.length(); i++){
					if(matches == true){
						if(variableName[i] == line[i]){
							//std::cout << variableName[i] << " matches with " << line[i] << std::endl;
						}else{
							matches = false;
						}
						if(i >= variableName.length() - 1){
							variableValue = line;
							//std::cout << variableName << " found! - " << variableValue << std::endl;
							break;
						}
					}
				}
			}
			if(matches == true) break;
		}
		unsigned first = variableValue.find("\"");
                unsigned last = variableValue.find(";");
                variableValue = variableValue.substr (first,last-first);
                removeCharsFromString(variableValue, '"');

		//std::cout << variableValue << " is variableValue!" << std::endl;
		return variableValue;
	}


	//RETURNING FILE INFORMATION
	std::vector<std::string> information::openFile(std::string path){
		std::ifstream file(path.c_str());
		std::string line;
		std::vector<std::string> text;
		int arr = 0;
		if(file.is_open()){
			while(std::getline(file,line)){
				if(line.length() > 0){
					if(line[0] != '#'){
						text.push_back(line);
					}
				}
			}
			file.close();
			return text;				
		}
		
		else{
			return text;
		}
	}
	//PRINTING OUT FILE
        void information::openFile(std::string path, std::string print){
                std::ifstream file(path.c_str());
                std::string line;
                if(file.is_open()){
                        while(std::getline(file,line)){
                                if(line.length() > 0){
                                        if(line[0] != '#' || print == "#"){
                                        	std::cout << line << std::endl;
                                       	}
                                }
                        }
                        file.close();
                }
        }

	
	//RETURN FUNCTIONS
	
	std::vector<std::string> information::returnOutputs(){ return outputData; }
	std::vector<std::string> information::returnInputdata(){ return inputData; }
	std::vector<std::string> information::returnFitnessdata(){ return fitnessData; }
	std::vector<std::string> information::returnEqualdata(){ return equalData; }
	std::string information::returnApp(){ return app; }
	std::string information::returnPopulation(){ return population; }
	std::string information::returnType(){ return type; }
	std::string information::returnDatafile(){ return datafile; }
	std::vector<std::string> information::returnData(){ return data; }
	std::string information::returnOutputfile(){ return outputfile; }
	std::string information::returnFitnessfile(){ return fitnessfile; }
	std::string information::returnFitness(){ return fitness; }
	std::string information::returnFitnesstype(){ return fitnesstype; }
	std::string information::returnEquation(){ return equation; }
	std::string information::returnEquals(){ return equals; }
	std::string information::returnFitnessadd(){ return fitnessadd; }
	std::string information::returnFitnessremove(){ return fitnessremove; }
	std::vector<std::string> information::returnEqualinputs(){ return equalinputs; }
	int information::returnGeneration(){ return generation; }
	std::vector<std::string> information::returnEqualoutputs(){ return equaloutputs; }
