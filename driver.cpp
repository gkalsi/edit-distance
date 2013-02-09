#include <string>
#include <iostream>
#include <cstdlib>
#include "EditDistance.hpp"

using namespace std;

int main(int argc, char** argv) {
	if (argc < 3 || argc > 4) {
		cerr << "Must provide exactly 2 arguments." << endl;
		exit(-1);
	}

	string opt(argv[1]);
	if (opt == "-f") {
		string s(argv[2]);
		string t(argv[3]);
		cout << EditDistance::editDistanceFast(s,t) << endl;
	} else {
		string s(argv[1]);
		string t(argv[2]);
		cout << EditDistance::editDistance(s,t) << endl;
	}
	return 0;
}