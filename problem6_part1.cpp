#pragma warning(disable: 4996)

#include <fstream>
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <utility>
using namespace std;

ifstream f("input.in");

vector<int> fishes;

int main() {

	char s[10001], sep[5] = {','};
	int val;

	f >> s;

	char* p = strtok(s, sep);
	while (p != NULL) {
		val = atoi(p);
		fishes.push_back(val);
		p = strtok(NULL, sep);
	}
	
	unsigned long long n = fishes.size();
	int days = 18;

	while (days != 0) {
		for (int i = 0; i < n; i++) {

			fishes[i] --;

			if (fishes[i] == -1) {
				fishes[i] = 6;
				fishes.push_back(8);
			}

		}
		days--;
		n = fishes.size();
	}

	cout << fishes.size();



	return 0;
}
