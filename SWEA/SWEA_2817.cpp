// 20.12.28 SWEA 2817 부분 수열의 합 문제풀이

#include <iostream>

using namespace std;

int num[20], K, N;
int answer;

void make_K(int i, int sum) {
    sum += num[i];

    if(sum == K) {
        answer++;
        return;
    }
    else if(sum > K) {
        return;
    }

    for(int j = i + 1; j < N; j++) {
        make_K(j, sum);
    }
}

int main() {

    int T;
    cin >> T;

    for(int test_case = 1; test_case <= T; test_case++) {
        answer = 0;
        cin >> N >> K;

        for(int i = 0; i < 20; i++) {
            num[i] = 0;
        }

        for(int i = 0; i < N; i++) {
            cin >> num[i];
        }

        for(int i = 0; i < N; i++) {
            make_K(i, 0);
        }

        cout << "#" << test_case << " " << answer << endl;
        
    }

    return 0;
}