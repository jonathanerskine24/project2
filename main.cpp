#include <iostream>
#include <fstream>
#include <string>


int main(int argc, char ** argv) {

	if (argc != 4) {
		std::cout << "Usage: ./a.out i/o file1 file2" << std::endl;
		return 1;
	}


	std::string data;

	std::ifstream file1, file2;
	file1.open(argv[2]);
	file2.open(argv[3]);
	
	std::string *stringArray1 = new std::string[100];
	std::string *stringArray2 = new std::string[100];

	for (int i=0; i<102; i++) {
		file1 >> data;		
	}
	file1 >> data;
	file1 >> data;


	std::cout << data << std::endl;


	return 0;
}
