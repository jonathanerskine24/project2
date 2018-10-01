#include <iostream>
#include <fstream>

void IntArray(int* intArray1, int* intArray2, std::ifstream file1) {
	file1 >> intArray1[1];
	return;
}

int main(int argc, char ** argv) {

	if (argc != 4) {
		std::cout << "Usage: ./a.out i/o file1 file2" << std::endl;
		return 1;
	}

	int *intArray1 = new int[100];
	int *intArray2 = new int[100];
	for (int i = 0; i<100; i++) {
		intArray1[i] = 0;
		intArray2[i] = 0;
	}

	std::string data;

	std::ifstream file1, file2;
	file1.open(argv[2]);
	file2.open(argv[3]);
	

	IntArray(intArray1, intArray2, file1);

	std::cout << intArray1[1] << std::endl;


	return 0;
}
