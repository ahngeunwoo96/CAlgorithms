#include <iostream>
#include <stdlib.h>
#include <algorithm>

using namespace std;

bool compare(int a, int b) {
	return a > b;
}
int main(void) {
	int number, max = 0;
	cin >> number;
	int *weight = (int *)malloc(sizeof(int) * number);

	for (int i = 0; i < number; i++) {
		cin >> weight[i];
	}

	for (int i = 0; i < number; i++) {
		if (max < weight[i] * (number - i))
			max = weight[i] * (number - i);
	}

	cout << max << endl;
	
	free(weight);
	return 0;
}