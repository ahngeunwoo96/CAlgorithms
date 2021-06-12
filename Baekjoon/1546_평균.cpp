#include <iostream>

using namespace std;

int main() {
  int N;
  cin >> N;
  int score[1000];

  for (int i = 0; i < N; i++) {
    cin >> score[i];
  }

  // 최댓값 구하기
  int max = 0;
  for (int i = 0; i < N; i++) {
    if (max < score[i]) max = score[i];
  }

  // 새로운 점수의 합 구하기
  float sum = 0;
  for (int i = 0; i < N; i++) {
    sum += score[i] / (float)max * 100;
  }

  // 평균 구하기
  float avg = sum / (float)N;

  cout << fixed;
  cout.precision(2);
  cout << avg << endl;
}