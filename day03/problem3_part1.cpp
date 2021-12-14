#include <fstream>
#include <iostream>
#include <cmath>
using namespace std;

ifstream f("input.in");

#define n 1000 // no of lines
#define m 12 //lenght of a line

char A[1005][1005];
char gammaBin[1005];
int gamma = 0;
int epsilon = 0;

int main() {

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			f >> A[i][j];
		}
	}

	int noOf0, noOf1;

	for (int j = 1; j <= m; j++) {

		noOf0 = 0;
		noOf1 = 0;

		for (int i = 1; i <= n; i++) {

			if (A[i][j] == '0') {
				noOf0++;
			}
			else {
				noOf1++;
			}

		}

		if (noOf0 >= noOf1) {
			gammaBin[j] = '0';
		}
		else {
			gammaBin[j] = '1';
		}

	}

	int index = 0;
	for (int j = m; j >= 1; j--) {
		if (gammaBin[j] == '1') {
			gamma += pow(2, index);
		}
		else {
			epsilon += pow(2, index);
		}
		index++;
	}

	cout << gamma * epsilon;

	return 0;
}
