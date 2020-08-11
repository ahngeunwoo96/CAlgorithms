// codeground 연습문제 숫자 골라내기

#include <iostream>

using namespace std;

int main() {
    int T;
    cin >> T;

    for(int tc = 1; tc <= T; tc++) {
            unsigned int n;
            cin >> n;
            int sum = 0;

            for(int i = 0; i < n; i++) {
                int num;
                cin >> num;

                sum ^= num; // ^ : XOR 연산
            }

            cout << "Case #" << tc << "\n" << sum << endl;
    }


    return 0;
}