// 20.12.15 SWEA 2819 격자판의 숫자 이어 붙이기

#include <iostream>
#include <vector>

using namespace std;

int map[4][4];
int answer = 0;
int move_x[4] = {-1, 0, 1, 0};
int move_y[4] = {0, -1, 0 ,1};
char answerList[10000000];


void moveMap_DFS(int i, int j, int num, int cnt) {
    if(cnt == 7) {
        if(answerList[num] == 0) {
            answerList[num] = 1;
        }
        return;
    }

    for(int a = 0; a < 4; a++) {
        if(i + move_y[a] >= 0 && i + move_y[a] < 4 && j + move_x[a] >= 0 && j + move_x[a] < 4) {
            num = 10 * num + map[i][j];
            moveMap_DFS(i + move_y[a], j + move_x[a], num, cnt + 1);
            num = num / 10;
        }
    }
    

}

int main() {

    int T;
    cin >> T;

    for(int test_case = 1; test_case <= T; test_case++) {
        answer = 0;

        for(int i = 0; i < 4; i++) {
            for(int j = 0; j < 4; j++) {
                cin >> map[i][j];
            }
        }

        for(int i = 0; i < 10000000; i++) {
            answerList[i] = 0;
        }

        for(int i = 0; i < 4; i++) {
            for(int j = 0; j < 4; j++) {
                moveMap_DFS(i, j, 0, 0);
            }
        }

        for(int i = 0; i < 10000000; i++) {
            if(answerList[i] == 1)
                answer++;
        }
        

        cout << "#" << test_case << " " << answer << endl;

    }

    return 0;
}