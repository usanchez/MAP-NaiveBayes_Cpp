#ifndef MAP_H
#define MAP_H
#include <iostream>
#include <fstream>
#include <vector>
#include "Data.h"

using namespace std;

class MAP
{
private:	
	bool normalized;
	array clsscnts;
	vector<int> condcnts;
	vector<int> attrcnts;
	vector<int> condprobs;
	vector<int>	clssprobs;
	Data data;
public:
	MAP(Data d);
	void print() const;
	void train();
	void normalize();
};
#endif
