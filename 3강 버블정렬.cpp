#include <stdio.h>
#include <conio.h>

// 버블 정렬 알고리즘
// 바로 옆과 비교하여 작은 값을 앞으로 보내는 것
// 가장 비효율적인 방법이나 구현하기 쉬움

int main() {
	int i, j, temp;
	int array[10] = { 1, 10, 5, 8, 7, 6, 4, 3, 2, 9 };

	for (i = 0; i < 10; i++) {
		for (j = 0; j < 9-i; j++) { // 9 - i 까지인거 주의하기!!!
			if (array[j] > array[j + 1]) {
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}
	for (i = 0; i < 10; i++) {
		printf("%d", array[i]);
	}
	
	_getch();
	return 0;
}