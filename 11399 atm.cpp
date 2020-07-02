#include <stdio.h>
#include <stdlib.h>
#define MAX 50000000

int main()
{
	int n, min;
	int i, j, k, sum = 0, *p, data;
	scanf("%d", &n);
	p = (int*)malloc(sizeof(int)*n);

	for (i = 0; i < n; i++)
	{
		scanf("%d", &p[i]);
	}

	for (i = 0; i < n; i++)
	{
		min = MAX;
		for (j = i; j < n; j++)
		{
			if (min >= p[j])
			{
				min = p[j];
				k = j;
			}
		}
		sum += min * (n - i);
		data = p[k];
		p[k] = p[i];
		p[i] = data;
	}

	printf("%d", sum);
	return 0;

}