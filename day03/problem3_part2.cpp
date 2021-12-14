#include <fstream>
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

ifstream f("input.in");

#define n 1000 // no of lines
#define m 12 //lenght of a line

char A[1005][1005];
vector<char> MSB; //Most significant bit
vector<char> LSB; //less significant bit
bool deleted[1005];

//return the number of lines that match bit criteria
int remainNumbers() {

	int remains = 0;

	for (int i = 1; i <= n; i++) {
		if (deleted[i] == false) {
			remains++;
		}
	}
	return remains;
}

int main() {

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			f >> A[i][j];
		}
	}

	int noOf0, noOf1;

	int index = 1;
	do{

		noOf0 = 0;
		noOf1 = 0;

		for (int k = 1; k <= n; k++) {

			if (deleted[k] == false) {
				if (A[k][index] == '1') {
					noOf1++;
				}
				else {
					noOf0++;
				}
			}
		}

		if (noOf1 >= noOf0) {
			MSB.push_back('1');
		}
		else {
			MSB.push_back('0');
		}

		for (int i = 1; i <= n; i++) {

			if (MSB.back() != A[i][index]) {
				deleted[i] = true;
			}
		}

		index++;

	} while (remainNumbers()!=1);

	int line;
	for (int i = 1; i <= n; i++) {
		if (deleted[i] == false) {
			line = i;
		}
	}

	int oxygen = 0;
	int power = 0;
	for (int j = m; j >= 1; j--) {
		if (A[line][j] == '1') {
			oxygen+= pow(2, power);
		}
		power++;
	}

	//cout << oxygen << endl;

	for (int i = 1; i <= n; i++) {
		deleted[i] = false;
	}

	index = 1;
	do {

		noOf0 = 0;
		noOf1 = 0;

		for (int k = 1; k <= n; k++) {

			if (deleted[k] == false) {
				if (A[k][index] == '1') {
					noOf1++;
				}
				else {
					noOf0++;
				}
			}
		}

		if (noOf0 <= noOf1) {
			LSB.push_back('0');
		}
		else {
			LSB.push_back('1');
		}

		for (int i = 1; i <= n; i++) {

			if (LSB.back() != A[i][index]) {
				deleted[i] = true;
			}
		}

		index++;

	} while (remainNumbers() != 1);
	

	for (int i = 1; i <= n; i++) {
		if (deleted[i] == false) {
			line = i;
		}
	}

	int CO2 = 0;
	power = 0;
	for (int j = m; j >= 1; j--) {
		if (A[line][j] == '1') {
			CO2 += pow(2, power);
		}
		power++;
	}

	//cout << CO2;

	cout << oxygen * CO2;

	return 0;
}
