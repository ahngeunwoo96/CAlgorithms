// sw 1946 ������ ���� Ǯ��

#include <iostream> 

using namespace std;

int main() {
	int T;
	cin >> T;


	for (int test = 0; test < T; test++) {
		int N, *cnt;
		char *alpha;
		cin >> N;
		cnt = (int*)malloc(sizeof(int) * N);
		alpha = (char*)malloc(sizeof(char) * N);
		
		for (int i = 0; i < N; i++) {
			cin >> alpha[i] >> cnt[i];
		}

		cout << "#" << test + 1 << endl;

		int line = 0;
		for (int i = 0; i < N; i++) {
			while (cnt[i] != 0) {
				cout << alpha[i];
				cnt[i]--;
				line++;
				if (line == 10) {
					cout << endl;
					line = 0;
				}
			}
		}
		cout << endl;

	}

	return 0;
}