#include <iostream>
#include <string>

using namespace std;

int main(void) {
	string n;
	cin >> n;
	string tmp = "";
	int sum = 0;
	int minus = 0;
	long unsigned  int i;

	for (i = 0; i <= n.size(); i++) {
		if (n[i] == '+' || n[i] == '-' || n[i] == '\0') {
			if (minus) {
				sum -= stoi(tmp);
			}
			else {
				sum += stoi(tmp);
			}
			
			if (n[i] == '-') {
				minus = 1;
			}

			tmp = "";
			continue;

		}
		tmp += n[i];
	}

	cout << sum << endl;

	return 0;
}