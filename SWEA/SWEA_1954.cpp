// sw 1954 달팽이 숫자

#include <iostream>

using namespace std;

int main() {
	int T;
	cin >> T;

	for (int test_case = 1; test_case <= T; test_case++) {
		int N;
		cin >> N;
		int map[11][11] = { 0, };
		int cnt = 1, row = 0, col = -1;
		int dir = 1;
		int n = N;

		while (n > 0) {
			for (int i = 0; i < n; i++) {
				col += dir;
				map[row][col] = cnt;
				cnt++;
			}
			n--;
			for (int i = 0; i < n; i++) {
				row += dir;
				map[row][col] = cnt;
				cnt++;
			}
			
			dir *= -1;
		}

		cout << "#" << test_case << endl;
		
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cout << map[i][j] << " ";
			}
			cout << endl;
		}

		
	}
	return 0;
}