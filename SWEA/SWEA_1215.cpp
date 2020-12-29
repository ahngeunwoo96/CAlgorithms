// 20.12.29 SWEA 1215 회문1 문제풀이

#include <iostream>

using namespace std;

char map[8][8];
int answer;

int main() {

    for(int test_case = 1; test_case <= 10; test_case++) {
        answer = 0;
        int len;
        cin >> len;

        for(int i = 0; i < 8; i++) {
            for(int j = 0; j < 8; j++) {
                cin >> map[i][j];
            }
        }

        // 가로로 회문 검사 
        for(int i = 0; i < 8; i++) {
            for(int j = 0; j < 8 - len + 1; j++) { // j: 시작점
                bool isCir = true;
                // 회문 확인
                for(int k = 0; k < len / 2; k++) {
                    if(map[i][j + k] != map[i][j + len - 1 - k]) {
                        isCir = false;
                        break;
                    }
                }

                if(isCir == true) {
                    answer++;
                }

                isCir = true;

                for(int k = 0; k < len / 2; k++) {
                    if(map[j + k][i] != map[j + len - 1 -k][i]) {
                        isCir = false;
                        break;
                    }
                }

                if(isCir == true) {
                    answer++;
                }

            }
        }

        cout << "#" << test_case << " " << answer << endl;

    }

    return 0;
}