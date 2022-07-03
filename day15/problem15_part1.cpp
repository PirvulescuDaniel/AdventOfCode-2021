#pragma warning(disable: 4996)

#include <fstream>
#include <iostream>
#include <vector>
#include <cstring>
#include <utility>
using namespace std;

#define maxx 99999

ifstream f("input.in");

int n, m;
int A[1001][1001];

bool ready[1001][1001];
int dp[1001][1001];

int solve(int i, int j) {

	if (i == 0) {
		return maxx;
	}
	if (j == 0) {
		return maxx;
	}

	if (i == 1 && j == 1) {
		return A[1][1];
	}

	if (ready[i][j]==true) {
		return dp[i][j];
	}

	dp[i][j] = std::min(solve(i - 1, j), solve(i, j - 1)) + A[i][j];
	ready[i][j] = true;

	return dp[i][j];
}

int main() {

	char s[1000];

	n = 0;
	m = 0;

	while (!f.eof()) {

		n++;

		f >> s;

		m =0;
		for (int i = 0; i < strlen(s); i++) {
			m++;
			A[n][m] = s[i] - '0';
		}

	}

	cout << solve(n, m) - A[1][1];

	return 0;
}
