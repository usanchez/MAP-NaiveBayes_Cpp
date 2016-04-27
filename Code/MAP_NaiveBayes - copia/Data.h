#ifndef DATA_H
#define DATA_H
#include <iostream>
#include <vector>

using namespace std;

class Data
{
private:
	int N;
	string filename;
	int justtrain;
	vector<string> headers;
	bool header;
public:
	vector<pair<vector<string>, string>> training_set;
	vector<pair<vector<string>, string>> test_set;
	Data(string f, int j);
	void report();

};
#endif

