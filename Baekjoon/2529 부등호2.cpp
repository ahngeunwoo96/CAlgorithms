#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

vector <int> max_value;
vector <int> min_value;

void find_max(string symbol, int n) {
	unsigned int start, end;

	for (int i = 9; i >= 9 - n; i--) {
		max_value.push_back(i);
	}

	for (size_t i = 0; i < symbol.size() + 1; i++) {
		start = i;
		for (size_t j = i; j < symbol.size() + 1; j++) {
			end = j;
			if (symbol[j] == '<') {
			}
			else { // max_value[i] == '>'
				if (start != end) {
					sort(&max_value[start], &max_value[end] + 1, less<int>());
				}
				break;
			}
		}
	}

	for (size_t i = 0; i < symbol.size() + 1; i++) {
		cout << max_value[i];
	}

	cout << endl;
}

void find_min(string symbol) {
	unsigned int start, end;

	for (size_t i = 0; i < symbol.size() + 1;i++) {
		min_value.push_back(i);
	}
	//cout << "symbol.size : " << symbol.size() << endl;

	for (size_t i = 0; i < symbol.size() + 1; i++) {
		start = i;
		for (size_t j = i; j < symbol.size() + 1; j++) {
			end = j;
			if (symbol[j] == '>') {
			}
			else { // max_value[i] == '>'
				if (start != end) {
					sort(&min_value[start], &min_value[end] + 1, greater<int>());
				}
				break;
			}
		}
	}

	for (size_t i = 0; i < symbol.size() + 1; i++) {
		cout << min_value[i];
	}

	cout << endl;
}

int main() {
	int n, min, max;
	cin >> n;
	string symbol;

	for(int i = 0; i < n; i++) {
		char data;
		cin >> data;
		symbol += data;
	}

	//cout << symbol << endl;

	find_max(symbol, n);
	find_min(symbol);

	return 0;
}