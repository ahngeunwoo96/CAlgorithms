//#include <iostream>
//#include <stdio.h>
//#include <stdlib.h>
//#include <algorithm>
//
//using namespace std;

// �׸��� �˰���
// ������ ��Ȳ�� �Ѵ� �˰���

// ù Ǯ�̴� ����!! --> �ð��ʰ� O(n^2)�̶� �����ѵ�?
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


// ���۸��ؼ� ã�ƺ�!! �� �������� O(n^2)�� ���ϱ� ���ؼ� ������ �ʿ��ؼ� sort�Լ��� ����
// ���� 10�� C++ STL sort()�Լ� ����ϱ� ���Ǹ� ��� 
// �ڵ带 ¥�� �ٽ� �ѹ� ���� �ʿ�!! vector�� bool, pair����غ���

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