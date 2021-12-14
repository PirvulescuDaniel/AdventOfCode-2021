#pragma warning(disable: 4996)

#include <fstream>
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <utility>
using namespace std;

ifstream f("input.in");

//x - column
//y - line

struct vent {
	int x1, y1;
	int x2, y2;
};

vector<vent> vents;

int matrix[1000][1000];

int main() {


	char s[100], sep[5] = { ' ' }, sep1[5] = { ',' };
	char* p;
	vent tempVent;
	int val, index, swch = 1, maxLine = 0, maxColumn = 0;

	while (!f.eof()) {

		f >> s;
		if (strchr(s, ',') != NULL) {
			
			p = strtok(s, sep1);

			index = 0;
			while (p != NULL) {
				val = atoi(p);
				if (swch % 2 == 1) {
					if (index == 0) {
						tempVent.x1 = val;
						if (val >= maxColumn) maxColumn = val;
					}
					else {
						tempVent.y1 = val;
						if (val >= maxLine) maxLine = val;
					}
					
				}
				else {
					if (index == 0) {
						tempVent.x2 = val;
						if (val >= maxColumn) maxColumn = val;
					}
					else {
						tempVent.y2 = val;
						if (val >= maxLine) maxLine = val;

						vents.push_back(tempVent);

					}
					
				}
				index++;
				p = strtok(NULL, sep);
			}
			swch++;

		}

	}

	int aux;
	int col1, col2;
	int line1, line2;
	int istart, jstart, istop, jstop;
	bool choose;
	for (auto it = vents.begin(); it != vents.end(); it++) {
		
		//horizontal
		if ((*it).y1 == (*it).y2) {

			col1 = (*it).x1;
			col2 = (*it).x2;

			if (col1 > col2) {
				aux = col1;
				col1 = col2;
				col2 = aux;
			}

			for (int i = col1; i <= col2; i++) {
				matrix[(*it).y1][i]++;
			}

		}else
		if ((*it).x1 == (*it).x2) { //vertical

			line1 = (*it).y1;
			line2 = (*it).y2;

			if (line1 > line2) {
				aux = line1;
				line1 = line2;
				line2 = aux;
			}

			for (int i = line1; i <= line2; i++) {
				matrix[i][(*it).x1]++;
			}

		}
		
	}

	int points = 0;
	for (int i = 0; i <= maxLine; i++) {
		for (int j = 0; j <= maxColumn; j++) {
			if (matrix[i][j] >= 2) {
				points++;
			}
		}
	}
	
	cout << points;

	return 0;
}
