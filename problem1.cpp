#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

ifstream f("input.in");

int main() {

	vector<int> v;
	int a, c = 0;

	while (!f.eof()) {

		f >> a;
		v.push_back(a);

	}

	for (auto it = v.begin()+1; it != v.end(); it++) {

		if (*it - *(it - 1) > 0) {
			c++;
		}

	}

	cout << c;

	return 0;
}
