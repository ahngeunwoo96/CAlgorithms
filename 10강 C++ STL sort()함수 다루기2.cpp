#include <iostream> // c++ header
#include <algorithm>
#include <vector>
#include <string>

using namespace std;


// pair�� �������� ����غ��� pair�ȿ� pair�� �� ����


bool compare(pair<string, pair<int, int>> a,
	pair<string, pair<int, int>> b) {
	if (a.second.first == b.second.first) {
		return a.second.second > b.second.second;
	}	else {
		return a.second.first > b.second.first;
	}
}

int main() {
	vector <pair<string, pair<int, int>>> v;
	v.push_back(pair<string, pair<int, int>>("�� �� ��", pair<int, int>(90, 19961222)));
	v.push_back(pair<string, pair<int, int>>("�� �� ��", pair<int, int>(97, 19961222)));
	v.push_back(pair<string, pair<int, int>>("�� �� ��", pair<int, int>(95, 19961222)));
	v.push_back(pair<string, pair<int, int>>("�� �� ��", pair<int, int>(95, 19971222)));
	v.push_back(pair<string, pair<int, int>>("�� �� ��", pair<int, int>(93, 19921222)));

	sort(v.begin(), v.end(), compare);

	for (int i = 0; i < v.size(); i++) {
		cout << v[i].first << " ";
	}
	return 0;
}