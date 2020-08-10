
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

//// ������ ������ ���� �� ����..!!
//bool compare(int a, int b) {
//	return a < b; // a < b�϶� true!! ������������ ���ĵ�
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


// �����͸� ��� ����? ������ �����͵��� ��ü�� �����Ǿ� ����

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
		Student("�� �� ��", 90),
		Student("�� �� ��", 99),
		Student("�� �� ��", 97)
	};

	sort(students, students + 3);
	for (int i = 0; i < 3; i++) {
		cout << students[i].name << ' ';
	}
	return 0;
}