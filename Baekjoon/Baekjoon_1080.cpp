#include <iostream> 
#include <stdio.h>

using namespace std;

int main() {
	int N, M, num = 0;
	int *A, *B, *C;
	cin >> N >> M;
	A = (int*)malloc(sizeof(int) * N * M);
	B = (int*)malloc(sizeof(int) * N * M);
	C = (int*)malloc(sizeof(int) * N * M);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%1d", &A[i * M+ j]);
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%1d", &B[i * M + j]);
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			C[i * M + j] = abs(B[i * M + j] - A[i * M + j]);
		}
	} 

	for (int i = 0; i < N - 2; i++) {
		for (int j = 0; j < M - 2; j++) {
			if (C[i * M + j] == 1) {
				num++;
				for (int a = i; a < i + 3; a++) {
					for (int b = j; b < j + 3; b++) {
						if (C[a * M + b] == 1) C[a * M + b] = 0;
						else if (C[a * M + b] == 0) C[a * M + b] = 1;
					}
				}
			}
		}
	}
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (C[i * M + j] == 1) {
				num = -1;
			}
		}
	}

	cout << num << endl;

	
	return 0;
}