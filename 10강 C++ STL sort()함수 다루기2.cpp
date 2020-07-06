#include <iostream> // c++ header
#include <algorithm>
#include <vector>
#include <string>

using namespace std;


// pair를 다중으로 사용해보기 pair안에 pair가 또 있음


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
	v.push_back(pair<string, pair<int, int>>("나 동 빈", pair<int, int>(90, 19961222)));
	v.push_back(pair<string, pair<int, int>>("이 태 일", pair<int, int>(97, 19961222)));
	v.push_back(pair<string, pair<int, int>>("안 건 우", pair<int, int>(95, 19961222)));
	v.push_back(pair<string, pair<int, int>>("양 윤 정", pair<int, int>(95, 19971222)));
	v.push_back(pair<string, pair<int, int>>("반 정 우", pair<int, int>(93, 19921222)));

	sort(v.begin(), v.end(), compare);

	for (int i = 0; i < v.size(); i++) {
		cout << v[i].first << " ";
	}
	return 0;
}