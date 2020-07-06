#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int N;
	cin >> N;
	int weight[1000];
	int possible = 0;

	for (int i = 0; i < N; i++) {
		cin >> weight[i];
	}

	sort(weight, weight + N);

	int sum = 0;
	for (int i = 0; i < N; i++) {
		if (sum + 2 <= weight[i]) break;
		sum += weight[i];
	}

	cout << sum + 1 << endl;

	

	return 0;
}