#include <iostream>

using namespace std;

int main() {
	int N;
	int count = 0;
	cin >> N;
	int height[10] = { 0 };
	int line[10] = { 0 };

	for (int i = 0; i < N; i++) {
		cin >> height[i];
	}
/*
	for (int i = 0; i < N; i++) {
		if (height[i] > 0) {
			for (int j = 0; j <= i; j++) {
				if (line[j] != 0)
					count++;
			}
			line[count + height[i]] = i + 1;
			count = 0;
		}
		else {
			for (int j = 0; j <= height[i]; j++) {
				if (line[j] != 0)
					count++;
			}
			if (line[0] == 0) {
				line[0] = i + 1;
				count = 0;
			}
			else
			{
				line[0 + count] = i + 1;
				count = 0;
			}
		}
	}*/

	for (int i = 0; i < N; i++) {
		count = height[i];
		for (int j = 0; j < N; j++) {
			if (count == 0 && line[j] == 0) {
				line[j] = i + 1;
				break;
			}
			else if (count != 0 && line[j] == 0) {
				count--;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		cout << line[i] << " ";
	}

	return 0;
}