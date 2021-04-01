# include <iostream>
# include <math.h>

using namespace std;

int GCD(int n1, int n2){

  if(n2 == 0){
    return n1;
  }

  return GCD(n2, n1 % n2);

}

int main() {
    int n1, n2;
    cin >> n1 >> n2;

    int gcd = GCD(max(n1, n2), min(n1, n2));
    int lcm = gcd * (n1 / gcd) * (n2 / gcd);

    cout << gcd << endl;
    cout << lcm << endl;

}


