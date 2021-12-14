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
bool choose[10001][10001];

int di[] = {-1,0,1,0},
	dj[] = {0,1,0,-1};

int solve(int i, int j) {

	choose[i][j] = true;

	int len = 0;
	for (int k = 0; k <= 3; k++) {
		
		int iv = i + di[k];
		int jv = j + dj[k];

		if (1 <= iv && iv <= n && 1 <= jv && jv <= m && choose[iv][jv] != true && A[iv][jv] != 9) {
			len += 1 + solve(iv, jv);
		}

	}
	return len;
}

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

	vector<int> basins;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			
			if (choose[i][j] == false && A[i][j] != 9) {
				basins.push_back( solve(i, j) + 1 );
			}

		}
	}

	sort(basins.begin(), basins.end(), greater<int>());

	cout << basins[0] * basins[1] * basins[2];

	return 0;
}
