#pragma warning(disable: 4996)

#include <fstream>
#include <iostream>
#include <vector>
#include <cstring>
#include <utility>
#include <string>
#include <algorithm>
using namespace std;

int n = 100;
int m = 100;

ifstream f("input.in");

vector<char> imageEnh;
char otp[1500][1500];

void extendImage(char A[][1000]) {

	int times = 2;
	
	while (times != 0) {
		m++;
		for (int i = 1; i <= n; i++) {
			for (int j = m; j >= 2; j--) {
				A[i][j] = A[i][j - 1];
			}
		}

		for (int i = 1; i <= n; i++) {
			A[i][1] = '.';
		}
		times--;
	}

	times = 2;
	while (times != 0) {

		m++;
		for (int i = 1; i <= n; i++) {
			A[i][m] = '.';
		}

		times--;
	}

	times = 2;
	while (times != 0) {

		n++;
		for (int i = n; i >= 2; i--) {
			for (int j = 1; j <= m; j++) {
				A[i][j] = A[i - 1][j];
			}
		}

		for (int j = 1; j <= m; j++) {
			A[1][j] = '.';
		}

		times--;
	}

	times = 2;
	while (times != 0) {

		n++;
		for (int j = 1; j <= m; j++) {
			A[n][j] = '.';
		}

		times--;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			otp[i][j] = '.';
		}
	}

}

void bin_to_dec(string s, int i, int j) {

	int dec = 0;
	int index = 0;
	for (int i = s.length() - 1; i >= 0; i--) {
		if (s[i] == '1') {
			dec += pow(2, index);
		}
		index++;
	}

	otp[i][j] = imageEnh[dec];

}

void create_strings(char A[][1000]) {

	extendImage(A);

	string str;
	for (int i = 2; i <= n-1; i++) {
		for (int j = 2; j <= m-1; j++) {

			str.push_back(A[i - 1][j - 1]);
			str.push_back(A[i - 1][j]);
			str.push_back(A[i - 1][j + 1]);

			str.push_back(A[i][j - 1]);
			str.push_back(A[i][j]);
			str.push_back(A[i][j + 1]);

			str.push_back(A[i + 1][j - 1]);
			str.push_back(A[i + 1][j]);
			str.push_back(A[i + 1][j + 1]);

			
			string bin;
			for (int k = 0; k < str.length(); k++) {
				if (str[k] == '#') {
					bin.push_back('1');
				}
				else {
					bin.push_back('0');
				}
			}

			bin_to_dec(bin,i,j);

			bin.clear();
			str.clear();
		}
	}

}

int main() {

	char s[1500];
	char A[1000][1000];

	while (!f.eof()) {

		f >> s;
		for (int i = 0; i < strlen(s); i++) {
			imageEnh.push_back(s[i]);
		}

		for (int i = 1; i <= n; i++) {
			f >> s;
			for (int j = 1; j <= m; j++) {
				int cnt = 1;
				for (int k = 0; k < strlen(s); k++) {
					A[i][cnt] = s[k];
					cnt++;
				}

			}
		}

	}

	int steps = 50;

	while (steps != 0) {
		create_strings(A);

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				A[i][j] = otp[i][j];
			}
		}

		steps--;
	}
	
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (otp[i][j] == '#') {
				cnt++;
			}
		}
	}
	
	cout << cnt;
	
	return 0;
}
