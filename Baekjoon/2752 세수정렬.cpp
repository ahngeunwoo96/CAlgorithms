
#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
	int data[3], min, temp, index;
	
	for (int i = 0; i < 3; i++) {
		cin >> data[i];
	}

	for (int i = 0; i < 3; i++) {
		min = 1000001;
		for (int j = i; j < 3; j++) {
			if(min > data[j]){
				min = data[j];
				index = j;
			}
		}
		temp = data[i];
		data[i] = min;
		data[index] = temp;
	}

	for (int i = 0; i < 3; i++) {
		cout << data[i] << " ";
	}
	return 0;
}