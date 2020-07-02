#include <iostream>
#include <string>
#include <stdlib.h>
#include <algorithm>
#include <vector>

using namespace std;

bool reverse(int a, int b) {
	return a < b;
}

int main() {

	int n;
	cin >> n;

	vector <int> min, max;
	string symbol;


	for (int i = 0; i < n + 1; i++) {
		min.push_back(i);
		max.push_back(9 - i);

		if (i < n) {
			char temp;
			cin >> temp;
			symbol += temp;
		}
	}
	unsigned int start_max = INT_MAX, end_max = INT_MAX;
	unsigned int start_min = INT_MAX, end_min = INT_MAX;

	for (unsigned int i = 0; i < symbol.size() + 1; i++) {

		if (symbol[i] == '<') { // '<'인 경우
			start_max = i;
			if (start_min < i && start_min != INT_MAX) {
				end_min = i + 1;
				sort(min.begin() + start_min, min.begin() + end_min);
				start_min = INT_MAX;
				end_min = INT_MAX;
			}
		}
		else { // '>'인 경우
			if (start_max < i && start_max != INT_MAX) {
				end_max = i + 1;
				sort(max.begin() + start_max, max.begin() + end_max);
				start_max = INT_MAX;
				end_max = INT_MAX;
			}
			start_min = i;
		}

		if (i == symbol.size() + 1) {
			if (start_min != INT_MAX) {
				end_min = i;
				sort(min.begin() + start_min, min.begin() + end_min);
			}

			if (start_max != INT_MAX) {
				end_max = i;
				sort(max.begin() + start_max, max.begin() + end_max);
			}
		}

	}
	

	for (unsigned int i = 0; i < min.size(); i++) {
		cout << min[i];
	}
	cout << endl;
	
	for (unsigned int i = 0; i < max.size(); i++) {
		cout << max[i];
	}
	cout << endl;
	return 0;
}