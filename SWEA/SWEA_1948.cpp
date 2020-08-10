// sw 1948 날짜 계산기 

#include <iostream> 

using namespace std;

int main() {
	int T;
	cin >> T;
	int	max[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	for (int i = 0; i < T; i++) {
		int f_month, f_day, s_month, s_day, ans = 0;
		cin >> f_month >> f_day >> s_month >> s_day;

		if (f_month == s_month) {
			ans += s_day - f_day + 1;
		}
		else {
			for (int j = f_month; j < s_month; j++) {
				if (j == f_month) ans += max[f_month] - f_day + 1;
				else ans += max[j];
			}
			ans += s_day;
		}

		cout << "#" << i + 1 << " " << ans << endl;
	}

	return 0;
}