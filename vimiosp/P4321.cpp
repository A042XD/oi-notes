#include <iostream>
#include <algorithm>
#define int long long

using namespace std;
const int N = 1e7 + 5;
int n, m, ans, y, t[N];
int read(){
  int x = 0, f = 1; char c = getchar();
  while (c < '0' || c > '9'){if (c == '-') f = -1; c = getchar();}
  while (c >= '0' && c <= '9'){x = x * 10 + c - 48; c = getchar();}
  return x * f;
}

signed main(){
  n = read(), m = read();
  for (int i = 1, l, r, s, e; i <= m; i++){
    l = read(), r = read(), s = read(), e = read();
    int d = (e - s) / (r - l), p = s - d;
    t[l] += s, t[l + 1] += d - s, t[r + 1] -= e + d, t[r + 2] += e;
  }
  for (int i = 1, c = 0, r = 0; i <= n; i++)
    c += t[i], r += c, ans = max(ans, r), y ^= r;
  printf("%lld %lld", y, ans);
  return 0;
}

