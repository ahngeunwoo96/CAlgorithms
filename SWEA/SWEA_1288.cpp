// sw 1288 ���ο� �Ҹ��� ġ���

#include <iostream> 
#include <string>

using namespace std;
int numCheck[10];
bool allNumber = true;
int answer;

void Sheep(int num, int x) {

	string number = to_string(num * x);

	for(int i = 0; i < number.size(); i++) {
		numCheck[number[i]] = 1;
	}

	allNumber = true;
	for(int i = 0; i < 10; i++) {
		if(numCheck[i] == 0)
			allNumber = false;
	}

	if(allNumber == true) {
		answer = x * num;
		return;
	}
	
	Sheep(num, x + 1);
}

int main() {
	int T;
	cin >> T;

	for (int test_case = 1; test_case <= T; test_case++) {
		answer = 0;
		int num;
		cin >> num;

		for(int i = 0; i < 10; i++) {
			numCheck[i] = 0;
		}

		Sheep(num, 1);
	}
	return 0;
}