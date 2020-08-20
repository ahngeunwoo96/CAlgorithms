// SCPC 5회 예선 세포키우기

#include <iostream>
#include <math.h>

using namespace std;

int Answer;

int main() {
    int T;
    cin >> T;

    for(int tc = 1; tc <= T; tc++) {
        int line_l, line_r, n, minnum = INT_MAX;

        cin >> line_l >> line_r;
        cin >> n;

        for(int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;

            if(x < line_l){
                if(minnum > min(line_l - x, y)) {
                    minnum = min(line_l - x, y);
                }
            }
            else if(line_l <= x && x <= line_r) {
                if(minnum > y) {
                    minnum = y;
                }
            }
            else {
                if(minnum > min(line_r - x, y)) {
                    minnum = min(line_r - x, y);
                }
            }
        }

        Answer = minnum;

        cout << "Case #" << tc << "\n" << Answer << endl;


    }

    return 0;
}