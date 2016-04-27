// MainMAP.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include <fstream>
#include <vector>

#include "MAP.h"
#include "Data.h"
#include "NaiveBayes.h"
#include "ConfMat.h"

using namespace std;

int main() {
	//from confmat import ConfMat Confusion matrix

	string filename = "ds/weatherNominalTr.txt";
	Data data = Data(filename, 67); // filename and train set percentage
	data.report();

	MAP MAPmodel = MAP(data);
	MAPmodel.train();
	ConfMat cm = ConfMat(MAPmodel.getClassCounts()); // Initialisation of confusion matrix
	// print
	for (auto const &row : data.test_set) {
		string c_pred = MAPmodel.predict(row.first)[0];
		pair<string, string> p(c_pred, row.second);
		// print v, c_pred, "( true class:", c_true, ")"
		cm.increaseValue(p); // +1 to this pair in the map matrix
	}

	// print
	//  pr.show()
	//  print
	cm.report();

//    counts = [ (e,pr.clsscnts[e]) for e in pr.clsscnts ]
	
	return 0;
}
