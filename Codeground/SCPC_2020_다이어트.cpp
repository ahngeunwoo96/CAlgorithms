// SCPC 2020 다이어트

#include <iostream>
#include <algorithm>

using namespace std;

int cal_a[200000], cal_b[200000];

bool compare(int a, int b) {
    return a > b;
}

int main () {
    int T;
    cin >> T;

    for(int tc = 1; tc <= T; tc++) {
        int Answer = 0;
        int num, date;
        cin >> num >> date;

        for(int i = 0; i < num; i++) {
            cin >> cal_a[i];
        }

        for(int i = 0; i < num; i++) {
            cin >> cal_b[i];
        }

        sort(cal_a, cal_a + num);
        sort(cal_b, cal_b + num, compare);

        for(int i = 0; i < date; i++) {
            Answer = max(Answer, cal_b[num - date + i] + cal_a[i]);
        }

        cout << "Case #" << tc << "\n" << Answer << endl;




    }

    return 0;
}