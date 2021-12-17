#pragma warning(disable: 4996)

#include <fstream>
#include <iostream>
#include <vector>
#include <cstring>
#include <utility>
using namespace std;

ifstream f("input.in");

int x1_target, x2_target, y1_target, y2_target;

int generateRoute(int x_vel, int y_vel) {

	int high = -1;

	int x_pos = 0;
	int y_pos = 0;

	while (true) {

		x_pos += x_vel;
		y_pos += y_vel;

		//check if projectile in inside target
		if (x1_target <= x_pos && x_pos <= x2_target && y1_target >= y_pos && y_pos >= y2_target) {
			return high;
		}

		//check if projectile left
		if (y_pos < y2_target) {
			return -1;
		}
		
		if (y_pos > high) {
			high = y_pos;
		}

		if (x_vel > 0) {
			x_vel--;
		}

		y_vel--;

	}

}

int main() {

	/*
		x1_target = where target begin on OX
		x2_target = where target end on ON
		y1_target = where target begin on OY
		y2_target = where target end on OY
	*/

	x1_target = 241;
	x2_target = 273;
	y1_target = -63;
	y2_target = -97;

	int high = -1, val;

	for (int i = 1; i <= 500; i++) {
		for (int j = 1; j <= 500; j++) {

			val = generateRoute(i, j);

			if (val > high) {
				high = val;
			}

		}
	}

	cout << high;
	
	return 0;
}
