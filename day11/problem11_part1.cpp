#pragma warning(disable: 4996)

#include <fstream>
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <utility>
#include <map>
#include <stack> 
#include <deque>
using namespace std;

int A[101][101];
bool exploded[101][101];

#define n 10
#define m 10

int di[] = {-1,-1,-1,0,1,1,1,0},
	dj[] = {-1,0,1,1,1,0,-1,-1};

ifstream f("input.in");

void set_false() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			exploded[i][j] = false;
		}
	}
}

void solve(int i, int j) {

	if (exploded[i][j] == false) {
		A[i][j]++;
	}

	if (A[i][j] > 9) {
		exploded[i][j] = true;
		A[i][j] = 0;

		for (int k = 0; k <= 7; k++) {

			int iv = i + di[k];
			int jv = j + dj[k];

			if (1 <= iv && iv <= n && 1 <= jv && jv <= m) {
				solve(iv, jv);
			}

		}

	}

}

int main() {

	char a;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			f >> a;
			A[i][j] = a - '0';
		}
	}

	int steps = 100;
	int expl = 0;
	
	while (steps != 0) {

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				solve(i, j);
			}
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (exploded[i][j] == true) {
					expl++;
					A[i][j] = 0;
				}
			}
		}
		set_false();
		steps--;
	}

	cout << endl << expl;

	return 0;
}
