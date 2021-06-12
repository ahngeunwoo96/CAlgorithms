// swea 1209 Sum

#include <iostream>
#include <limits.h>

using namespace std;

int main() {

	int input[100][100];
	
	for (int tc = 1; tc <= 10; tc++) {
		cin >> tc;
		int ans = 0;
p
		for(int y = 0; y < 100; y++) 
			for (int x = 0; x < 100; x++) {
				cin >> input[y][x];
			}

		int sum = 0;
		for (int y = 0; y < 100; y++) {
			sum = 0;
			for (int x = 0; x < 100; x++) {
				sum += input[y][x];
			}
			
			if (ans < sum)
				ans = sum;
		}
		for (int x = 0; x < 100; x++) {
			sum = 0;
			for (int y = 0; y < 100; y++) {
				sum += input[y][x];
			}

			if (ans < sum)
				ans = sum;
		}
		sum = 0;
		for (int x = 0; x < 100; x++) {
			sum += input[x][x];
		}

		if (ans < sum) ans = sum;

		sum = 0;
		for (int x = 0; x < 100; x++) {
			sum += input[x][99 - x];
		}
		
		if (ans < sum) ans = sum;

		cout << "#" << tc << " " << ans << endl;
	}

	
	return 0;
}