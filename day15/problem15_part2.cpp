#pragma warning(disable: 4996)

#include <fstream>
#include <iostream>
#include <vector>
#include <cstring>
#include <utility>
using namespace std;

ifstream f("input.in");

#define INF 1000007

int di[] = {-1,0,1,0},
	dj[] = {0,1,0,-1};

int n, m;
int A[10001][10001];

bool computed[10001][10001];

bool visited[1001][1001];
int weights[1001][1001];

int main() {

	char s[10000];

	n = 0;
	m = 0;

	while (!f.eof()) {

		n++;

		f >> s;

		m = 0;
		for (int i = 0; i < strlen(s); i++) {
			m++;
			A[n][m] = s[i] - '0';
			computed[n][m] = true;
		}

	}

	//construct 5X5 grid
	for (int i = 1; i <= 5 * n; i++) {
		for (int j = 1; j <=m; j++) {
			
			if (computed[i][j] == false) {
				A[i][j] = A[i - n][j] + 1;
				if (A[i][j] > 9) {
					A[i][j] = 1;
				}
				computed[i][j] = true;
			}

		}
	}

	for (int i = 1; i <= 5 * n; i++) {
		for (int j = m + 1; j <= 5 * m; j++) {

			if (computed[i][j] == false) {
				A[i][j] = A[i][j - m] + 1;
				if (A[i][j] > 9) {
					A[i][j] = 1;
				}
				computed[i][j] = true;
			}

		}
	}

	//set the weights to INF
	for (int i = 1; i <= 5 * n; i++) {
		for (int j = 1; j <= 5 * m; j++) {
			weights[i][j] = INF;
		}
	}
	weights[1][1] = 0;

	int i = 1;
	int j = 1;

	int steps = 25 * n * m;

	//dijkstra
	while (steps!=0) {

		visited[i][j] = true;

		for (int k = 0; k <= 3; k++) {

			int iv = i + di[k];
			int jv = j + dj[k];

			if (1 <= iv && iv <= 5 * n && 1 <= jv && jv <= 5 * m && visited[iv][jv] == false) {

				int tempWeight = weights[i][j] + A[iv][jv];

				if (tempWeight < weights[iv][jv]) {
					weights[iv][jv] = tempWeight;
				}

			}

		}

		int iv_minW = -1;
		int jv_minW = -1;
		int minW = INF;

		for (int q = 1; q < 5 * n; q++) {
			for (int w = 1; w <= 5 * m; w++) {
				if (visited[q][w] == false && weights[q][w] < minW) {
					minW = weights[q][w];
					iv_minW = q;
					jv_minW = w;
				}
			}
		}

		if (iv_minW != -1 && jv_minW != -1) {
			i = iv_minW;
			j = jv_minW;
		}

		steps--;

	}

	weights[5 * n][5 * m] = min(weights[(5 * n) - 1][5 * m], weights[5 * n][(5 * m) - 1]) + A[5 * n][5 * m];
	cout << weights[5 * n][5 * m];

	return 0;
}
