// baekjoon 15684 사다리 조작

#include <iostream>

using namespace std;

int mincnt = 4;

int possible(int Connect[][10], int H, int N) {
	int a;

	for (int i = 1; i <= H; i++) {
		a = i;
		for (int j = 1; j <= N; j++) {
			if (Connect[j][a - 1])
				a--;
			else if (Connect[j][a])
				a++;
		}

		if (a != i)
			return false;
	}
	return true;
}

void Ladder_game(int cnt, int Connect[][10], int H, int N) {
	
	if (cnt == 3) // 종료
		return;

	if (cnt >= mincnt)
		return;

	if (possible(Connect, H,N)) {
		mincnt = cnt;
		return;
	}

	for (int i = 1; i < H; i++) {
		for (int j = 1; j <= N; j++) {
			if (Connect[i][j] == 1) {
				j++;
				continue;
			}

			Connect[i][j] = 1;
			Ladder_game(cnt + 1, Connect, H, N);
			Connect[i][j] = 0;
		}
	}

}

int main() {

	int N, M, H;
	cin >> N >> M >> H;
	int Connect[30][10] = { 0 };

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		Connect[a][b] = 1;
	}

	Ladder_game(0, Connect, H, N);

	if (mincnt > 3)
		mincnt = -1;

	cout << mincnt << endl;

	 
	return 0;
}