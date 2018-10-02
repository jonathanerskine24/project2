#include <iostream>
#include <fstream>
#include <string>
#include <vector>

std::vector<std::string> *InitIntVector(char *fileName) {
	std::ifstream file;
	file.open(fileName);
	std::vector<std::string> *newVector = new std::vector<std::string>;
	int data;
	while (file >> data) {
		std::string x = std::to_string(data);
		newVector->push_back(x);
	}
	file.close();
	return newVector;
}

std::vector<std::string> *InitStringVector(char *fileName) {
	std::ifstream file;
	file.open(fileName);
	std::vector<std::string> *newVector = new std::vector<std::string>;
	std::string data;
	while (file >> data) {
		newVector->push_back(data);
	}
	file.close();
	return newVector;
}

std::vector<std::string> *Merge(std::vector<std::string> *vectorHalf1, std::vector<std::string> *vectorHalf2) {
	std::vector<std::string> *temp = new std::vector<std::string>;

	while (!vectorHalf1->empty() && !vectorHalf2->empty() ) {
		if (vectorHalf1->at(0) > vectorHalf2->at(0)) {
			temp->push_back(vectorHalf2->at(0));
			vectorHalf2->erase(vectorHalf2->begin());
		} else {
			temp->push_back(vectorHalf1->at(0));
			vectorHalf1->erase(vectorHalf1->begin());
		}
	}

	while (!vectorHalf1->empty()) {
		temp->push_back(vectorHalf1->at(0));
		vectorHalf1->erase(vectorHalf1->begin());
	}

	while (!vectorHalf2->empty()) {
		temp->push_back(vectorHalf2->at(0));
		vectorHalf2->erase(vectorHalf2->begin());
	}

	return temp;
}

std::vector<std::string> *MergeSortVector(std::vector<std::string> *vectorToSort) {
		if (vectorToSort->size() == 1) return vectorToSort;	

		int half = vectorToSort->size() / 2;
		std::vector<std::string> *firstHalf = new std::vector<std::string>(vectorToSort->begin(), vectorToSort->begin() + half);
		std::vector<std::string> *secondHalf = new std::vector<std::string>(vectorToSort->begin() + half, vectorToSort->end());
		firstHalf = MergeSortVector(firstHalf);
		secondHalf = MergeSortVector(secondHalf);
		return Merge(firstHalf, secondHalf);
}


int main(int argc, char ** argv) {

	if (argc != 4) {
		std::cout << "Usage: ./a.out i/o file1 file2" << std::endl;
		return 1;
	}

	std::string inputType = argv[1];
	std::vector<std::string> *vector1;
	std::vector<std::string> *vector2;

	if (inputType == "s") {
		vector1 = InitStringVector(argv[2]);
		vector2 = InitStringVector(argv[3]);
	} else if (inputType == "i") {
		vector1 = InitIntVector(argv[2]);
		vector2 = InitIntVector(argv[3]);
	} else {
		std::cout << inputType << " is not a valid argument, program quitting" << std::endl;
		return 1;
	}


	std::cout << vector1->at(0) << " "  << std::endl;
	vector1 = MergeSortVector(vector1);

	std::cout << vector1->at(0) << " "  << std::endl;

	return 0;
}
