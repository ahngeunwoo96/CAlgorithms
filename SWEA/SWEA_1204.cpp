// 20.12.15 SWEA 1024 최빈수 구하기

#include <iostream>

using namespace std;

int answer;

int main() {

    int T;
    cin >> T;

    for(int test_case = 1; test_case <= T; test_case++) {
        answer = 0;
        int max = 0;

        int score[101] = {0};
        cin >> test_case;

        for(int i = 0; i < 1000; i++) {
            int n;
            cin >> n;

            score[n]++;
        } 

        for(int i = 100; i >= 0; i--) {
            if(max < score[i]){
                max = score[i];
                answer = i;
            }
        }

    cout << "#" << test_case << " " << answer << endl;

    }

    return 0;
}