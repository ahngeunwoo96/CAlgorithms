// 월간코딩챌린지 시즌1 0927 문제3 풍선터뜨리기 

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;
vector <int> answer_a;

int solution(vector<int> a) {
    int answer = 0;

    answer = 2; // 처음과 끝은 무조건 가능

    vector<pair<int, int> > a_index;

    for(int i = 0; i < a.size(); i++) {
        // vector a의 값과 index값을 같이 가지고 있는 vector를 만들어 줌
        a_index.push_back(pair<int, int>(a[i], i));
    }

    // a_index를 오름차순으로 정렬 
    sort(a_index.begin(), a_index.end());

    int start = min(a_index[0].second, a_index[1].second);
    int end = max(a_index[0].second, a_index[1].second);

    // 3번째 작은 값부터 최후에 남길 수 있는 풍선인지 확인 
    for(int i = 2; i < a_index.size(); i++) {
        if(a_index[i].second > start && a_index[i].second < end) {// 자신의 왼쪽, 오른쪽에 자신보다 작은 값이 존재할 때 (불가능)

        }
        else { // 한쪽에만 자신보다 작은 값이 존재할 때 
            ++answer;
            if(a_index[i].second > end)
                end = a_index[i].second;
            else 
                start = a_index[i].second;
        }
    }

    return answer;

}

int main() {
    vector <int> a;

    a.push_back(<int>(-16, 27, 65, -2, 58, -92, -71, -68, -61, -33));

    // a.push_back(-16);
    // a.push_back(27);
    // a.push_back(65);
    // a.push_back(-2);
    // a.push_back(58);
    // a.push_back(-92);
    // a.push_back(-71);
    // a.push_back(-68);
    // a.push_back(-61);
    // a.push_back(-33);


    int answer = solution(a);

    for(int i = 0; i < answer_a.size(); i++) {
        cout << answer_a[i] << endl;
    }

    cout << answer << endl;


    return 0;
}

// 66.7점 받음,,방법을 변경해야 함!! 

// #include <iostream>
// #include <vector>
// #include <string>

// using namespace std;
// vector <int> answer_a;

// int solution(vector<int> a) {
//     int answer = 0;

//     answer = 2;
//     int left_is_small = false, right_is_small = false;

//     for(int i = 1; i < a.size() - 1; i++) {
//         left_is_small = false, right_is_small = false;
//         for(int j = 0; j < i; j++) { 
//             if(a[j] < a[i]) {
//                 left_is_small = true;
//                 break;
//             }
//         }

//         for(int k = i + 1; k < a.size(); k++) {
//             if(a[k] < a[i]) {
//                 right_is_small = true;
//                 break;
//             }
//         }

//         if(left_is_small == false || right_is_small == false)
//             answer += 1;
            
//     }

//     return answer;
// }