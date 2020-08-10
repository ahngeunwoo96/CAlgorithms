// swea 2115 ¹ú²Ü Ã¤Ãë
#include <iostream>
#include <algorithm>

using namespace std;
int farmer_x[2] = { -1 };
int farmer_y[2] = { -1 };
int honey_max = 0;

int select(int input[][10], int M, int C, int x, int y, int sum, int honey_sum,int n) {
	
	if (x == farmer_x[n] + M )
		return honey_sum;

	for (int i = x; i < farmer_x[n] + M; i++) {

		if (sum + input[y][i] < C) {
			sum += input[y][i];
			honey_sum += input[y][i] * input[y][i];
		}

		select(input, M, C, i + 1, y, sum, honey_sum, n);
		sum -= input[y][i];
		honey_sum -= input[y][i] * input[y][i];
	}

}

int honey_get(int input[][10], int M, int C) {
	int sum = 0;

	sum += select(input, M, C, farmer_x[0], farmer_y[0], 0, 0, 0);
	sum += select(input, M, C, farmer_x[1], farmer_y[1], 0, 0, 1);
	
	return sum;
}


void honey(int N, int M, int C, int x, int y, int input[][10], int n) {

	if (farmer_x[0] != -1 && farmer_x[1] != -1)
		if (honey_max < honey_get(input, M, C)) {
			honey_max = honey_get(input, M, C);
			return;
		}
		else return;

	for (int yy = y; yy < N; yy++) {
		for (int xx = x; xx < N; xx++) {
			if (xx + M >= N)
				continue;
			
			farmer_x[n] = xx;
			farmer_y[n] = yy;

			honey(N, M, C, 0, yy + 1, input, 1);

			farmer_x[n] = -1;
			farmer_y[n] = -1;
		}
	}
}

int main() {
	int T;
	cin >> T;

	for (int test_case = 1; test_case <= T; test_case++) {
		int N, M, C;
		cin >> N >> M >> C;
		int input[10][10];

		for(int i = 0; i < N; i++) 
			for (int j = 0; j < N; j++) {
				cin >> input[i][j];
			}

		honey(N, M, C, 0, 0, input, 0);

		cout << "#" << test_case << " " << honey_max << endl;
	}
	return 0;
}