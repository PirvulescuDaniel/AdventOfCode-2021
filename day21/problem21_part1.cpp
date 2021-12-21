#pragma warning(disable: 4996)

#include <fstream>
#include <iostream>
#include <vector>
#include <cstring>
#include <utility>
#include <string>
#include <algorithm>
using namespace std;

ifstream f("input.in");

int player1_pos;
int player2_pos;

int main() {

	player1_pos = 6;
	player2_pos = 8;

	int p1_score = 0;
	int p2_score = 0;

	int rolled_times1 = 0;
	int rolled_times2 = 0;

	int turn = 1;

	int dice = 1;

	while (p1_score < 1000 && p2_score < 1000) {

		int sum = 0;
		for (int i = 1; i <= 3; i++) {
			if (dice > 100) {
				dice = 1;
			}
			sum += dice;
			dice++;
		}

		if(turn%2==1){

			for (int i = 1; i <= sum; i++) {
				player1_pos++;
				if (player1_pos > 10) {
					player1_pos = 1;
				}
			}

			p1_score += player1_pos;
			rolled_times1+=3;

		}
		else {

			for (int i = 1; i <= sum; i++) {
				player2_pos++;
				if (player2_pos > 10) {
					player2_pos = 1;
				}
			}

			p2_score += player2_pos;
			rolled_times2+=3;

		}
		turn++;
	}

	cout << min(p1_score, p2_score) * (rolled_times1 + rolled_times2);


	return 0;
}
