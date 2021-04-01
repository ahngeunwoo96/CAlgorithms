#include <iostream>

using namespace std;

int main(){

  int tc = 3;
  // cin >> tc;

  for (int test_case = 1; test_case <= tc; test_case ++) {
    int d = 200, l = 12, n = 10;
    // cin >> d >> l >> n;

    long int damage = 0;

    for (int i = 0; i < n; i++){
      damage += d * (1 + (n * l) / 100);
    }

    cout << "#" << test_case << " " << damage << endl;

  }

  return 0;
}