#include <iostream>

using namespace std;

int main() {
	int N, M, count = 0;
	cin >> N >> M;

	if (N == 1)
		count = 1;
	else if (N == 2) {
		if (M < 3) count = 1;
		else if (M < 5) count = 2;
		else if (M < 7) count = 3;
		else count = 4;
	}
	else { 
		if (M == 1) count = 1;
		else if (M == 2) count = 2;
		else if (M == 3) count = 3;
		else if (M < 7) count = 4;
		else count = M - 2;
	}
		
	cout << count << endl;
	return 0;
}