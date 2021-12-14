#pragma warning(disable: 4996)

#include <fstream>
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

ifstream f("input.in");

int main() {

	int a;
	char s[1001], sep[5] = { ',',' ' };
	f >> s;

	vector<int> numbers;
	vector<int> sums;

	char* p = strtok(s, sep);
	while (p != NULL) {
		a = atoi(p);
		numbers.push_back(a);
		p = strtok(NULL, sep);
	}

	int A[1000][6][6], sum, tableNo = 0, winTable, lastNumber;
	bool marked[1000][6][6], temp, win = false;

	while (!f.eof()) {

		sum = 0;
		for (int i = 1; i <= 5; i++) {
			for (int j = 1; j <= 5; j++) {
				f >> A[tableNo][i][j];
				marked[tableNo][i][j] = false;
				sum += A[tableNo][i][j];
			}
		}
		sums.push_back(sum);

		tableNo++;

	}

	for (auto it = numbers.begin(); it != numbers.end() && win==false; it++) {

		//marcam *it in toate tablitele

		for (int k = 0; k < tableNo; k++) {
			for (int i = 1; i <= 5; i++) {
				for (int j = 1; j <= 5; j++) {
					if (A[k][i][j] == *it) {
						marked[k][i][j] = true;
					}
				}
			}
		}

		//verificam daca a castigat vreo tablita
		for (int k = 0; k < tableNo && win==false; k++) {

			//pe linie
			for (int i = 1; i <= 5; i++) {
				temp = true;
				for (int j = 1; j <= 5; j++) {
					if (marked[k][i][j] == false) {
						temp = false;
					}
				}

				if (temp == true) {
					win = true;
					winTable = k;
					lastNumber = *it;
				}
			}

			//pe coloana
			for (int j = 1; j <= 5; j++) {
				temp = true;
				for (int i = 1; i <= 5; i++) {
					if (marked[k][i][j] == false) {
						temp = false;
					}
				}

				if (temp == true) {
					win = true;
					winTable = k;
					lastNumber = *it;
				}
			}

		}

	}

	int sumCheck = 0;
	for (int i = 1; i <= 5; i++) {
		for (int j = 1; j <= 5; j++) {
			if (marked[winTable][i][j] == true) {
				sumCheck += A[winTable][i][j];
			}
		}
	}

	cout << (sums[winTable] - sumCheck) * lastNumber;

	return 0;
}
