// SWEA 1244 2일차 - 최대상금 
#include <iostream>
#include <algorithm>

using namespace std;

int saveNumber(int num, int number[], int sorted_number[], int cnt) {

	if(num / 100000 != 0) {
		number[0] = num / 100000;
		sorted_number[0] = number[0];
		num = num % 100000;
		cnt++;
	}
	
	if(num / 10000 != 0) {
		number[1] = num / 10000;
		sorted_number[1] = number[1];
		num = num % 10000;
		cnt++;
	}

	if(num / 1000 != 0) {
		number[2] = num / 1000;
		sorted_number[2] = number[2];
		num = num % 1000;
		cnt++;
	}

	if(num / 100 != 0) {
		number[3] = num / 100;
		sorted_number[3] = number[3];
		num = num % 100;
		cnt++;
	}

	if(num / 10 != 0) {
		number[4] = num / 10;
		sorted_number[4] = number[4];
		num = num % 10;
		cnt++;
	}

	if(num % 10 != 0) {
		number[5] = num % 10;
		sorted_number[5] = number[5];
		cnt++;
	}

	return cnt;
	
}

void sortnFindPos(int number[], int sorted_number[], int cnt, int pos[]) {
	int max = 0, pos_cnt = 0, max_pos = 0;
	// number = 8,8,8,5,3,2
	while(pos_cnt != 6) {
		max = 0;
		for(int i = 0; i <= cnt; i++) {
			if(number[i] > max && pos[i] == 0) {
				max = number[i];
				max_pos = i;
			}
		}
		pos[max_pos] = ++pos_cnt;
	}

	for(int i = 0; i < cnt; i++) {
		sorted_number[pos[i] - 1] = number[i];
	}
}



int main(int argc, char** argv)
{
	int test_case;
	int T;
	/*
	   아래의 freopen 함수는 input.txt 를 read only 형식으로 연 후,
	   앞으로 표준 입력(키보드) 대신 input.txt 파일로부터 읽어오겠다는 의미의 코드입니다.
	   //여러분이 작성한 코드를 테스트 할 때, 편의를 위해서 input.txt에 입력을 저장한 후,
	   freopen 함수를 이용하면 이후 cin 을 수행할 때 표준 입력 대신 파일로부터 입력을 받아올 수 있습니다.
	   따라서 테스트를 수행할 때에는 아래 주석을 지우고 이 함수를 사용하셔도 좋습니다.
	   freopen 함수를 사용하기 위해서는 #include <cstdio>, 혹은 #include <stdio.h> 가 필요합니다.
	   단, 채점을 위해 코드를 제출하
	   실 때에는 반드시 freopen 함수를 지우거나 주석 처리 하셔야 합니다.
	*/
	//freopen("input.txt", "r", stdin);
	//cin>>T;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/

	T = 1;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        int num, cnt = 0, change_cnt, answer = 0;
        //cin >> num >> change_cnt;

		num = 238588;
		change_cnt = 2;
        int number[6] = {0}, sorted_number[6] = {0}, pos[6] = {0};

        // number배열에 입력받은 숫자를 첫째자리부터 저장
        cnt = saveNumber(num, number, sorted_number, cnt);

		sortnFindPos(number, sorted_number, cnt, pos);

        for(int i = 0; i < change_cnt; i++) {
			
        }

		cout << "#" << test_case << endl;

	}
	
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}