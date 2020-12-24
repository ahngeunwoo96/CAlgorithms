// 20.12.24 SWEA 1926 문제풀이

#include <iostream>
#include <string>

using namespace std;

int main() {
    int N;
        cin >> N;

        for(int i = 1; i <= N; i++) {
            if(i >= 100) {
                int tempNum = i;
                if((i / 100) == 3 || (i / 100) == 6 || (i / 100) == 9) {
                    cout << "-";
                } 
                tempNum = tempNum % 100;
                if((tempNum / 10) == 3 || (tempNum / 10) == 6 || (tempNum / 10) == 9) {
                    cout << "-";
                }
                if((tempNum % 10) == 3 || (tempNum % 10) == 6 || (tempNum % 10) == 9) {
                    cout << "-";
                }
                if((i / 100) != 3 && (i / 100) != 6 && (i / 100) != 9 && (tempNum / 10) != 3 && (tempNum / 10) != 6 && (tempNum / 10) != 9 && (tempNum % 10) != 3 && (tempNum % 10) != 6 && (tempNum % 10) != 9) {
                    cout << i;
                }
                cout << " ";
            }
            else if(i >= 10) {
                if((i / 10) == 3 || (i / 10) == 6 || (i / 10) == 9) {
                    cout << "-";
                }
                if((i % 10) == 3 || (i % 10) == 6 || (i % 10) == 9) {
                    cout << "-";
                }
                if((i / 10) != 3 && (i / 10) != 6 && (i / 10) != 9 && (i % 10) != 3 && (i % 10) != 6 && (i % 10) != 9) {
                    cout << i;
                }
                cout << " ";
            }
            else {
                if(i % 3 == 0) {
                    cout << "- ";
                }          
                else 
                    cout << i << " ";
            }

        }

        cout << endl;

    return 0;
}