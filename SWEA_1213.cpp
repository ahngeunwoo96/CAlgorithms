// swea 1213 String

#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

int main() {

	for (int tc = 1; tc <= 10; tc++) {
		cin >> tc;
		int ans = 0;

		string con;
		string String;

		cin >> con;
		cin >> String;


		for (int i = 0; i <= String.length() - con.length(); i++) {
			int cnt = 0;
			for (int j = i; j < i + con.length(); j++) {
				if (con[j - i] == String[j])
				{
					cnt++;
				}
				else break;
				
				if (cnt == con.length())
					ans++;
			}
		}

		cout << "#" << tc << " " << ans << endl;

	}

	return 0;
}