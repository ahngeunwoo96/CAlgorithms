// baekjoon 14503 로봇 청소기

#include <iostream>

using namespace std;

#define North 0
#define East 1
#define South 2
#define West 3

int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};

int n, m, map[50][50], cnt = 0, ans, off = 0;

void vaccum(int r,int c, int d) {
	if (off == 0) {
		int alr = 0;
		if (map[c][r] == 0)
		{
			map[c][r] = 2;
			cnt++;
		}

		int d_cnt = 0;

		for (int x = (d + 3) % 4; d_cnt < 4; d_cnt++, x--) {
			if (x == -1)
				x = 3;

			int new_c = c + dy[x];
			int new_r = r + dx[x];

			if (map[new_c][new_r] == 0) {
				vaccum(new_r, new_c, x);
				alr = 1;
			}
		}

		if (alr == 0) {// 네 방향이 모두 청소되있는 경우 
			int new_c = c + dy[(d + 2) % 4];
			int new_r = r + dx[(d + 2) % 4];

			if (map[new_c][new_r] == 0 || map[new_c][new_r] == 2) { // 뒤로 이동
				vaccum(new_r, new_c, d);
			}
			else 
				off = 1;
		}
	}
}

int main() {
	cin >> n >> m;
	int r, c, d;
	cin >> r >> c >> d;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> map[i][j];

	vaccum(c, r, d);

	cout << cnt << endl;

	return 0;
}