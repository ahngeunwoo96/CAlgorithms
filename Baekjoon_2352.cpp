#include <iostream> 
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

// �� ����� O(n^2)

//int main() {
//	int n;
//	int maxnum = 0;
//	cin >> n;
//	int *a = (int*)malloc(sizeof(int) * n);
//	int dy[40000];
//
//	for (int i = 0; i < n; i++) {
//		cin >> a[i];
//		dy[i] = 1;
//	}
//
//	int i, j;
//	for (i = 1; i <= n; i++) {
//		for (j = 0; j < i; j++) {
//			if (a[i] > a[j] && dy[i] < dy[j] + 1) {
//				dy[i] = dy[j] + 1;
//			}
//		}
//	}
//	
//	for (int i = 0; i < n; i++) {
//		maxnum = max(maxnum, dy[i]);
//	}
//	cout << dy[n - 1];
//	return 0;
//}

// ����� O(nlogn)���� �����Ϸ���??

int N;
int connect[40001];
int cache[40001];

int portLIS() {
	cache[1] = connect[1];
	int length = 1;
	for (int i = 2; i <= N; i++) {
		if (cache[length] < connect[i]) {
			cache[++length] = connect[i];
			continue;
		}

	// lower_bound �Լ��� cache + 1���� cache + length + 1���� connect[i]���� ���ų� ū ���� ��ġ
		int idx = lower_bound(cache + 1, cache + length + 1, connect[i]) - cache; 
		cache[idx] = connect[i];
	}
	return length;
}

int main() {
	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> connect[i];
	}

	cout << portLIS() << endl;
	return 0;
}