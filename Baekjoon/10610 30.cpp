#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool compare(int a, int b) {
	return a > b;
}

int main(void) {
	string n;
	cin >> n;
	int sum = 0;

	sort(n.begin(), n.end(), compare);

	if (n[n.size() - 1] != '0' ){
		cout << "-1";
	}
	else {
		for (int i = 0; i < n.size(); i++) {
			sum += n[i];
		}
		if (sum % 3 != 0) {
			cout << "-1";
		}
		else {
			for (int i = 0; i < n.size(); i++) {
				cout << n[i];
			}
		}
	}
	

	return 0;
}