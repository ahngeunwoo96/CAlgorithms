// codeground 연습문제 이항계수의 합

#include <iostream>

using namespace std;

int Answer;

int main () {
    int T;
    cin >> T;

    for(int tc = 1; tc <= T; tc++) {
        Answer = 0;
        int n, m;
        cin >> n >> m;

        for(int a = 0; a <= n; a++)
            for(int b = 0; b <= m; b++){
                int Sum = 1;
                for(int i = b + 1; i <= a + b ; i++) {
                    Sum *= i;
                }
                
                for(int i = 1; i <= a; i++) {
                    Sum /= i;
                }
                Answer += Sum;
            }

        cout << "Case #" << tc << "\n" << Answer % 1000000007 << endl;

    }

    return 0;
}