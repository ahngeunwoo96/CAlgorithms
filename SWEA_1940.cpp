// sw 1940 가랏! RC카!

#include <iostream> 

using namespace std;

int main() {
	int T;
	cin >> T;

	for (int test_case = 1; test_case <= T; test_case++) {
		int N, mode, v = 0, d = 0;
		cin >> N;

		for (int i = 0; i < N; i++) {
			cin >> mode;
			int a;
			switch (mode) {
			case 1: // 가속
				cin >> a;
				v += a;
				d += v;
				break;
			case 2: // 감속 
				cin >> a;
				if (v < a) {
					v = 0;
				}
				else {
					v -= a;
					d += v;
				}
				break;
			case 0:
				d += v;
				break;
			}

		}

		cout << "#" << test_case << " " << d << endl;

	}

	return 0;
}