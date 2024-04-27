#include <iostream>
using namespace std;
int gcd(int a, int b){return !b ? a : gcd(b, a % b);}
int main(){
  int a, b, n; cin >> a >> b >> n;
  int x = a * b / gcd(a, b);
  while (n % x) n++;
  cout << n << endl;
  return 0;
}
