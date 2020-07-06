#include <stdio.h>
#include <conio.h>

// 삽입 정렬
// 각 숫자를 적절한 위치에 삽입하는 방법
// O(N^2)에서는 가장 빠른 정렬 --> 이미 정렬되있을 경우 속도가 굉장히 빨라짐

int main() {
	int i, j, temp;
	int array[10] = { 1, 10, 5, 8, 7, 6, 4, 3, 2, 9 };
	for (i = 0; i < 9; i++) {
		j = i;
		while (j >= 0 && array[j] > array[j + 1]) {
			temp = array[j];
			array[j] = array[j + 1];
			array[j + 1] = temp;
			j--;
		}
	}

	for (j = 0; j < 10; j++) {
		printf("%d ", array[j]);
	}
	_getch();
	return 0;
}