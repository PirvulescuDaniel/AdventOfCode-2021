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

	char s[10001];
	char* pos;
	char temp[1000];
	int lenght, count = 0;

	while (!f.eof()) {

		f >> s;

		if (strlen(s) == 1) {
			
			for (int i = 1; i <= 4; i++) {
				f >> temp;
				lenght = strlen(temp);
				
				if (lenght == 2 || lenght == 4 || lenght == 3 || lenght == 7) {
					count++;
				}
			}

		}
		
	}

	std::cout << count;

	return 0;
}
