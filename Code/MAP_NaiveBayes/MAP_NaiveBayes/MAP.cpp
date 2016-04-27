#include "MAP.h"
#include "Data.h"

using namespace std;

MAP::MAP(Data d) : data(d) {	
	normalized = false;
}

void MAP::train() {
	normalized = false;
	for each (pair<vector<string>, string> pair in data.training_set) {
		clsscnts[pair.second] += 1;
		attrcnts[pair.first] += 1;
		condcnts[pair] += 1;
	}
	normalize();
}

bool MAP::normalize() {
	if (normalized)
		return normalized;
	normalized = true;
	for (auto const &iter1 : attrcnts) {	
		for (auto const &iter2 : clsscnts) {
			pair<vector<string>, string> p(iter1.first, iter2.first);
			condprobs[p] = float(condcnts[p]) / attrcnts[iter1.first];
		}
	}
	for (auto const &iter : clsscnts) {
		clssprobs[iter.first] = float(clsscnts[iter.first]) / data.getNumberOfRows();
	}
}

float MAP::value_weight(vector<string> attrs, string clval) {
	printf("weight of class value clval for these attrs");
	pair<vector<string>, string> p(attrs, clval);
	return condprobs[p];
}

// TODO: missing method float value prediction

vector<string> MAP::predict(vector<string> attrs) {
	vector<string> predictions;
	float mx = 0.0;
	for (auto const &iter : clssprobs) {
		float prc = value_weight(attrs, iter.first);
		if (prc > mx)
			predictions.clear();
		if (prc >= mx) {
			mx = prc;
			predictions.push_back(iter.first);
		}
	}
	return predictions;
}

map<string, int> MAP::getClassCounts() {
	return clsscnts;
}

void MAP::print() const {

}