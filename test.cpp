#include <iostream>
#include <fstream>
#include <string>
#include <vector>

template <typename ElementType>
std::vector<ElementType> *InitVector(char *fileName, ElementType type) {
	std::ifstream file;
	file.open(fileName);
	std::vector<ElementType> *newVector = new std::vector<ElementType>;
	ElementType data;
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

template <typename ElementType>
void checkForDuplicates(ElementType *vector1, ElementType *vector2) {
	ElementType *temp = new ElementType;
	int size1 = vector1->size();
	int size2 = vector2->size();
	for (int i = 0; i<size1; i++) {
		for (int j = 0; j<size2; j++) {
			if (vector1->at(i) == vector2->at(j)) {
				temp->push_back(vector1->at(i));
			}
		}
	}
	for (int i = 0; i<temp->size(); i++) {
		std::cout << temp->at(i) << std::endl;
	}
	delete temp;
	return;
}

int main(int argc, char ** argv) {

	if (argc != 4) {
		std::cout << "Usage: ./a.out i/o file1 file2" << std::endl;
		return 1;
	}

	std::string inputType = argv[1];
	std::vector<std::string> *s_vector1; std::vector<std::string> *s_vector2;
	std::vector<int> *i_vector1; std::vector<int> *i_vector2;
	int placeholder = 0;
	std::string placeholder2 = "";

	if (inputType == "s") {
		s_vector1 = InitVector(argv[2], placeholder2);
		s_vector2 = InitVector(argv[3], placeholder2);
		s_vector1 = MergeSortVector(s_vector1);
		s_vector2 = MergeSortVector(s_vector2);
		checkForDuplicates(s_vector1, s_vector2);
	} else if (inputType == "i") {
		i_vector1 = InitVector(argv[2], placeholder);
		i_vector2 = InitVector(argv[3], placeholder);
		i_vector1 = MergeSortVector(i_vector1);
		i_vector2 = MergeSortVector(i_vector2);
		checkForDuplicates(i_vector1, i_vector2);
	} else {
		std::cout << inputType << " is not a valid argument, program quitting" << std::endl;
		return 1;
	}


	return 0;
}


