#include <random>
#include <fstream>
#include <string>
#include <tuple>
#include <utility>

#include "Data.h"
#include "Utils.cpp"

using namespace std;

Data::Data(string f, int j) : justtrain(j) {
	/*
	justrain == 0: use training data as test data
	justrain == p > 0: use approx p% as training data and rest as test
	*/
	N = 0;
	filename = f;
	ifstream datafile;
	datafile.open(filename);
	header = true;
	string line;
	while (getline(datafile, line)){
		if (header) {
			header = false;			
			headers = split(line, " ");
			for each (string el in headers)
				el = trim_inplace(el);
		} else {
			N += 1;
			vector<string> ls = split(line, " ");
			for each (string el in ls)
				el = trim_inplace(el);
			string clss = ls.back();
			ls.pop_back();
			vector<string> values = ls;
			pair<vector<string>, string> row_pair(values, clss);
			if (justtrain == 0 || (rand() %100 + 1) <= justtrain)
				training_set.push_back(row_pair);
			else
				test_set.push_back(row_pair);
		}
	}
	datafile.close();
	if (justtrain == 0)
		test_set = training_set;
}

void Data::report() {
	printf("%i observations from file %s", N, filename);
	if (justtrain == 0)
		printf("testing with whole training set");
	else
		printf("training with %i observations ", size(training_set));
		printf("testing with %i observations ", size(test_set));
}

int Data::getNumberOfRows() {
	return N;
}
