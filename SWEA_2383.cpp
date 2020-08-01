// swea 2383 점심 식사시간

#include <iostream>
#include <limits.h>

using namespace std;

int input[10][10];
int people_x[10], people_y[10], people_cnt = 0, move_time[10], using_str[10], str_per[2];
int stair_x[2], stair_y[2], stair_len[2], stair_cnt, min_time = INT_MAX, ans;

void timetomove() {
	int t = 0;
	for (int i = 0; i < stair_cnt; i++) {
		str_per[i] = 0;
	}

	for (int per = 0; per < people_cnt; per++) // 사람마다 계단까지 걸리는 시간을 측정
		move_time[per] = abs(people_x[per] - stair_x[using_str[per]]) + abs(people_y[per] - stair_y[using_str[per]]);

	int end_num = 0;

	while (1) {

		for (int per = 0; per < people_cnt; per++) {
			move_time[per]--; // 1초의 이동시간 감소 

			if (move_time[per] == -(stair_len[using_str[per]] + 1)) { // 계단의 끝에 온 경우
				str_per[using_str[per]]--; // 계단에 올라와있는 사람의 수를 감소 
				end_num++; // 끝낸 사람의 수를 증가
			}
		}

		for(int per = 0; per < people_cnt; per++) {
			if (move_time[per] == -1) { // 계단의 입구에 도착해서 1분을 기다린 후 
				if (str_per[using_str[per]] == 3) // 계단에 올라와있는 사람의 수가 3명인 경우
					//wait
					move_time[per]++;
				else str_per[using_str[per]]++; // 계단에 올라와있는 사람의 수를 증가
			}
		}

		t++; // 시간 증가

		if (end_num == people_cnt) { // 모든 사람이 도착한 경우
			if (min_time > t)
				min_time = t;
			break;
		}

		if (min_time < t)
			break;
	}
}

void person_matching(int per) {
	if (per == people_cnt) {
		timetomove();
		return;
	}
	
	for (int str = 0; str < stair_cnt; str++)
	{
		using_str[per] = str;
		person_matching(per + 1);
	}
}


int main() {
	int T;
	cin >> T;
	int ans;

	// 테스트 케이스 
	for (int tc = 1; tc <= T; tc++) {
		int n;
		cin >> n;
		people_cnt = 0; stair_cnt = 0;

		for (int y = 0; y < n; y++)
			for (int x = 0; x < n; x++)
			{
				cin >> input[y][x];
				if (input[y][x] == 1) { // 사람이 있는 경우
					people_x[people_cnt] = x;
					people_y[people_cnt++] = y;
				}
				else if (input[y][x] >= 2 && input[y][x] <= 10) // 계단이 있는 경우
				{
					stair_x[stair_cnt] = x;
					stair_y[stair_cnt] = y;
					stair_len[stair_cnt++] = input[y][x];
				}
			}


		min_time = INT_MAX;
		person_matching(0);
		cout << "#" << tc << " " << min_time << endl;

	}

	return 0;
}