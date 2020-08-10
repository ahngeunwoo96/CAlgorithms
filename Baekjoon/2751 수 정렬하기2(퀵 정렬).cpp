#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>

using namespace std;
//
//void quickSort(int *data, int start, int end) {
//	if (start >= end) {
//		return;
//	}
//
//	int i = start + 1;
//	int j = end;
//	int temp;
//
//	while (i <= j) {
//		while (data[i] <= data[start]) {
//			i++;
//		}
//		while (data[j] >= data[start] && j > start) {
//			j--;
//		}
//		
//		if (i < j) {
//			temp = data[j];
//			data[j] = data[i];
//			data[i] = temp;
//		}
//		else {
//			temp = data[j];
//			data[j] = data[start];
//			data[start] = temp;
//		}
//
//		quickSort(data, start, j - 1);
//		quickSort(data, j + 1, end);
//
//	}
//}
//
//int main() {
//	int n;
//	cin >> n;
//	int *data = (int*)malloc(sizeof(int)*n);
//
//	for (int i = 0; i < n; i++) {
//		cin >> data[i];
//	}
//
//	quickSort(data, 0, n-1);
//
//	for (int i = 0; i < n; i++) {
//		cout << data[i] << "\n";
//	}
//
//	free(data);
//	return 0;
//}

int number;

int main() {
	int *data;
	cin >> number;
	data = (int*)malloc(sizeof(int) * number);

	for (int i = 0; i < number; i++) {
		cin >> data[i];
	}

	sort(data, data + number);
	for (int i = 0; i < number; i++) {
		cout << data[i] << "\n";
	}

	return 0;
}