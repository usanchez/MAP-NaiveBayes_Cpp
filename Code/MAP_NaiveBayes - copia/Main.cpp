// MainMAP.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <fstream>
#include <vector>
#include "MAP.h"
#include "Data.h"
#include "NaiveBayes.h"

using namespace std;

int main()
{
	//from confmat import ConfMat Confusion matrix

	string filename = "ds/weatherNominalTr.txt";
	Data data = Data(filename, 67);
	data.report();

	MAP MAPmodel = MAP(data);
	MAPmodel.train();
	cm = ConfMat(MAPmodel.clsscnts); // confusion matrix
//    print
	for (v, c_true) in data.test_set: {
		c_pred = MAPmodel.predict(v)[0];
//		print v, c_pred, "( true class:", c_true, ")"
		cm.mat[c_pred, c_true] += 1;
	}

	print
	//  pr.show()
	//  print
	cm.report();

//    counts = [ (e,pr.clsscnts[e]) for e in pr.clsscnts ]
	
	return 0;
}
