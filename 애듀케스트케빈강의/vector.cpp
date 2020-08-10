#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool resort(int a, int b) {
	return a > b;
}

int main() {
	vector <int> v;

	v.push_back(1);
	v.push_back(2);
	v.push_back(3);

	sort(v.begin(), v.end(), resort);
	
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << endl;
	}
	return 0;

}