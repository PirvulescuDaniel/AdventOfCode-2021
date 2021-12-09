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

#define n 100
#define m 100

int A[10001][10001];

int main() {

	string s;
	int i = 1;

	while (!f.eof()) {

		f >> s;

		for (int j = 1; j <= s.length(); j++) {
			A[i][j] = s[j-1] - '0';
		}
		i++;
	}

	for (int j = 0; j <= m + 1; j++) {
		A[0][j] = 10;
		A[n + 1][j] = 10;
	}
	for (int i = 0; i <= n + 1; i++) {
		A[i][0] = 10;
		A[i][m + 1] = 10;
	}

	int sum = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (A[i][j] < A[i - 1][j] && A[i][j] < A[i][j + 1] && A[i][j] < A[i + 1][j] && A[i][j] < A[i][j - 1]) {
				sum += A[i][j] + 1;
			}
		}
	}

	cout << sum;

	return 0;
}
