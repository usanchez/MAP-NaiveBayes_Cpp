#include "MAP.h"
#include "Data.h"

#include <iostream>
#include <fstream>
#include <vector>


using namespace std;

MAP::MAP(Data d) : data(d) {	
	normalized = false;
}


void MAP::train() {
	normalized = false;
	for each (pair<vector<string>, string> pair in data.training_set) {
		clsscnts[pair.second] += 1;
		attrcnts[pair.first] += 1;
		condcnts[pair.first, pair.second] += 1;
	}
	normalize();
}

void MAP::normalize() {
	/*
	if (normalized)
		return normalized;
		normalized = true;
		for (vals in attrcnts)
			for (c in clsscnts)
				condprobs[vals, c] = \
				float(condcnts[vals, c]) / attrcnts[vals]
				for (c in clsscnts)
					clssprobs[c] = float(clsscnts[c]) / data.N
	*/
}

void MAP::value_weight(attrs, clval) {
	printf("weight of class value clval for these attrs");
	return condprobs[attrs, clval];
}

void MAP::predict(attrs) {
	vector<float> predictions = [];
	float mx = 0.0;
	for (c in clssprobs.keys()) {
		prc = value_weight(attrs, c)
		if (prc > mx)
			predictions = [];
		if (prc >= mx) {
			mx = prc;
			predictions.append(c);
		}
	}
	return predictions
}

void MAP::print() const
{

}

