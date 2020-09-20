#include <string>
#include <vector>
#include <stdlib.h>
#include <iostream>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;

    int end = n * (n + 1) / 2;
    int ans[16] = { 0};

    //int *ans = (int*)malloc(sizeof(int) * (end + 1));
    int cnt = 1, arr_num = 1;

    int dis = 1;

    while(cnt != end) {
        for(int i = 0; i < n; i++) {
            ans[arr_num] = cnt++;
            arr_num += dis;
            dis++;
        }
        arr_num -= dis - 2;
        n--;
        if(n==1)
            break;
        for(int i = 0; i < n; i++) {
            ans[arr_num] = cnt++;
            arr_num++;
        }
        arr_num -= dis;
        dis -= 2;
        n--;
        if(n == 1)
            break;
        for(int i = 0; i < n; i++) {
            ans[arr_num] = cnt++;
            arr_num -= dis;
            dis--;
        }
        arr_num += dis + 1;
        n--;
        if(n == 1)
            break;
        arr_num += dis + 1;
        dis++;
        
    }

    for(int i = 1; i <= end; i++) {
        answer.push_back(ans[i]);
    }

    
    return answer;
}

int main() {
    vector<int> answer;
    answer = solution(5);

    for(int i = 0; i < answer.size(); i++) {
        cout << answer[i] << endl;
    }

    return 0;
}