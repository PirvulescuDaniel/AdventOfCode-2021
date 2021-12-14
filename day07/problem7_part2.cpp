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

#define INF 100000008

int main() {

	vector<int> pos;

	char s[10001], sep[2] = { ',' };
	long long val, min=999999, max=-1;
	f >> s;

	char* p = strtok(s, sep);
	while (p != NULL) {
		val = atoi(p);
		pos.push_back(val);

		if (val > max) {
			max = val;
		}

		if (val < min) {
			min = val;
		}

		p = strtok(NULL, sep);
	}
  
  //THIS IS AN INEFFICIENT SOLUTION
  
	int nr;
	int cost_min = INF;
	for (int i = min; i <= max; i++) {

		nr = i;

		int cost = 0;
		for (auto it = pos.begin(); it != pos.end(); it++) {
			int dif = abs(*it - nr);
			cost += (dif * (dif + 1)) / 2;
		}

		if (cost < cost_min) {
			cost_min = cost;
		}

	}

	cout << cost_min;

	return 0;
}
