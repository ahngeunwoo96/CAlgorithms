// 20.12.28 SWEA 1249 보급로 문제풀이

#include <iostream>
#include <limits.h>
#include <stdio.h>

using namespace std;

int map[100][100], sumMap[100][100];
int N, answer;

void findBestWay(int sum, int i, int j) {

    if(i == N - 1 && j == N - 1) {
        if(answer > sum) {
            answer = sum;
        }
        return;
    }
    
    if(sum >= answer) {
        return;
    }

    if(sum < sumMap[i][j]) {
        sumMap[i][j] = sum;
    }

    if(sum > sumMap[i][j])
        return;
    
    if(j + 1 < N)
        findBestWay(sum + map[i][j + 1], i, j + 1);
    if(i + 1 < N)
        findBestWay(sum + map[i + 1][j], i + 1, j);
}

int main() {

    int T;
    cin >> T;

    for(int test_case = 1; test_case <= T; test_case++) {
        answer = INT_MAX;
        cin >> N;

        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                map[i][j] = 0;
                sumMap[i][j] = INT_MAX;
            }
        }

        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                scanf("%1d" , &map[i][j]);
            }
        }

        findBestWay(0, 0, 0);

        cout << "#" << test_case << " " << answer << endl;

    }

    return 0;
}