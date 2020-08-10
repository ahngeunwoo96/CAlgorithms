#include <iostream>
#include <string>
#include <algorithm>
#include <stdlib.h>

using namespace std;

int main() {

	int n, m;
	cin >> n >> m;
	int sum = 0;

	int *package = (int*)malloc(sizeof(int) * m);
	int *one = (int*)malloc(sizeof(int) * m);

	for (int i = 0; i < m; i++) {
		cin >> package[i] >> one[i];
	}

	sort(package, package + m);
	sort(one, one + m);

	while (n > 0) {
		if (package[0] < n * one[0] && n <= 6) {
			n = 0;
			sum += package[0];
			continue;
		}
		else if (n >= 6 && package[0] < 6 * one[0]) {
			n = n - 6;
			sum += package[0];
			continue;
		}
		else {
			n = n - 1;
			sum += one[0];
		}
	}
	cout << sum << endl;

	free(package);
	free(one);
	return 0;
}