// sw 1945 간단한 소인수분해

#include <iostream> 

using namespace std;

int main() {
	int test_case;
	cin >> test_case;

	for (int i = 1; i <= test_case; i++) {
		int number;
		cin >> number;
		int ans[5] = { 0 };

		while (number % 2 == 0) {
			ans[0] += 1;
			number /= 2;
		}
		
		while (number % 3 == 0) {
			ans[1] += 1;
			number /= 3;
		}

		while (number % 5 == 0) {
			ans[2] += 1;
			number /= 5;
		}

		while (number % 7 == 0) {
			ans[3] += 1;
			number /= 7;
		}

		while (number % 11 == 0) {
			ans[4] += 1;
			number /= 11;
		}

		cout << "#" << i;
		for (int j = 0; j < 5; j++) {
			cout << " " << ans[j];
		}
		cout << endl;
	}

	return 0;
}