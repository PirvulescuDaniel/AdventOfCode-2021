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

ifstream f("input.in");

int main() {

	string s, scopy;
	stack<char> stk;
	map<char, long long> bracket;
	bool corrupted;
	deque<char> deq;
	vector<long long> vec;

	bracket[')'] = 0;
	bracket[']'] = 0;
	bracket['}'] = 0;
	bracket['>'] = 0;

	while (!f.eof()) {

		f >> s;
		scopy = s;
		corrupted = false;

		for (int i = 0; i < s.length(); i++) {
			
			if (s[i] == '[' || s[i] == '(' || s[i] == '{' || s[i] == '<') {
				stk.push(s[i]);
			}
			else {

				if (s[i] == ')' && stk.top() != '(' ) {
					corrupted = true;
					break;
				}

				if (s[i] == ']' && stk.top() != '[') {
					corrupted = true;
					break;
				}

				if (s[i] == '}' && stk.top() != '{') {
					corrupted = true;
					break;
				}

				if (s[i] == '>' && stk.top() != '<') {
					corrupted = true;
					break;
				}

				stk.pop();

			}

		}

		while (stk.empty() != true) {
			stk.pop();
		}

		if (corrupted == false) {

			for (int i = 0; i < scopy.length(); i++) {

				if (scopy[i] == '[' || scopy[i] == '(' || scopy[i] == '{' || scopy[i] == '<') {
					stk.push(scopy[i]);
				}
				else {

					if (scopy[i] == ')' && stk.top() == '(') {
						stk.pop();
					}
					if (scopy[i] == ']' && stk.top() == '[') {
						stk.pop();
					}
					if (scopy[i] == '}' && stk.top() == '{') {
						stk.pop();
					}
					if (scopy[i] == '>' && stk.top() == '<') {
						stk.pop();
					}

				}

			}

			while (stk.empty() != true) {
				
				if (stk.top() == '(') {
					deq.push_back(')');
				}

				if (stk.top() == '[') {
					deq.push_back(']');
				}

				if (stk.top() == '{') {
					deq.push_back('}');
				}

				if (stk.top() == '<') {
					deq.push_back('>');
				}

				stk.pop();
			}

			long long score = 0;

			while (deq.empty() != true) {
				score *= 5;

				if (deq.front() == ')') {
					score += 1;
				}

				if (deq.front() == ']') {
					score += 2;
				}

				if (deq.front() == '}') {
					score += 3;
				}

				if (deq.front() == '>') {
					score += 4;
				}

				deq.pop_front();
			}
			vec.push_back(score);

			while (stk.empty() != true) {
				stk.pop();
			}
			
			deq.clear();
		}

		while (stk.empty() != true) {
			stk.pop();
		}
	}

	sort(vec.begin(), vec.end());

	cout << vec[vec.size() / 2];


	return 0;
}
