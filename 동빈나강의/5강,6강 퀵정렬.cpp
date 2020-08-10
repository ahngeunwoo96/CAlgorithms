//#include <stdio.h>
//#include <conio.h>
//
//// 퀵 정렬
//// O(N * logN) --> 빠른 알고리즘
//// 하나의 수(피벗)를 기준으로 두가지로 분류(분할 정렬)
//// 재귀함수 사용
//
//int number = 10;
//int data[10] = { 1, 10, 5, 8, 7, 6, 4, 3, 2, 9 };
//
//void quickSort(int *data, int start, int end) {
//	if (start >= end) {
//		return;
//	}
//
//	int key = start;
//	int i = start + 1; // 왼쪽 출발 지점
//	int j = end; // 오른쪽 출발 지점
//	int temp;
//
//	while (i <= j) { // 엇갈릴 때까지 반복
//		while (data[i] <= data[key]) {
//			i++;
//		}
//		while (data[j] >= data[key] && j >start) {
//			j--;
//		}
//		if (i > j) { // 엇갈린 경우
//			temp = data[j];
//			data[j] = data[key];
//			data[key] = temp;
//		}
//		else { // 엇갈리지 않은 경우
//			temp = data[j];
//			data[j] = data[i];
//			data[i] = temp;
//		}
//
//		quickSort(data, start, j - 1);
//		quickSort(data, j + 1, end);
//	}
//
//}
//
//int main()
//{
//	quickSort(data, 0, number - 1);
//	for (int i = 0; i < number; i++) {
//		printf("%d ", data[i]);
//	}
//	_getch();
//	return 0;
//
//}


///////////////////내가 직접 해보기//////////////////
#include <stdio.h>
#include <conio.h>

int number = 10;
int array[10] = { 3, 5, 6, 4, 1, 10, 7, 8, 9, 2 };

void quickSort(int *array, int start, int end) {
	if (start >= end) {
		return;
	}
	
	int i = start + 1;
	int j = end;
	int temp;
	int key = start;

	while (i <= j) {
		while (array[i] <= array[key]) {
			i++;
		}
		while (array[j] >= array[key]) {
			j--;
		}

		if (i > j) { // 엇갈릴 때
			temp = array[j];
			array[j] = array[key];
			array[key] = temp;
		}
		else {
			temp = array[j];
			array[j] = array[i];
			array[i] = temp;
		}

		quickSort(array, start, j - 1);
		quickSort(array, j + 1, end);
	}
}

int main()
{
	quickSort(array, 0, number - 1);
	for (int i = 0; i < number; i++) {
		printf("%d ", array[i]);
	}
	_getch();
	return 0;
}