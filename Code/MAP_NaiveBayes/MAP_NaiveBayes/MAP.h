#ifndef MAP_H
#define MAP_H

#include <iostream>
#include <fstream>
#include <vector>
#include <map>

#include "Data.h"

using namespace std;

class MAP {
private:	
	bool normalized;
	map<string, int> clsscnts;
	map<vector<string>, int> attrcnts;
	map<pair<vector<string>, string>, int> condcnts;
	map<pair<vector<string>, string>, float> condprobs;
	map<string, float>	clssprobs;
	Data data;
public:
	MAP(Data d);
	void print() const;
	void train();
	bool normalize();
	float value_weight(vector<string> attrs, string clval);
	vector<string> predict(vector<string> attrs);
	map<string, int> getClassCounts();
};
#endif
