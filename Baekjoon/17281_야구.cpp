#include <iostream>

using namespace std;

int main(){
  int N;
  cin >> N; 
  int hitter[9][N];

  for(int i = 0; i < N; i++) {
    for(int j = 0; j < 9; j++) {
      cin >> hitter[j][i];
    }
  }

  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      cout << hitter[j][i];
    }
    cout << endl;
  } 

  return 0;
}