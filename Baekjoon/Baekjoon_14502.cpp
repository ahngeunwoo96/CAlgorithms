// baekjoon 14502 연구소 문제
// dfs, bfs

#include <iostream>
#include <algorithm>

using namespace std;

int N, M, input[8][8], maxCnt;
int test[8][8], afterspreadmap[8][8];

void copymap(int input[][8], int test[][8]) {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			test[i][j] = input[i][j];
}

void virus(int j, int i) {

	if (afterspreadmap[i][j + 1] == 0 && j + 1 < M) {
		afterspreadmap[i][j + 1] = 2;
		virus(j + 1, i);
	}
	
	if (afterspreadmap[i][j - 1] == 0 && j - 1 >= 0) {
		afterspreadmap[i][j - 1] = 2;
		virus(j - 1, i);
	}

	if (afterspreadmap[i + 1][j] == 0 && i + 1 < N) {
		afterspreadmap[i + 1][j] = 2;
		virus(j, i + 1);
	}

	if (afterspreadmap[i - 1][j] == 0 && i - 1 >= 0) {
		afterspreadmap[i - 1][j] = 2;
		virus(j, i - 1);
	}
}

void wall(int x, int y, int cnt) {

	int ans = 0;

	if (cnt == 3) {
		copymap(test, afterspreadmap);
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				if (test[i][j] == 2) {
					virus(j, i);
				}

		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++) {
				if (afterspreadmap[i][j] == 0)
					ans += 1;
			}

		if (maxCnt < ans) {
			maxCnt = ans;
		}
		return;
	}

	int xx;
	for (int yy = y; yy < N; yy++, x = -1) 
		for (xx = x + 1; xx < M; xx++)
			if (test[yy][xx] == 0) {
				test[yy][xx] = 1;
				wall(xx, yy, cnt + 1);
				test[yy][xx] = 0;
			}
	

}

int main() {
	cin >> N >> M;
	maxCnt = 0;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			cin >> input[i][j];
		}


	for(int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			if (input[i][j] == 0) {
				copymap(input, test);
				test[i][j] = 1;
				wall(j, i, 1);
				test[i][j] = 0;
			}
		}

	cout << maxCnt;

	return 0;
}