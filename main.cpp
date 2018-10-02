#include <iostream>
#include <fstream>
#include <string>

std::string* snipArray(std::string* array, int N) {
	std::string *newArray = new std::string[N];
	for (int i = 0; i<N; i++) {
		newArray[i] = array[i];
	}
	return newArray;
}

std::string* InitArray(char *fileName) {
	std::ifstream file;
	file.open(fileName);
	std::string *stringArray = new std::string[100];
	int index = 0;
	int n = 0;
	std::string data;
	while (file >> data) {
		stringArray[index] = data;
		index++;
		n++;
	}
	std::string *stringArraySnipped = snipArray(stringArray, n);
	delete [] stringArray;
	stringArray = NULL;
	return stringArraySnipped;
}


int main(int argc, char ** argv) {

	if (argc != 4) {
		std::cout << "Usage: ./a.out i/o file1 file2" << std::endl;
		return 1;
	}


	std::string *stringArray1 = InitArray(argv[2]);
	std::string *stringArray2 = InitArray(argv[3]);




	std::cout << stringArray1[4] << " " <<  << std::endl;


	return 0;
}
