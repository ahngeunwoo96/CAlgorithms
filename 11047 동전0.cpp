#include <iostream>
#include <stdlib.h>

using namespace std;

int main(void) {
	int number, price, sum = 0;
	cin >> number >> price;
	int *coin;
	coin = (int *)malloc(sizeof(int) * number);

	for (int i = 0; i < number; i++) {
		cin >> coin[i];
	}

	for (int i = number-1; i >= 0; i--) {
		if (price >= coin[i]) {
			sum += price / coin[i];
			price = price % coin[i];
		}
	}

	cout << sum << endl;
	free(coin);
	return 0;
}