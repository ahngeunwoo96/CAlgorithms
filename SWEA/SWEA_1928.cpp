// sw 1928 20.12.22 Base64 Decoder

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int deco[24];
string encText = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

int main() {
	int T;
	cin >> T;

	for (int test_case = 0; test_case < T; test_case++) {
		string encodedText, decodedText = "", twoBit = "";
		cin >> encodedText;
		cout << "#" << test_case + 1 << " ";

		for(int i = 0; i < encodedText.size(); i+=4) {
			twoBit.clear();

			for(int j = 0; j < 4; j++) {
				int num = encText.find(encodedText[i + j]);

				string temp = "";
				for(int k = 0; k < 6; k++) {
					temp += (num % 2) + '0'; 
					num /= 2;
				}
				reverse(temp.begin(), temp.end());
				twoBit += temp;
			}

			for(int j = 0; j < 3; j++) {
				int num = 0;
				for(int k = 0; k < 8; k++) {
					if(twoBit[j * 8 + k] == '1') {
						num += (1 << (7 - k));
					}
				}
				decodedText += (char)num;
			}
		}	
		cout << decodedText << endl;
	}

	return 0;
}
