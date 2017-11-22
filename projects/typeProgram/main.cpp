#include <iostream>
#include <string>

int main(){
	std::cout << "What character?";
	std::string c;
	std::cin >> c;
	std::cout << "How many characters? - ";
	int character;
	std::cin >> character;
	std::string length;
	for(int i = 0; i < character; i++){
		length += c;
	}
	std::cout << "\n" << length;
	return 0;
}
