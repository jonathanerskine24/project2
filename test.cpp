#include <iostream>
#include <fstream>
#include <string>
#include <vector>

std::vector<int> *InitIntVector(char *fileName) {
	std::ifstream file;
	file.open(fileName);
	std::vector<int> *newVector = new std::vector<int>;
	int data;
	while (file >> data) {
		newVector->push_back(data);
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


template <typename ElementType>
ElementType *Merge(ElementType *vectorHalf1, ElementType *vectorHalf2) {
	ElementType *temp = new ElementType;

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

	delete vectorHalf1;
	delete vectorHalf2;

	return temp;
}

template <typename ElementType>
ElementType *MergeSortVector(ElementType *vectorToSort) {
		if (vectorToSort->size() == 1) return vectorToSort;	
		int half = vectorToSort->size() / 2;
		ElementType *firstHalf = new ElementType(vectorToSort->begin(), vectorToSort->begin() + half);
		ElementType *secondHalf = new ElementType(vectorToSort->begin() + half, vectorToSort->end());
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
	std::vector<std::string> *s_vector1; std::vector<std::string> *s_vector2;
	std::vector<int> *i_vector1; std::vector<int> *i_vector2;

	if (inputType == "s") {
		s_vector1 = InitStringVector(argv[2]);
		s_vector2 = InitStringVector(argv[3]);
		s_vector1 = MergeSortVector(s_vector1);
		s_vector2 = MergeSortVector(s_vector2);
		for (int i = 0; i<s_vector2->size(); i++) {
			std::cout << s_vector2->at(i) << std::endl;
		}
	} else if (inputType == "i") {
		i_vector1 = InitIntVector(argv[2]);
		i_vector2 = InitIntVector(argv[3]);
		i_vector1 = MergeSortVector(i_vector1);
		i_vector2 = MergeSortVector(i_vector2);
		for (int i = 0; i<i_vector2->size(); i++) {
			std::cout << i_vector2->at(i) << std::endl;
		}
	} else {
		std::cout << inputType << " is not a valid argument, program quitting" << std::endl;
		return 1;
	}



	return 0;
}
