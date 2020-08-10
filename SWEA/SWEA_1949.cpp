// swea 1949 등산로 조성

#include <iostream>
#include <algorithm>

using namespace std;

int input[8][8];

void dfs(int x, int y, int cnt, int flag) {
	input[x][y] = true;

}

int main() {
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		int N, K;
		cin >> N >> K;
		int maxCnt = 0;

		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++) {
				cin >> input[i][j];
				maxCnt = max(input[i][j], maxCnt);
			}

		for(int i = 0; i < N; i++)
			for(int j = 0; j < N; j++) 
				if (maxCnt == input[i][j]) {
					dfs(j, i, 1, 1);
				}





	}

	return 0;
}