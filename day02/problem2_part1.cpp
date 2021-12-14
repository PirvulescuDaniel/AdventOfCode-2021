#include <fstream>
#include <iostream>
using namespace std;

ifstream f("input.in");

int main() {

	string s;
	int val;

	int depth = 0;
	int horizontal = 0;

	while (!f.eof()) {

		f >> s >> val;

		if (s == "forward") {
			horizontal += val;
		}
		else if (s == "down") {
			depth += val;
		}
		else if (s == "up") {
			depth -= val;
		}


	}

	cout << depth * horizontal;

	return 0;
}
