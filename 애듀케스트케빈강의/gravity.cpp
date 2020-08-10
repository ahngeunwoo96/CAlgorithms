#include <iostream>

using namespace std;

int main() {

	int testcase;
	cin >> testcase;
	
	for (int i = 0; i < testcase; i++) {
		int N;
		int *price;

		cin >> N;
		price = (int *)malloc(N * sizeof(int));

		for (int j = 0; j < N; j++) {
			cin >> price[i];
		}

		for (int j = N - 1; j >= 0; j--) {
			if (price[j] > price[j - 1]) {
				sum += price[j] - price[j - 1];
			}

		}
	}


	return 0;
}