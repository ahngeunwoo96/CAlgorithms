#include <stdio.h>
#include <conio.h>

// ���� ����
// �� ���ڸ� ������ ��ġ�� �����ϴ� ���
// O(N^2)������ ���� ���� ���� --> �̹� ���ĵ����� ��� �ӵ��� ������ ������

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