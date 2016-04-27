#include "Utils.h"

using namespace std;

vector<string> split(string in, const char * delim) {
	vector<string> out;
	char * dup = strdup(in.c_str());
	char * token = strtok(dup, delim);
	while (token != NULL) {
		out.push_back(string(token));
		// the call is treated as a subsequent calls to strtok:
		// the function continues from where it left in previous invocation
		token = strtok(NULL, " ");
	}
	free(dup);
	return out;
}

string& trim_right_inplace(
	std::string&       s,
	const std::string& delimiters = " \f\n\r\t\v") {
	return s.erase(s.find_last_not_of(delimiters) + 1);
}

string& trim_left_inplace(
	std::string&       s,
	const std::string& delimiters = " \f\n\r\t\v") {
	return s.erase(0, s.find_first_not_of(delimiters));
}

string& trim_inplace(
	std::string&       s,
	const std::string& delimiters = " \f\n\r\t\v") {
	return trim_left_inplace(trim_right_inplace(s, delimiters), delimiters);
}