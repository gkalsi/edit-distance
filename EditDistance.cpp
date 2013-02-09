#include "EditDistance.hpp"
#include <string>
#include <iostream>

using namespace std;

int editDistanceRecursive(string& s, string& t, int i, int j) {
	if (i == s.size()) return t.size() - j;
	if (j == t.size()) return s.size() - i;

	int opt[3];
	opt[0] = editDistanceRecursive(s, t, i + 1, j);
	opt[1] = editDistanceRecursive(s, t, i, j + 1);
	opt[2] = editDistanceRecursive(s, t, i + 1, j + 1);

	int optsMin = opt[0];
	for (int a = 0; a < 3; a++) {
		if (opt[a] < optsMin) {
			optsMin = opt[a];
		}
	}

	if (s[i] != t[j]) {
		return optsMin + 1;
	} else {
		return optsMin;
	}
}

int EditDistance::editDistance(string& s, string& t) {
	return editDistanceRecursive(s, t, 0, 0);
}

int match(char s, char t) {
	if (s == t) return 0;
	return 1;
}

int EditDistance::editDistanceFast(string s, string t) {
	s = ' ' + s;
	t = ' ' + t;
	int lookup[s.size() + 1][t.size() + 1];
	for (int i = 0; i <= s.size(); i++) {
		for (int j = 0; j <= t.size(); j++) {
			lookup[i][j] = 0;
		}
	}

	int opt[3];
	int i, j;
	for (i = 1; i < s.size(); i++) {
		for (j = 1; j < t.size(); j++) {
			opt[0] = lookup[i - 1][j - 1] + match(s[i], t[j]);
			opt[1] = lookup[i][j - 1] + 1;
			opt[2] = lookup[i - 1][j] + 1;

			lookup[i][j] = opt[0];
			for (int a = 0; a < 3; a++) {
				if (opt[a] < lookup[i][j]) {
					lookup[i][j] = opt[a];
				}
			}
		}
	}
	return lookup[s.size() - 1][t.size() - 1];
}
