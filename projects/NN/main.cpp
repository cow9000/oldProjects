#include <iostream>
#include <string>
#include "headers/information.h"
#include "headers/windmill.h"
#include "headers/link.h"
#include "headers/network.h"
#include "headers/layer.h"
int main()
{
	
	std::cout << "Windmill is now learning about - " << information::Instance()->returnApp() << std::endl;
	std::cout << "How many networks will be generated? - " << information::Instance()->returnPopulation() << std::endl;
	std::cout << "What type of data will Windmill get? - " << information::Instance()->returnType() << std::endl;
	std::cout << "Where will windmill get DATA (for output layer)? - " << information::Instance()->returnDatafile() << std::endl;
	std::cout << "The data windmill recieved are as follows - " << std::endl;
	information::Instance()->printVector(information::Instance()->returnData());
	std::cout << "The outputs windmill recieved are as follows - " << std::endl;
	information::Instance()->printVector(information::Instance()->returnOutputs());
	
	Windmill::startTraining();

	char a;
	std::cin >> a;
	return 0;
}
