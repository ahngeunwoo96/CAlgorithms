#include <iostream> 

using namespace std;

#define EMPTY 0
#define BOX 1

int main() {

	int testcase, roomwidth, roomheight, boxheight;
	int room[100][100];
	int max = 0;

	cin >> testcase;
	cin >> roomwidth >> roomheight;
	for (int a = 0; a < testcase; a++) {
		for (int i = 0; i < roomwidth; i++) {
			for (int j = 0; j < roomheight; j++) {
				room[i][j] = EMPTY;
			}
		}

		int countEmptySpace;

		for (int i = 0; i < roomwidth; i++) {
			cin >> boxheight;
			for (int j = 0; j < boxheight; j++) {
				room[i][j] = BOX;
			}
		}

		for (int i = 0; i < roomwidth; i++) {
			for (int j = 0; j < roomheight; j++) {
				if (room[i][j] == BOX) {
					countEmptySpace = 0;
					for (int k = i + 1; k < roomwidth; k++) {
						if (room[k][j] == EMPTY) {
							countEmptySpace += 1;
						}
						if (countEmptySpace > max) {
							max = countEmptySpace;
						}
					}
				}

			}
		}
	}

	cout << max << endl;
	return 0;
}