#include <iostream>
#include <algorithm>
#include <cstring>
#define int long long

using namespace std;
int p, a, c, x, n, g;
int mtp(int x, int y){
  int ans = 0;
  while (y){
    if (y & 1) ans = (ans + x) % p;
    x = (x + x) % p, y /= 2;
  }
  return ans;
}
struct mat{
  int m[4][4], x, y;
  mat(){memset(m, 0, sizeof(m));}
  void sz(int a, int b){y = a, x = b;}
  void unit(int n){
    sz(n, n);
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++)
        m[i][j] = i == j ? 1 : 0;
  }
  friend mat operator*(mat a, mat b){
    mat c; c.sz(a.y, b.x);
    for (int i = 1; i <= a.y; i++)
      for (int j = 1; j <= b.x; j++)
        for (int k = 1; k <= a.x; k++)
          c.m[i][j] = (c.m[i][j] + mtp(a.m[i][k], b.m[k][j]) % p) % p;
    return c;
  }
}unit, d, t;
mat pow(mat a, int k){
  if (k <= 1) return k == 1 ? a : unit;
  mat t = pow(a, k / 2);
  if (k & 1) return t * t * a;
  return t * t;
}

signed main(){
  scanf("%lld %lld %lld %lld %lld %lld", &p, &a, &c, &x, &n, &g);
  unit.unit(2); d.sz(2, 2), t.sz(1, 2);
  d.m[1][1] = a, d.m[2][1] = d.m[2][2] = 1;
  t.m[1][1] = x, t.m[1][2] = c;
  mat c = t * pow(d, n);
  printf("%lld", c.m[1][1] % g);
  return 0;
}
