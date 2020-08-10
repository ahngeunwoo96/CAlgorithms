#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;


int main()
{
	int n, min, index, temp;
	cin >> n;
	int *data = (int *)malloc(sizeof(int)*n);

	for (int i = 0; i < n; i++) {
		cin >> data[i];
	}

	for (int i = 0; i < n; i++) {
		min = 10001;
		for (int j = i; j < n; j++) {
			if (min > data[j]) {
				min = data[j];
				index = j;
			}
		}
		temp = data[index];
		data[index] = data[i];
		data[i] = temp;
	}

	for (int i = 0; i < n; i++) {
		cout << data[i] << "\n";
	}

	free(data);
	return 0;
}