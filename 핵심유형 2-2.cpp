// 애듀케스트 케빈 핵심 유형 2-2 
// 100 * 100 배열에서 거꾸로 읽어도 똑같은 문자열의 최대 길이 찾기 

#include <iostream>
#include <algorithm>

using namespace std;

bool isPalindrome(char input[][100], int y, int x, int len) {
	for (int i = 0; i < (len + 1) / 2; i++) {
		if (input[y][x + i] != input[y][x + len - 1 - i])
			return false;
	}
	return true;

}

int find_max_length(char input[][100]) {

	int max = 0;

	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			for (int k = 100 - j; k > max; k--) {
				if (isPalindrome(input, i, j, k))
				{
					if (max < k) max = k;
					break;
				}
			}
		}
	}

	return max;

}

int main() {

	int T;
	cin >> T;

	int max_len = 0;

	for (int test_case = 1; test_case <= T; test_case++) {

		cin >> test_case;

		char input[100][100];
		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++) {
				cin >> input[i][j];
			}
		}

		max_len = find_max_length(input);

		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++) {
				if (i > j) {
					char temp = input[i][j];
					input[i][j] = input[j][i];
					input[j][i] = temp;
				}
			}
		}

		max_len = max(max_len, find_max_length(input));

		cout << "#" << test_case << " " << max_len << endl;

		max_len = 0;
	}
	return 0;
	
}