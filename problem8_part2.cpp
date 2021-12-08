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

map<int, string> code;

char* reunion(char a[], char b[]) {

	char temp1[20];
	char temp2[20];

	for (int i = 1; i < strlen(temp1); i++) {

		if (strchr(temp2, temp1[i]) == NULL) {
			strcat(temp2, temp1[i]);
		}

	}

}

int main() {

	char s[10001], * p, sep[2] = { '|' }, * temp, sep1[2] = { ' ' };

	char unu[10], doi[10], trei[10], patru[10], cinci[10], sase[10], sapte[10], opt[10], noua[10], zero[10];

	while (!f.eof()) {

		f.getline(s, 10001);

		p = strtok(s, sep);
		
		temp = strtok(p, sep1);
		while (temp != NULL) {

			if (strlen(temp) == 2) {
				strcpy(unu, temp);
			}

			if (strlen(temp) == 3) {
				strcpy(sapte, temp);
			}

			if (strlen(temp) == 4) {
				strcpy(patru, temp);
			}

			if (strlen(temp) == 7) {
				strcpy(opt, temp);
			}

			temp = strtok(NULL, sep1);
		}

		

	}

	return 0;
}
