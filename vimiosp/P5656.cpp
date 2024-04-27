#include <iostream>
#include <algorithm>
#define int long long

using namespace std;
int t, a, b, c;
int read(){
  int x = 0, f = 1; char c = getchar();
  while (c < '0' || c > '9'){if (c == '-') f = -1; c = getchar();}
  while (c >= '0' && c <= '9'){x = x * 10 + c - 48; c = getchar();}
  return x * f;
}
void exgcd(int a, int b, int &x, int &y, int &d){
  if (!b) return x = 1, y = 0, d = a, void();
  exgcd(a, b % a, y, x, d), y -= a / b * x;
}

signed main(){
  scanf("%lld", &t);
  while (t--){
    scanf("%lld %lld %lld", &a, &b, &c); int d, x, y;
    exgcd(a, b, x, y, d); if (c % d){puts("-1"); continue;}
  }
  return 0;
}
