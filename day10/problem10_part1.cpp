#pragma warning(disable: 4996)

#include <fstream>
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <utility>
#include <map>
#include <stack> 
using namespace std;

ifstream f("input.in");

int main() {

	string s;
	stack<char> stk;
	map<char, int> bracket;

	bracket[')'] = 0;
	bracket[']'] = 0;
	bracket['}'] = 0;
	bracket['>'] = 0;

	while (!f.eof()) {

		f >> s;

		for (int i = 0; i < s.length(); i++) {
			
			if (s[i] == '[' || s[i] == '(' || s[i] == '{' || s[i] == '<') {
				stk.push(s[i]);
			}
			else {

				if (s[i] == ')' && stk.top() != '(' ) {
					bracket[')'] ++;
					break;
				}

				if (s[i] == ']' && stk.top() != '[') {
					bracket[']'] ++;
					break;
				}

				if (s[i] == '}' && stk.top() != '{') {
					bracket['}'] ++;
					break;
				}

				if (s[i] == '>' && stk.top() != '<') {
					bracket['>'] ++;
					break;
				}

				stk.pop();

			}

		}

		while (stk.empty() != true) {
			stk.pop();
		}
	}

	long sum = 0;
	sum = (bracket[')'] * 3) + (bracket[']'] * 57) + (bracket['}'] * 1197) + (bracket['>'] * 25137);

	cout << sum;
 
	return 0;
}
