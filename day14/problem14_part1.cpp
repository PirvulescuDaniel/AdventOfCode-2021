#pragma warning(disable: 4996)

#include <fstream>
#include <iostream>
#include <vector>
#include <cstring>
#include <utility>
#include <map>
#include <algorithm>
using namespace std;

ifstream f("input.in");

vector<char> tmplt;
vector<pair<string, string>> elements;
map<char, long long> mp;
vector<long long> occurence;

int main() {

	char s[256], * p, sep[2] = { ' ' };

	while (!f.eof()) {

		f.getline(s, 256);

		if (strstr(s, "->") == NULL) {

			for (int i = 0; i < strlen(s); i++) {
				tmplt.push_back(s[i]);
			}

		}
		else {

			string val1 = "";
			string val2 = "";

			p = strtok(s, sep);
			while (p != NULL) {

				if (strlen(p) == 2 && strstr(p, "->") == NULL) {
					for (int i = 0; i < strlen(p); i++) {
						val1.push_back(p[i]);
					}
				}

				if (strlen(p) == 1) {
					for (int i = 0; i < strlen(p); i++) {
						val2.push_back(p[i]);
					}
				}

				p = strtok(NULL, sep);
			}

			elements.push_back(make_pair(val1, val2));

		}

	}

	int steps = 10;
	string temp, insert;
	

	while (steps != 0) {

		for (long long i = 0; i < tmplt.size()-1; i++) {

			temp.clear();
			char insrt = {' '};

			temp.push_back(tmplt[i]);
			temp.push_back(tmplt[i + 1]);

			for (auto it = elements.begin(); it != elements.end(); it++) {
				if ((*it).first == temp) {
					insrt = (*it).second[0];
				}
			}

			if (insrt != ' ') {
				auto it = tmplt.begin() + i+1;
				tmplt.insert(it, insrt);
				i++;
			}

		}

		steps--;
	}

	for (auto it = tmplt.begin(); it != tmplt.end(); it++) {
		mp[*it]++;
	}


	for (auto it = mp.begin(); it != mp.end(); it++) {
		occurence.push_back((*it).second);
	}

	std::sort(occurence.begin(), occurence.end());

	cout << occurence[occurence.size() - 1] - occurence[0];

	return 0;
}
