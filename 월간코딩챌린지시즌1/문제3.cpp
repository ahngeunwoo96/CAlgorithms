// 월간코딩챌린지 시즌1 0927 문제3 풍선터뜨리기 

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector <int> answer_a;

int solution(vector<int> a) {
    int answer = 0;

    int min_num = INT_MAX, min_index;
    for(int i = 0; i < a.size(); i ++){
        if(min_num > a[i]) {
            min_num = a[i];
            min_index = i;
        }
    }

    answer = 2; // 처음과 끝은 무조건 가능
    for(int i = 1; i < a.size() - 1; i++) {
        int possible = true;
        if(i < min_index) {
            for(int j = 0; j < i; j++) {
                if(a[j] < a[i]){
                    possible = false;
                    break;
                }
            }
        }
        else if(i > min_index) {
            for(int j = i + 1; j < a.size(); j++) {
                if(a[j] < a[i]) {
                    possible = false;
                    break;
                }
            }
        }
        else {// 최소인 경우
            answer += 1;
            continue;
        }

    if(possible == true)
        answer += 1;

    }

    return answer;

}

int main() {
    vector <int> a;

    a.push_back(-16);
    a.push_back(27);
    a.push_back(65);
    a.push_back(-2);
    a.push_back(58);
    a.push_back(-92);
    a.push_back(-71);
    a.push_back(-68);
    a.push_back(-61);
    a.push_back(-33);


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