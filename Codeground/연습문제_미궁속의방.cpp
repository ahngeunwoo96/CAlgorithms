// codeground 연습문제 미궁속의 방

#include <iostream>

using namespace std;

#define up 1
#define down 0

int Map[100000][100000];

int main () {

    int T;
    cin >> T;

    for(int tc = 1; tc <= T; tc++) {
        int n, k;
        cin >> n >> k;

        int cnt = 0;
        int x = 0, y = 0, dec = 0, dir = down, thr = 0;

        Map[0][0] = ++cnt;

        while(y != n && x != n) {

            if(x == n || y == n) dec = 1;

            if(dec == 1) ++thr;

            if(dir == up){
                if(dec == 1) {
                    Map[y][++x] = ++cnt;
                    while(y != thr)
                        Map[--y][++x] = ++cnt;
                }
                else {
                    Map[++y][x] = ++cnt;
                    while(y != 0) 
                        Map[--y][++x] = ++cnt;
                }
                dir = down;
            }
            else {
                if(dec == 1) {
                    Map[++y][x] = ++cnt;
                    while(x != thr) 
                        Map[++y][--x] = ++cnt;
                }
                else {
                    Map[y][++x] = ++cnt;
                    while(x != 0) 
                        Map[++y][--x] = ++cnt;
                }
                dir = up;
            }

        }

        for(int yy = 0; yy < n; yy++) {
            for(int xx = 0; xx < n; xx++) {
                cout << Map[yy][xx] << " ";
            }
            cout << endl;
        }
            
    }

    return 0;
}
