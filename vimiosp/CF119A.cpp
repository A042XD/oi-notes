#include <iostream>
#include <algorithm>

using namespace std;
const int N = 105;
int a, b, n;
int gcd(int a, int b){return !b ? a : gcd(b, a % b);}

int main(){
  scanf("%d %d %d", &a, &b, &n);
  if (!a) puts("0"), exit(0);
  if (!b) puts("1"), exit(0);
  while (n){
    n -= gcd(a, n);
    if (!n) puts("0"), exit(0);
    n -= gcd(b, n);
    if (!n) puts("1"), exit(0);
  }
  return 0;
}
