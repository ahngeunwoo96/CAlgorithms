// 20.12.28 SWEA 2005 파스칼의 삼각형 문제풀이

#include <iostream>

using namespace std;

int pascal[10][10];

void makePascalTriangle(int N) {
    pascal[0][0] = 1;
    pascal[1][0] = 1;
    pascal[1][1] = 1;

    if(N > 2) {
        for(int i = 2; i < N; i++) {
            pascal[i][0] = 1;
            pascal[i][N - 1] = 1;
            for(int j = 1; j < N - 1; j++) {
                pascal[i][j] = pascal[i - 1][j - 1] + pascal[i - 1][j];
            }
        }
    }
    
}

int main() {

    int T;
    cin >> T;

    for(int test_case = 1; test_case <= T; test_case++) {
        // 파스칼의 삼각형 만들기

        for(int i = 0; i < 10; i++) {
            for(int j = 0; j < 10; j++) {
                pascal[i][j] = 0;
            }
        }

        int N;
        cin >> N;

        makePascalTriangle(N);

        cout << "#" << test_case << endl;

        for(int i = 0; i < N; i++) {
            for(int j = 0; j <= i; j++) {
                cout << pascal[i][j] << " ";
            }
            cout << endl;
        }

    }

    return 0;
}