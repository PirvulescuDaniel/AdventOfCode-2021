#pragma warning(disable: 4996)

#include <fstream>
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <utility>
#include <map>
using namespace std;

ifstream f("input.in");

int main() {

	vector<int> pos;

	char s[10001], sep[2] = { ',' };
	int val;
	f >> s;

	char* p = strtok(s, sep);
	while (p != NULL) {
		val = atoi(p);
		pos.push_back(val);
		p = strtok(NULL, sep);
	}

	sort(pos.begin(), pos.end());
	
	int n = pos.size() - 1;
	int middle = n / 2;

	int cost = 0;
	for (auto it = pos.begin(); it != pos.end(); it++) {
		cost += abs(*it - pos[middle]);
	}

	cout << cost;


	return 0;
}
