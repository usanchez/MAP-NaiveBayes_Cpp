#ifndef CONFMAT_H
#define CONFMAT_H

#include <map>

using namespace std;

class ConfMat {
private:
	map<string, string> classmap;
public:
	map<pair<string, string>, int> mat; // confusion matrix
	ConfMat(map<string, int> clsscnts);
	void report();
	void increaseValue(pair<string, string> p);

};


#endif
