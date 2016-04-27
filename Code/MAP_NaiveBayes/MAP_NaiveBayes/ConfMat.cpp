#include "ConfMat.h"

using namespace std;

ConfMat::ConfMat(map<string, int> clsscnts) {
	int cnt = 1;
	for (auto const &iterclass : clsscnts) {
		classmap[iterclass.first] = "class" + cnt;
		cnt++;
	}
	// Neccessary?
	for (auto const &iter1 : clsscnts) {
		for (auto const &iter2 : clsscnts) {
			pair<string, string> p(iter1.first, iter2.first);
			mat[p] = 0;
		}
	}
}

// print conf matrix and show accuracy
void ConfMat::report() {
	// first one predicted, second true one
	// Iterate over classes
	for (auto const &iterclass : classmap) {
		printf("Guesses for %s, classifies as: %s", iterclass.first, iterclass.second); // class number, class real name
		int correct = 0, incorrect = 0;
		// Iterate over matrix to see which ones were correctly classified and which ones not
		for (auto const &itermat : mat) {
			pair<string, string> p(itermat.first);
			if (iterclass.second == p.first && p.first == p.second) { // Guessed correctly TODO: see if this is okay
				printf("\n\tGuessed correctly: %d", itermat.second);
				correct += itermat.second;
			}
			else { // Guessed incorrectly
				printf("\n\tGuessed incorrectly, class was predicted as %s and the true class was %s", itermat.second, p.second);
				incorrect += itermat.second;				
			}
		}
		printf("\n\nFinal results for class %s ( %s ):\n Correct guesses: %d \n Incorrect guesses: %d \n Accuracy: %f", iterclass.first, iterclass.second, correct, incorrect, float(correct/(correct+incorrect)));
	}
}

void ConfMat::increaseValue(pair<string, string> p) {
	mat[p] += 1;
}
