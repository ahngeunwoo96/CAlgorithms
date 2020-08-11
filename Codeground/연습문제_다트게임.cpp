#include <iostream>
#include <math.h>

using namespace std;

int Answer;

int main() {
    int T;
    cin >> T;

    int Score[20] = { 6, 13, 4, 18, 1, 20, 5, 12, 9, 14, 11, 8, 16, 7, 19, 3, 17, 2, 15, 10 };


    for(int tc = 1; tc <= T; tc++) {
        Answer = 0;
        int Bonus;
        int A, B, C, D, E; // A : BULL의 반지름, B : TRIPLE시작구간의 반지름, C : TRIPLE종료구간의 반지름, D : DOUBLE시작구간의 반지름, E : DOUBLE종료구간의 반지름 
        cin >> A >> B >> C >> D >> E;
        
        int n;
        cin >> n;

        for(int i = 0; i < n; i++) {
            double x, y;
            cin >> x >> y;

            // x, y의 좌표에 따라 몇 점인지 계산하는 코드

            double dis = sqrt((x * x) + (y * y));

            if(dis < A) {
                Bonus = 50;
            }
            else if(A < dis && dis < B) {
                Bonus = 1;
            }
            else if(B < dis && dis < C) {
                Bonus = 3;
            }
            else if(C < dis && dis < D) {
                Bonus = 1;
            }
            else if(D < dis && dis < E) {
                Bonus = 2;
            }
            else 
                Bonus = 0;

            // 각도에 따라 점수를 계산 
            // 이후에 dis값에 따라 배수를 할지 계산 
            double theta = atan2(y, x) * (double)180 / M_PI;
            if(theta < 0) 
                theta += 360;

            if(Bonus == 50) 
                Answer += 50;
            else 
                Answer += Score[(int)((theta + 9) / 18)] * Bonus;
        }

        cout << "Case #" << tc << "\n" << Answer << endl;
        
    }

    return 0;
}