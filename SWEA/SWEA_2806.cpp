// 20.12.27 SWEA 2806 N-Queen 문제풀이

#include <iostream>
#include <stdlib.h>

using namespace std;

int board[10];
int row_bool[10];
int answer;

void Queen(int N, int i) {
    if(i == N) { // 종료조건
        // 같은 대각선에 퀸이 놓아져있는 경우
        for(int j = 0; j < N; j++) {
            for(int k = j + 1; k < N; k++) {
                if((k - j) == abs(board[k] - board[j]))
                    return;
            }
        }

        answer++;
        return;
    }

    for(int j = 0; j < N; j++) {
        if(row_bool[j] == 0) {
            board[i] = j;
            row_bool[j] = 1;
            Queen(N, i + 1);
            board[i] = 0;
            row_bool[j] = 0;
        }
        
    }

    
}

int main () {

    int T;
    cin >> T;

    for(int testCase = 1; testCase <= T; testCase++) {
        answer = 0;
        int N;
        cin >> N;

        for(int i = 0; i < 10; i++) {
            board[i] = 0;
            row_bool[i] = 0;
        }

        for(int i = 0; i < N; i++) {
            board[0] = i;
            row_bool[i] = 1;
            Queen(N, 1);
            board[0] = 0;
            row_bool[i] = 0;

        }

        cout << "#" << testCase << " " <<  answer << endl;

    }


    return 0;
}