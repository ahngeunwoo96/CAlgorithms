// SCPC 2019 1차 예선 공 굴리기

#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
#include <stdio.h>

#define PI 3.141592

using namespace std;

int lef[1000], rig[1000], hei[1000];

int main() {
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		
		double r, start, end, n;
		cin >> r >> start >> end;

		double dis = end - start;

		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> lef[i] >> rig[i] >> hei[i];
		}

		for (int i = 0; i < n; i++) {

			if (hei[i] >= r) {
				dis += 2 * hei[i] + r * M_PI - 4 * r;
			}
			else {
				double row = sqrt(r * r - (r - hei[i]) * (r - hei[i]));
				double theta = M_PI / 2 - atan2(r - hei[i], row);
				dis += 2 * r * theta - 2 * row;
			}
		}

		cout << "Case #" << tc << endl;
		printf("%.6lf", dis);
	}

	return 0;
}