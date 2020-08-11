// codeground 연습문제 시험 공부

#include <iostream>
#include <algorithm>

using namespace std;

int Answer;

bool compare(int a, int b) {
    return a > b;
}

int main() {
    int T;
    cin >> T;

    int Score[200000];

    for(int tc = 1; tc <= T; tc++) {
        Answer = 0;
        int n, k;
        cin >> n >> k;

        for(int i = 0; i < n; i++) {
            cin >> Score[i];
        }

        sort(Score, Score + n, compare);

        for(int i = 0; i < k; i++) {
            Answer += Score[i];
        }

        cout << "Case #" << tc << "\n" << Answer << endl;

    }
    return 0;
}