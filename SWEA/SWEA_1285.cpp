// swea 1285 아름이의 돌 던지기

#include <iostream>
#include <algorithm>

using namespace std;

int dis[1000];

int main() {
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		int ans = 100001, cnt = 0;
		int per;
		cin >> per;

		for (int i = 0; i < per; i++) {
			cin >> dis[i];
		}

		for (int i = 0; i < per; i++) {
			ans = min(ans, abs(dis[i]));
		}

		for (int i = 0; i < per; i++) {
			if (ans == abs(dis[i]))
				cnt++;
		}

		cout << "#" << tc << " " << ans << " " << cnt << endl;
	}
	return 0;
}