// swea 1284 수도 요금 경쟁 

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		int P, Q, R, S, W, ans;
		cin >> P >> Q >> R >> S >> W;

		int price_A, price_B;

		price_A = P * W;
		if (R >= W)
			price_B = Q;
		else price_B = Q + (W - R) * S;

		ans = min(price_A, price_B);

		cout << "#" << tc << " " << ans << endl;

		
	}
	return 0;
}