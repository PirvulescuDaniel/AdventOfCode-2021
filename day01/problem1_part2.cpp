#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

ifstream f("input.in");

int main() {

	vector<int> v;
	vector<int> u;
	int a, c = 0, sum = 0;

	while (!f.eof()) {

		f >> a;
		v.push_back(a);

	}

	auto it1 = v.begin();
	auto it2 = v.begin() + 2;

	while (it2 != v.end()) {

		sum = *it1 + *(it1 + 1) + *(it1 + 2);
		u.push_back(sum);

		it1++;
		it2++;

	}

	for (auto it = u.begin()+1; it != u.end(); it++) {

		if (*it - *(it - 1) > 0) {
			c++;
		}

	}

	cout << c;

	return 0;
}
