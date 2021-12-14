#include <fstream>
#include <iostream>
using namespace std;

ifstream f("input.in");

int main() {

	string s;
	int val;

	int depth = 0;
	int horizontal = 0;
	int aim = 0;

	while (!f.eof()) {

		f >> s >> val;

		if (s == "forward") {
			horizontal += val;
			depth += aim * val;
		}
		else if (s == "down") {
			aim += val;
		}
		else if (s == "up") {
			aim -= val;
		}


	}

	cout << depth * horizontal;

	return 0;
}
