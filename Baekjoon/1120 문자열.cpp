#include <iostream>
#include <string>

using namespace std;

int main(void) {
	string a, b;
	cin >> a >> b;
	int sum = 0;
	int min = 100;
	
	if (a.size() < b.size()) {
		for (int j = 1; j <= b.size() - a.size(); j++) {
			for (int k = 0; k < a.size(); k++) {
				if (b[k + j] != a[k]) {
					sum += 1;
				}
			} 
			if (min > sum) {
				min = sum;
			}
			sum = 0;
		}
	}

	for (int i = 0; i < a.size(); i++) {
		if (b[i] != a[i]) {
			sum += 1;
		}
	}

	if (min < sum) {
		sum = min;
	}


	cout << sum << endl;
	return 0;
}