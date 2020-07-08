#include <iostream> 
#include <algorithm>

using namespace std;

int main() {
	int answer[10];

	for (int test = 0; test < 10; test++) {
		int L, sum = 0;
		cin >> L;
		int height[1004] = { 0 };

		for (int i = 2; i < L + 2; i++) {
			cin >> height[i];
		}

		for (int i = 2; i < L + 2; i++) {
			int max = 0;
			if (height[i] != 0) {
				for (int j = i - 2; j < i + 3; j++) {
					if (max < height[j] && j != i) {
						max = height[j];
					}
				}
				if (height[i] - max > 0)
					sum += (height[i] - max);
			}
		}

		cout << "#" << test << " " << sum << endl;
	}


	return 0;
}