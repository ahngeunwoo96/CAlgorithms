// codeground 연습문제 이항계수의 합

#include <iostream>

using namespace std;

long long int Answer;

int main () {
    int T;
    cin >> T;

    for(int tc = 1; tc <= T; tc++) {
        Answer = 1;
        int n, m;
        cin >> n >> m;

        

        for(int i =  m + 2; i <= m + n + 2; i++) {
            Answer *= i;
        }

        for(int i = 1; i <= n + 1; i++) {
            Answer /= i;
        }

        Answer -= 1;

        cout << "Case #" << tc << "\n" << Answer % 1000000007 << endl;

    }

    return 0;
}