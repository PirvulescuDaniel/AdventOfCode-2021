#pragma warning(disable: 4996)

#include <fstream>
#include <iostream>
#include <vector>
#include <cstring>
#include <utility>
using namespace std;

ifstream f("input.in");

vector<pair<int, int>> coordonates;
vector<pair<char, int>> instructions;
char A[10000][10000];
char temp1[10000][10000];
char temp2[10000][10000];

char s[100], * p, sep[3] = { ',' }, val1, val2;
int lines = -1, column = -1;

void horizontal_cut(int y) {

	int temp1lines = -1;
	int temp2lines = -1;

	//"cut" the matrix
	for (int i = 0; i <= lines; i++) {
		if (i < y) {
			temp1lines++;
		}
		if (i > y) {
			temp2lines++;
		}
		for (int j = 0; j <= column; j++) {

			if (i < y) {
				temp1[temp1lines][j] = A[i][j];
			}
			if (i > y) {
				temp2[temp2lines][j] = A[i][j];
			}
		}
	}

	//differences
	if (temp1lines > temp2lines) {
		while (temp1lines != temp2lines) {
			temp2lines++;
			for (int j = 0; j <= column; j++) {
				temp2[temp2lines][j] = '.';
			}
		}
	}

	if (temp1lines < temp2lines) {

		while (temp1lines != temp2lines) {
			temp1lines++;
			for (int i = temp1lines; i >= 1; i--) {
				for (int j = 0; j <= column; j++) {
					temp1[i][j] = temp1[i - 1][j];
				}
			}

			for (int j = 0; j <= column; j++) {
				temp1[0][j] = '.';
			}
		}

	}

	//reverse second matrix
	char aux;
	for (int i = 0; i <= temp2lines / 2; i++) {
		for (int j = 0; j <= column; j++) {
			aux = temp2[i][j];
			temp2[i][j] = temp2[temp2lines - i][j];
			temp2[temp2lines - i][j] = aux;
		}
	}

	//concatenate temp1 and temp2
	for (int i = 0; i <= temp1lines; i++) {
		for (int j = 0; j <= column; j++) {
			if (temp1[i][j] == '#' || temp2[i][j] == '#') {
				A[i][j] = '#';
			}
			else {
				A[i][j] = '.';
			}
		}
	}
	lines = temp1lines;

}

void vertical_cut(int x) {

	int temp1col = -1;
	int temp2col = -1;

	//"cut" the matrix
	for (int j = 0; j <= column; j++) {
		if (j < x) {
			temp1col++;
		}
		if (j > x) {
			temp2col++;
		}
		for (int i = 0; i <= lines; i++) {
			if (j < x) {
				temp1[i][temp1col] = A[i][j];
			}
			if (j > x) {
				temp2[i][temp2col] = A[i][j];
			}
		}
	}

	//difference
	if (temp1col > temp2col) {
		while (temp1col != temp2col) {
			temp2col++;

			for (int i = 0; i <= lines; i++) {
				temp2[i][temp2col] = '.';
			}
		}
	}

	if (temp1col < temp2col) {
		while (temp1col != temp2col) {
			temp1col++;

			for (int j = temp1col; j >= 1; j--) {
				for (int i = 0; i <= lines; i++) {
					temp1[i][j] = temp1[i][j - 1];
				}
			}

			for (int i = 0; i <= lines; i++) {
				temp1[i][0] = '.';
			}
		}
	}

	//reverse temp1
	int aux;
	for (int i = 0; i <= lines; i++) {
		for (int j = 0; j < temp1col/2; j++) {
			aux = temp1[i][j];
			temp1[i][j] = temp1[i][temp1col - j];
			temp1[i][temp1col - j] = aux;
		}
	}

	//overlap
	for (int i = 0; i <= lines; i++) {
		for (int j = 0; j <= temp1col; j++) {
			if (temp1[i][j] == '#' || temp2[i][j] == '#') {
				A[i][j] = '#';
			}
			else {
				A[i][j] = '.';
			}
		}
	}
	column = temp1col;

}

int main() {

	while (!f.eof()) {

		f.getline(s, 256);

		if (strstr(s, "fold") != NULL) {

			char val1 = ' ';
			int val2 = 0;

			if (strchr(s, 'y') != NULL) {
				val1 = 'y';
			}
			if (strchr(s, 'x') != NULL) {
				val1 = 'x';
			}

			for (int i = 0; i < strlen(s); i++) {
				if (48 <= s[i] && s[i] <= 57) {
					val2 = (val2 * 10) + (s[i] - '0');
				}
			}

			instructions.push_back(make_pair(val1, val2));

		}
		else if (strstr(s, "fold") == NULL && strlen(s) >= 2) {

			int index = 1;
			pair<int, int> values;

			p = strtok(s, sep);
			while (p != NULL) {

				if (index == 1) {
					values.first = atoi(p);
					if (values.first > column) column = values.first;
				}
				else {
					values.second = atoi(p);
					if (values.second > lines) lines = values.second;
				}

				index++;
				p = strtok(NULL, sep);
			}

			coordonates.push_back(values);

		}

	}

	for (int i = 0; i <= lines; i++) {
		for (int j = 0; j <= lines; j++) {
			A[i][j] = '.';
		}
	}

	for (auto it = coordonates.begin(); it != coordonates.end(); it++) {
		A[(*it).second][(*it).first] = '#';
	}

	int no_of_instructions = 1;

	while (no_of_instructions != 0) {

		if (instructions[no_of_instructions - 1].first == 'y') {
			horizontal_cut(instructions[no_of_instructions - 1].second);
		}
		else {
			vertical_cut(instructions[no_of_instructions - 1].second);
		}

		no_of_instructions--;
	}

	int dots = 0;
	for (int i = 0; i <= lines; i++) {
		for (int j = 0; j <= column; j++) {
			if (A[i][j] == '#') {
				dots++;
			}
		}
	}

	cout << dots;

	return 0;
}
