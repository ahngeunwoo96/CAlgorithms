#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main()
{
	int N, M, *map;
	scanf("%d %d", &N, &M);
	map = (int*)malloc(sizeof(int*N*M);

	for(int i=0; i<N; i++)
		for (int j = 0; j < M; j++)
		{
			scanf("%d", &map[i*M + j]);
			if (map[i*M + j] == 2); // virus
				
		}

	/*for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			printf("%d ", map[i*M + j]);
		}
		printf("\n");
	}*/

	_getch();
	return 0;
}