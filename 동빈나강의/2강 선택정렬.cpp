#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

using namespace std;


// �������� �˰��� 
// ���� ���� ���� �����ؼ� ������ ������ ��
// O(N^2) --> ȿ�������� ����

int main()
{
	int i, j, min, index, temp;
	int array[10] = { 1, 10, 5, 8, 7, 6, 4, 3, 2, 9 };
	
	for (i = 0; i < 10; i++)
	{
		min= 99999;
		for (j = i; j < 10; j++) {
			if (min > array[j]) {
				min = array[j];
				index = j; 
			}
		}
		temp = array[i]; 
		array[i] = array[index]; 
		array[index] = temp;
	}

	for (i = 0; i < 10; i++) {
		printf("%d ", array[i]);
	}

	_getch();
	return 0;
}