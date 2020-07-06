
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

//// 정렬할 기준을 만들 수 있음..!!
//bool compare(int a, int b) {
//	return a < b; // a < b일때 true!! 오름차순으로 정렬됨
//}
//
//int main(void) {
//	int a[10] = { 9, 3, 5, 4, 1, 10, 8, 6, 7, 2 };
//	sort(a, a + 10, compare);
//	
//	for (int i = 0; i < 10; i++) {
//		cout << a[i] << " ";
//	}
//
//	return 0;
//}


// 데이터를 묶어서 정렬? 보통은 데이터들이 객체로 정리되어 있음

class Student {
public:
	string name;
	int score;
	Student(string name, int score) {
		this->name = name;
		this->score = score;
	}

	bool operator <(Student &student) {
		return this->score < student.score;
	}
};

int main() {
	Student students[] = {
		Student("나 동 빈", 90),
		Student("안 건 우", 99),
		Student("박 한 울", 97)
	};

	sort(students, students + 3);
	for (int i = 0; i < 3; i++) {
		cout << students[i].name << ' ';
	}
	return 0;
}