//#include <iostream>
//#include <stdio.h>
//#include <stdlib.h>
//#include <algorithm>
//
//using namespace std;

// 그리디 알고리즘
// 최적의 상황을 쫓는 알고리즘

// 첫 풀이는 실패!! --> 시간초과 O(n^2)이라서 실패한듯?
//int main()
//{
//	int number, time = 0, howmany = 0, last;
//	scanf("%d", &number);
//	int *start = (int*)malloc(sizeof(int) * number);
//	int *end = (int*)malloc(sizeof(int) * number);
//	int min = 10001, max = 0;
//
//	for (int i = 0; i < number; i++)
//	{
//		scanf("%d %d", &start[i], &end[i]);
//		if (max < end[i]) {
//			max = end[i];
//		}
//	}
//	last = max;
//
//	while (time < last) {
//		min = 10001;
//		for (int i = 0; i < number; i++) {
//			if (start[i] >= time) {
//				if (min >= end[i]) {
//					min = end[i];
//				}
//			}
//		}
//		time = min;
//		howmany++;
//	}
//
//	printf("%d", howmany);
//	free(start);
//	free(end);
//	return 0;
//}



//*******************************************************************************************


// 구글링해서 찾아봄!! 이 문제에서 O(n^2)을 안하기 위해선 정렬이 필요해서 sort함수를 따옴
// 동빈나 10강 C++ STL sort()함수 사용하기 강의를 듣고 
// 코드를 짜봄 다시 한번 복습 필요!! vector와 bool, pair사용해보기

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second) {
		return a.first < b.first;
	} else {
		return a.second < b.second;
	}
}
int main(void) {
	int number;
	cin >> number;
	vector <pair<int, int>> meeting;

	for (int i = 0; i < number; i++) {
		int start;
		int end;
		cin >> start >> end;
		meeting.push_back(pair<int, int>(start, end));
	}

	sort(meeting.begin(), meeting.end(), compare);

	int cnt = 0, now = 0;

	for (int i = 0; i < meeting.size(); i++) {
		if (now <= meeting[i].first) {
			now = meeting[i].second;
			cnt++;
		}
	}

	cout << cnt << endl;
	
	return 0;
}