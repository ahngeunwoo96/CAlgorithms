#include <iostream> 
#include <algorithm>
#include <stdio.h>

using namespace std;

int main() {
	int t;
	cin >> t;
	int *success = (int*)malloc(sizeof(int) * t);
	

	for (int i = 0; i < t; i++) {
		int number[10] = { 0 };
		int input_number;

		for (int j = 0; j < 6; j++) {
			scanf("%1d", &input_number);
			number[input_number] += 1;
		}

		for (int j = 0; j < 10; j++) {
			if (number[j] > 0) {
				if (number[j] >= 3) {
					number[j] -= 3;
					j--;
				}

				if (number[j + 1] > 0) {
					if (number[j + 2] > 0) {
						number[j] -= 1;
						number[j + 1] -= 1;
						number[j + 2] -= 1;
						j--;
					}
				}
			}
		}
		int sum = 0;

		for (int j = 0; j < 10; j++) {
			sum += number[j];
		}

		if (sum == 0) success[i] = 1;
		else success[i] = 0;

	}
	
	for (int i = 0; i < t; i++) {
		if (success[i] == 0) cout << "Lose" << endl;
		else if (success[i] == 1) cout << "Baby Gin" << endl;
	}
	

	return 0;
}