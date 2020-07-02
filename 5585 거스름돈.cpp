#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main()
{
	int price, exchange,num = 0;
	scanf("%d", &price);
	exchange = 1000 - price;
	while (exchange / 500 >= 1)
	{
		num++;
		exchange -= 500;
	}
	while (exchange / 100 >= 1)
	{
		num++;
		exchange -= 100;
	}
	while (exchange / 50 >= 1)
	{
		num++;
		exchange -= 50;
	}
	while (exchange / 10 >= 1)
	{
		num++;
		exchange -= 10;
	}
	while (exchange / 5 >= 1)
	{
		num++;
		exchange -= 5;
	}
	while (exchange / 1 >= 1)
	{
		num++;
		exchange -= 1;
	}
	printf("%d", num);
	return 0;
}