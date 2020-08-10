#include <iostream>

using namespace std;

int main() {
	int testcase, end_x, end_y, move_x, move_y;
	cin >> testcase;
	int radder[12][12];

	for (int a = 0; a < testcase; a++) {
		int testcasenumber;
		cin >> testcasenumber;

		for (int i = 1; i < 11; i++) {
			for (int j = 1; j < 11; j++) {
				cin >> radder[i][j];
			}
		}

		for(int i = 0; i < 11; i++){
			if (radder[10][i] == 2)
				end_x = i;
		}

		end_y = 10;
		move_y = end_y;
		move_x = end_x;

		while (move_y != 1) {
			if (radder[move_y][move_x - 1] == 1) {
				while (radder[move_y][move_x - 1] != 0)
					move_x -= 1;
				move_y -= 1;
			}
			else if (radder[move_y][move_x + 1] == 1) {
				while (radder[move_y][move_x + 1] != 0) {
					move_x += 1;
				}
				move_y -= 1;
			}
			else
				move_y -= 1;
			
		}

		cout << move_x - 1 << endl;

	
	}

	return 0;
}