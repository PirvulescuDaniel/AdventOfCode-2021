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
#include <set>
using namespace std;

/*
	This problem has been resolved with backtracking
	and you should wait approximately 5 mins for the solution
*/

ifstream f("input.in");

set<string> caves;
vector<pair<string, string>> lab;
string path[10001];
int no_of_paths = 0;

bool is_upper(string s) {

	bool upper = true;

	for (int i = 0; i < s.size(); i++) {
		if (isupper(s[i]) == 0) {
			upper = false;
			break;
		}
	}

	if (upper == true) {
		return true;
	}
	else {
		return false;
	}
}


bool ok(int k) {

	//path will always start with "first"
	if (k == 1) {
		if (path[k] == "start") {
			return true;
		}
		else {
			return false;
		}
	}

	//chech if there exists a path between k and k-1
	pair<string, string> temp;
	temp.first = path[k];
	temp.second = path[k - 1];

	bool found = false;
	for (auto it = lab.begin(); it != lab.end(); it++) {
		if ((*it).first == temp.first && (*it).second == temp.second) {
			found = true;
		}

		if ((*it).second == temp.first && (*it).first == temp.second) {
			found = true;
		}
	}

	if (found == false) {
		return false;
	}

	//check for "start" and "end" duplicates
	int noOfStart = 0;
	int noOfEnd = 0;
	for (int i = 1; i <= k; i++) {
		if (path[i] == "start") {
			noOfStart++;
		}

		if (path[i] == "end") {
			noOfEnd++;
		}
	}

	if (noOfStart >= 2 || noOfEnd >= 2) {
		return false;
	}

	//check for lower caves duplicates

	int no_of_duplicates = 0;

	for (int i = 1; i <= k-1; i++) {
		for (int j = i + 1; j <= k; j++) {
			if (path[i] == path[j] && is_upper(path[i]) == false) {
				no_of_duplicates++;
			}
		}
	}

	if (no_of_duplicates < 2) {
		return true;
	}
	else {
		return false;
	}
}

bool solution(int k) {
	if (path[k] == "end") {
		return true;
	}
	return false;
}

void show(int k) {
	for (int i = 1; i <= k; i++) {
		cout << path[i] << " ";
	}
	cout << endl;
}

void back(int k) {

	for (auto it = caves.begin(); it != caves.end(); it++) {

		path[k] = *it;

		if (ok(k)) {
			if (solution(k)) {
				show(k);
				no_of_paths++;
			}
			else {
				back(k + 1);
			}
		}
	}

}


int main() {

	char s[20], * p, sep[2] = { '-' };
	string from, to;

	while (!f.eof()) {

		from = "none";
		to = "none";

		f >> s;
		p = strtok(s, sep);
		while (p != NULL) {

			if (from == "none") {
				from = p;
			}
			else {
				to = p;
			}

			p = strtok(NULL, sep);
		}

		lab.push_back(make_pair(from, to));
		caves.insert(from);
		caves.insert(to);

	}

	back(1);
	cout << no_of_paths;

	return 0;
}
