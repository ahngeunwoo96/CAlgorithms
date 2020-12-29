// 20.12.29 SWEA 2805 농작물 수확하기 문제풀이

#include <iostream>
#include <stdio.h>

using namespace std;
int map[49][49];
int answer;

int main() {

    int T;
    cin >> T;

    for(int test_case = 1; test_case <= T; test_case++) {
        answer = 0;
        int N;
        cin >> N;

        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                scanf("%1d", &map[i][j]);
            }
        }

        for(int y = 0; y <= N / 2; y++) {
            for(int x = N / 2 - y; x <= N / 2 + y; x++) {
                answer += map[y][x];
            }
        }

        for(int y = N / 2 + 1; y < N; y++) {
            for(int x = y - N / 2; x < N - (y - N / 2); x++) {
                answer += map[y][x];
            }
        }

        cout << "#" << test_case << " " << answer << endl;
    }

    return 0;
}