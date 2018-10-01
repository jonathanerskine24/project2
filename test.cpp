#include <iostream>
#include <fstream>


using namespace std;
// void IntData(int *intArray1, int *intArray2, std::ifstream file1, std::ifstream file2) {
// 	int i = 0;
// 	while (file1 || file2) {
// 		file1 << intArray1[i];
// 		file2 << intArray2[i];
// 	}
// }


int main(void) {

	int *test = new int[10];
	for (int i = 0; i<10; i++) {
		test[i] = 89;
	}


	cout << test[2] << endl;

	delete [] test;
	test = NULL;

	// cout << test[2] << endl;


	string a = "50";
	string b = "51";
	string c = "Ant";
	string d = "Banana";

	if (d > c) cout << "true" << endl;

	cout << c.compare(d) << endl;
	cout << d.compare(c) << endl;

	return 0;
}
