// Codeground 연습문제 프로그래밍 경진대회

#include <iostream>
#include <algorithm>

using namespace std;

int Answer;

int main() {
    int T;
    cin >> T;

    int Score[300000];
    int Max[300000];

    for(int tc = 1; tc <= T; tc ++) {
        Answer = 0;

        int n;
        cin >> n;
        
        int max = 0;

        for(int i = 0; i < n; i++) {
            cin >> Score[i];
            Max[i] = Score[i];
        }

        sort(Max, Max + n);

        for(int i = 0; i < n; i++) {
            Max[i] += n - i;
            if(max < Max[i])
                max = Max[i];
        }

        for(int i = 0; i < n; i++) {
            if(Score[i] + n >= max ) 
                Answer += 1;
        }

        cout << "Case #" << tc << "\n" << Answer << endl;
    }

    return 0;
}
