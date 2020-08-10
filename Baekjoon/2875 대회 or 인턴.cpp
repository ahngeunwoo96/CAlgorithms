#include <iostream>

using namespace std;

int main() {
	int n, m, k, cnt, left = 0;
	cin >> n >> m >> k;

	if (n >= 2 * m) {
		cnt = m;
		left = n - (2 * m);
	}
	else {
		cnt = n / 2;
		left = m - (n / 2);
	}
	
	if (k - left + 2 > 0) {
		cnt -= (k - left + 2) / 3;
	}

	cout << cnt << endl;

	return 0;
}