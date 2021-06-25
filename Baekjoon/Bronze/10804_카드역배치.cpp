#include <iostream>

using namespace std;

int main() {

  int cards[21];

  for (int i = 1; i <= 20; i++) {
    cards[i] = i;
  }

  for (int i = 1; i <= 20; i++) {
    cout << cards[i] << " ";
  }
  cout << endl;

  int s, e;
  for (int i = 0; i < 10; i++) {
    cin >> s >> e;

    while (s != e) {
      int temp;
      temp = cards[e];
      cards[e] = cards[s];
      cards[s] = temp;
      s++;
      e--;
    }
  }

  return 1;
}