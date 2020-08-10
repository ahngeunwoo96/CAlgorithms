// codeground 연습문제 숫자 골라내기

#include <iostream>

using namespace std;

int main() {
    int T;
    cin >> T;

    for(int tc = 1; tc <= T; tc++) {
            int n;
            cin >> n;
            int sum = 0 ;

            int number[10] = { 0 };

            for(int i = 0; i < n; i++) {
                int num;
                cin >> num;

                number[num] += 1;
            }

            for(int i = 0; i < 10; i++) {
                if(number[i] % 2 != 0) {
                    sum += i;
                }
            }

            cout << "Case #" << tc << "\n" << sum << endl;

    }


    return 0;
}