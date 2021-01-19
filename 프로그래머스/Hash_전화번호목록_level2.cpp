// 20.12.16 해시 전화번호목록 Level2 문제 풀이

#include <string>
#include <vector>
#include <math.h>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    
    for(int i = 0; i < phone_book.size(); i++) {
        for(int j = i + 1; j < phone_book.size(); j++) {
            string first_num, second_num;
            bool isNumberSame = true;
            first_num = phone_book[i];
            second_num = phone_book[j];

            for(int k = 0; k < min(first_num.size(), second_num.size()); k++) {
                if(first_num[k] != second_num[k]) {
                    isNumberSame = false;
                    break;
                }
            }

            if(isNumberSame == true) {
                answer = false;
                return answer;
            }
        }
    }
    
    return answer;
}