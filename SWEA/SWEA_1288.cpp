// sw 1288 새로운 불면증 치료법

#include <iostream> 

using namespace std;

int main() {
	int T;
	cin >> T;

	for (int test_case = 1; test_case <= T; test_case++) {
		int N;
		cin >> N;
		int number[10];
		int i = 1;

		while (number[0] != 0 && number[1] != 0 && number[2] != 0 && number[3] != 0 && number[4] != 0 && number[5] != 0 &&
			number[6] != 0 && number[7] != 0 && number[8] != 0 && number[9] != 0) {

			int kN = i * N;

			while (kN >= 10) {
				number[kN % 10] = 1;
				kN = kN / 10;
			}

			number[kN] = 1;
			i += 1;

		}

		cout << "#" << test_case << " " << i;
	}
	return 0;
}