// 2020 kakao coding test 괄호변환

#include <iostream>
#include <string>
#include <string>

using namespace std;

string solution(string p){
    string answer = "";
    string u, v; // 문자열 u와 문자열 v를 저장할 변수
    int left_cnt = 0, right_cnt = 0; // 왼쪽 괄호와 오른쪽 괄호의 갯수를 저장할 변수
    int i = 0;
    if(p == "") return answer;

    do { // 왼쪽 괄호의 갯수가 오른쪽 괄호의 갯수와 같아질대까지 반복
        if(p[i] == '(') left_cnt++;
        else right_cnt++;

        i++;
    } while(left_cnt != right_cnt);

    for(int j = 0; j < i; j++) 
        u += p[j];
    
    for(int j = i; j < p.size(); j++) {
        v += p[j];
    }

    left_cnt = right_cnt = 0; // 왼쪽 괄호의 갯수와 오른쪽 괄호의 갯수를 초기화
    int right_string = 1; // 올바른 문자열인지 확인하는 변수
    for(int j = 0; j < u.size(); j++) {
        if(u[j] == '(') left_cnt++;
        else right_cnt++;

        if(right_cnt > left_cnt) {
            right_string = 0;
        }
    }

    if(right_string == 0) { // u가 올바르지 않은 문자열인경우 
        answer += '(';
        answer += solution(v);
        answer += ')';
        for(int j = 1; j < u.size() - 1; j++)
        {
            if(u[j] == '(') answer += ')';
            else answer += '(';
        }
    }
    else { // u가 올바른 문자열인 경우
        answer += u;
        answer += solution(v);
    }

    return answer;
}

int main () {

    string p;
    p = "()))((()";

    cout << solution(p) << endl;

    return 0;
}
