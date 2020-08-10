// sw 1952 ¼ö¿µÀå

#include <iostream>
#include <algorithm>

using namespace std;
int Min = 3000 * 12 * 30 + 1;

int minimum_price(int index, int sum, int *price, int *plan) {

	if (index == 11) {
		sum += min(plan[index] * price[0], price[1]);
		if (Min > sum) Min = sum;
		return Min;
	}
	else if (index > 11) {
		if (Min > sum) Min = sum;
		return Min;
	}

	minimum_price(index + 1, sum + min(plan[index] * price[0], price[1]), price, plan);
	if (index < 10) {
		minimum_price(index + 3, sum + price[2], price, plan);
	}

	
}

int main() {

	int T;
	cin >> T;

	for (int test_case = 1; test_case <= T; test_case++) {
		int price[4] = { 0 };

		for (int i = 0; i < 4; i++) {
			cin >> price[i];
		}

		int plan[12];

		for (int i = 0; i < 12; i++) {
			cin >> plan[i];
		}

		minimum_price(0, 0, price, plan);

		Min = min(price[3], Min);

		cout << "#" << test_case << " " << Min << endl;

		Min = 3000 * 12 * 30 + 1;
	}
	return 0;
}