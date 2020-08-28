// SCPC 5회 예선 세포키우기

#include <iostream>
#include <math.h>

using namespace std;

int Answer;

int find_min_dis(int pt, int x[100000], int y[100000], int n) {
    int dis, minnum = INT_MAX;
    for(int i = 0; i < n; i++) {
        dis = min(abs(pt - x[i]), y[i]);
    }
    return dis;
}

int main() {
    int T;
    cin >> T;

    for(int tc = 1; tc <= T; tc++) {
        int line_l, line_r, n, maxnum = 0;
        int x[100000], y[100000];

        cin >> line_l >> line_r;
        cin >> n;

        for(int i = 0; i < n; i++) {
            cin >> x[i] >> y[i];
        }

        for(int i = line_l; i <= line_r; i++) {
            maxnum = max(maxnum, find_min_dis(i, x, y, n));

        }

        cout << "Case #" << tc << "\n" << Answer << endl;


    }

    return 0;
}