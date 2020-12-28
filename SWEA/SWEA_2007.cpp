// 20.12.27 SWEA 2007 패턴 마디의 길이 문제풀이

#include <iostream> 

using namespace std;

int main() {

    int T;
    cin >> T;

    for(int test_case = 1; test_case <= T; test_case++) {
        string text;
        cin >> text;

        for(int len = 1; len <= 10; len++) { // len은 마디의 길이 
            bool isAnswer = true;

            for(int i = 0; i < 30; i += len) {
                for(int j = 0; j < len && i + j < 30; j++) {
                    if(text[j] != text[i + j]) {
                        isAnswer = false;
                    }
                }
            }

            if(isAnswer == true) {
                cout << "#" << test_case << " " << len << endl;
                break;
            }
            else continue;

        }

    }

    return 0;
}