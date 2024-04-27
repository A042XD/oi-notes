#include <iostream>
#include <algorithm>
#define int long long

using namespace std;
int gcd(int a, int b){return !b ? a : gcd(b, a % b);}
void exgcd(int a, int b, int &x, int &y, int &d){
  if (!b) return d = a, x = 1, y = 0, void();
  exgcd(b, a % b, y, x, d), y -= a / b * x;
}

signed main(){
  int a, b, c;
  cin >> a >> b >> c;
  cout << gcd(gcd(a, b), c);
  return 0;
}
