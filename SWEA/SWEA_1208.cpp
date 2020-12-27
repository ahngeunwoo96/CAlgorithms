// SWEA 1208 [S/W 문제해결 기본] 1일차 - Flatten

#include <iostream>
#include <algorithm>

using namespace std;

int main() {

    for(int tc = 1; tc <= 10; tc++) {
        int dump_num;
        cin >> dump_num;

        int box_height[100] = {0};

        for(int i = 0; i < 100; i++) {
            cin >> box_height[i];
        }

        sort(box_height, box_height + 100);

        for(; dump_num > 0; dump_num--) {
        
        // 최고점에서 하나를 빼고 최저점에서 하나를 더 함
        box_height[99] -= 1;
        if(box_height[99] < box_height[98]) {
            box_height[98] = box_height[99];
            box_height[99] += 1;
        }
        box_height[0] += 1;
        if(box_height[0] > box_height[1]) {
            box_height[0] = box_height[1];
            box_height[1] += 1;
        } 
        sort(box_height, box_height + 100);
        }

        cout << "#" << " " << box_height[99] - box_height[0] << endl;
        
  }

    return 0;
}