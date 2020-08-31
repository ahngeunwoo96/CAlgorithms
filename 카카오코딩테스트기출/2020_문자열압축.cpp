// 2020 kakao blind recruitment 문자열압축

// 문자열에서 같은 값이 연속해서 나타나는 것을 문자의 개수와 반복되는 값으로 표현하여
// 더 짧은 문자열로 줄여서 표현하는 최소값을 출력 
// 예를 들면 aabbaccc : 길이7의 문자열로 표현(2a2bc3c), abcabcdede : 길이8의 문자열로 출력(2abcdede)

#include <iostream>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

int solution(string s) {
    int answer = 100;

    if(s.size() == 1){
        answer = 1;
    }

    for(int cut_len = 1; cut_len <= s.size() / 2; cut_len++) { // cut_len : 자르는 문자열의 갯수

        int same_s_cnt = 1; // 일치하는 문자열의 갯수를 세기위한 변수
        int same_string = 1; // 두 문자열이 일치하는 문자열인지 확인하기 위한 변수
        string ans;

        // 문자열을 자른 후, 자른 문자열을 비교하기 위한 for문
        for(int i = 0; i < s.size(); i += same_s_cnt * cut_len) {
            same_s_cnt = 1;
            for(int j = i + cut_len ; j < s.size() ; j += cut_len) {
                same_string = 1;
                for(int k = 0; k < cut_len; k++) {
                    // 두 문자열이 일치하는 경우 
                    same_string = 1;
                    if(s[i + k] == s[j + k] && i + k < s.size() && j + k < s.size()){
                    } 
                    // 두 문자열이 일치하지 않는 경우
                    else{
                        same_string = 0;
                        break;
                    }
                }
                if(same_string == 1){
                    same_s_cnt++;
                }
                else{ 
                    break; 
                }
            }
            

                if(same_s_cnt != 1) { // 문자열이 일치하는 경우가 2개 이상인경우
                    ans += to_string(same_s_cnt);
                    for(int k = 0; k < cut_len; k++) {
                        ans += s[i + k];
                    }
                }
                else { // 문자열이 일치하는 경우가 없는 경우
                    for(int k = 0; k < cut_len; k++) {
                        if(i + k < s.size())
                            ans += s[i + k];
                    }
                }
            
                
            
        }
        int tmp = ans.size();
        answer = min(answer, tmp);
    }

    return answer;
}

int main() {
    string s;
    // cin >> s;

    s = "acdcacdcacdcacdc";

    cout << solution(s) << endl;

    return 0;
}