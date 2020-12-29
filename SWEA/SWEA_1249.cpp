// 20.12.29 SWEA 1249 보급로 문제풀이

#include <iostream>
#include <stdio.h>
#include <queue>
#include <limits.h>

using namespace std;

int map[100][100];
int sumMap[100][100];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
queue < pair<int, int>> q;

int main() {

    int T;
    cin >> T;

    for(int test_case = 1; test_case <= T; test_case++) {
        int N;
        cin >> N;

        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                scanf("%1d", &map[i][j]);
                sumMap[i][j] = INT_MAX;
            }
        }

        sumMap[0][0] = 0;
        q.push(make_pair(0, 0));

        while(!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(int i = 0; i < 4; i++) {
                int xx = x + dx[i];
                int yy = y + dy[i];
                if(xx >= 0 && xx < N && yy >= 0 && yy < N) {
                    if(sumMap[xx][yy] > sumMap[x][y] + map[xx][yy]) {
                        sumMap[xx][yy] = sumMap[x][y] + map[xx][yy];
                        q.push({xx, yy});
                    }
                }

            }
        }

        

        cout << "#" << test_case << " " << sumMap[N - 1][N - 1] << endl;

    }

    return 0;
}