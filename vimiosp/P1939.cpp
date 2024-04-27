#include <iostream>
#include <algorithm>
#include <cstring>
#define int long long

using namespace std;
const int p = 1e9 + 7;
int t, x;
struct mat{
  int x, y, m[5][5];
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
          c.m[i][j] = (c.m[i][j] + a.m[i][k] * b.m[k][j] % p) % p;
    return c;
  }
}unit, r, k;
mat pow(mat a, int k){
  if (k <= 1) return k == 0 ? unit : a;
  mat t = pow(a, k / 2);
  if (k & 1) return t * t * a;
  return t * t;
}

signed main(){
  scanf("%lld", &t);
  unit.unit(3), r.sz(3, 3), k.sz(1, 3);
  r.m[1][3] = r.m[2][1] = r.m[3][2] = r.m[3][3] = 1;
  k.m[1][1] = k.m[1][2] = k.m[1][3] = 1;
  while (t--){
    scanf("%lld", &x);
    if (x <= 3) puts("1");
    else{
      mat tmp = k * pow(r, x - 3);
      printf("%lld\n", tmp.m[1][3]);
    }
  }
}
