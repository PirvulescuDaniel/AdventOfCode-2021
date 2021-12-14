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

string reunion(string s1, string s2) {

	string temp;

	for (int i = 0; i < s1.length(); i++) {
		if (temp.find(s1[i]) == std::string::npos) {
			temp.push_back(s1[i]);
		}
	}

	for (int i = 0; i < s2.length(); i++) {
		if (temp.find(s2[i]) == std::string::npos) {
			temp.push_back(s2[i]);
		}
	}

	return temp;

}

void alpha_sort(string &s) {

	sort(s.begin(), s.end());

}

map<string, int> numbers;

int main() {

	char s[10001], * p, sep[2] = { '|' }, * temp, sep1[2] = { ' ' }, copy[10001], * q, * x;

	string one, two, three, four, five, six, seven, eight, nine, zero;
	string tmp;
	vector<string> codes;
	vector<string> outp;

	int SUM = 0;

	while (!f.eof()) {

		f.getline(s, 10001);
		strcpy(copy, s);

		p = strtok(s, sep);

		temp = strtok(p, sep1);
		while (temp != NULL) {

			for (int i = 0; i < strlen(temp); i++) {
				tmp.push_back(temp[i]);
			}

			codes.push_back(tmp);

			tmp.clear();

			temp = strtok(NULL, sep1);
		}

		for (int i = 0; i <= 9; i++) {
			
			if (codes[i].length() == 2) {
				one = codes[i];
				alpha_sort(one);
			}

			if (codes[i].length() == 3) {
				seven = codes[i];
				alpha_sort(seven);
			}

			if (codes[i].length() == 4) {
				four = codes[i];
				alpha_sort(four);
			}

			if (codes[i].length() == 7) {
				eight = codes[i];
				alpha_sort(eight);
			}

		}

		for (int i = 0; i <= 9; i++) {
			if (codes[i].length() == 5) {
				if (reunion(one, codes[i]).length() == 5) {
					three = codes[i];
					alpha_sort(three);
				}
			}
		}

		for (int i = 0; i <= 9; i++) {
			if (codes[i].length() == 6) {
				if (reunion(three, codes[i]).length() != 7) {
					nine = codes[i];
					alpha_sort(nine);
				}
			}
		}

		for (int i = 0; i <= 9; i++) {
			if (codes[i].length() == 5) {
				if (reunion(nine, codes[i]).length() == 7) {
					two = codes[i];
					alpha_sort(two);
				}
			}
		}

		for (int i = 0; i <= 9; i++) {
			if (codes[i].length() == 5) {
				if (reunion(two, codes[i]).length() == 7) {
					five = codes[i];
					alpha_sort(five);
				}
			}
		}

		for (int i = 0; i <= 9; i++) {
			if (codes[i].length() == 6) {
				if (reunion(one, codes[i]).length() == 7) {
					six = codes[i];
					alpha_sort(six);
				}
			}
		}

		for (int i = 0; i <= 9; i++) {
			if (codes[i].length() == 6) {
				if (reunion(five, codes[i]).length() == 7) {
					zero = codes[i];
					alpha_sort(zero);
				}
			}
		}

		numbers[zero] = 0;
		numbers[one] = 1;
		numbers[two] = 2;
		numbers[three] = 3;
		numbers[four] = 4;
		numbers[five] = 5;
		numbers[six] = 6;
		numbers[seven] = 7;
		numbers[eight] = 8;
		numbers[nine] = 9;

		q = strtok(copy, sep);
		int ind = 1;
		while (q != NULL) {

			if (ind == 2) {
				break;
			}
			ind++;

			q = strtok(NULL, sep);
		}

		x = strtok(q, sep1);
		string ss;
		while (x != NULL) {

			for (int i = 0; i < strlen(x); i++) {
				ss.push_back(x[i]);
			}
			alpha_sort(ss);

			outp.push_back(ss);

			ss.clear();

			x = strtok(NULL, sep1);
		}

		int prod = 0;
		for (int i = 0; i < outp.size(); i++) {
			prod = prod * 10 + numbers[outp[i]];
		}

		SUM += prod;

		outp.clear();
		numbers.clear();
		codes.clear();

	}

	cout << SUM;

	return 0;
}
