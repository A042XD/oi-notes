#include <iostream>
#include <algorithm>
#include <cstring>
#define mid ((cl + cr) / 2)
#define inr (l <= cl && cr <= r)
#define outr (cr < l || r < cl)

using namespace std;
const int N = 2.5e5 + 5, p = 998244353;
int n, q;
bool f[N * 4];
struct mat{
  int m[4][4];
  mat(){memset(m, 0, sizeof(m));}
  friend mat operator+(mat a, mat b){
    for (int i = 0; i < 4; i++)
      a.m[0][i] = (1ll * a.m[0][i] + b.m[0][i]) % p;
    return a;
  }
  friend mat operator*(mat a, mat b){
    mat c; 
    for (int i = 0; i < 4; i++)
      for (int j = 0; j < 4; j++){
        c.m[i][j] = (c.m[i][j] + (1ll * a.m[i][0] * b.m[0][j]) % p) % p;
        c.m[i][j] = (c.m[i][j] + (1ll * a.m[i][1] * b.m[1][j]) % p) % p;
        c.m[i][j] = (c.m[i][j] + (1ll * a.m[i][2] * b.m[2][j]) % p) % p;
        c.m[i][j] = (c.m[i][j] + (1ll * a.m[i][3] * b.m[3][j]) % p) % p;
      }
    return c;
  }
  friend mat mul(mat a, mat b){
    mat c;
    for (int j = 0; j < 4; j++){
      c.m[0][j] = (c.m[0][j] + (1ll * a.m[0][0] * b.m[0][j]) % p) % p;
      c.m[0][j] = (c.m[0][j] + (1ll * a.m[0][1] * b.m[1][j]) % p) % p;
      c.m[0][j] = (c.m[0][j] + (1ll * a.m[0][2] * b.m[2][j]) % p) % p;
      c.m[0][j] = (c.m[0][j] + (1ll * a.m[0][3] * b.m[3][j]) % p) % p;
    }
    return c;
  }
}ut, a[N], t[N * 4], lz[N * 4], r[7];
inline int read(){
  int x = 0, f = 1; char c = getchar();
  while (c < '0' || c > '9'){if (c == '-') f = -1; c = getchar();}
  while (c >= '0' && c <= '9'){x = x * 10 + c - 48; c = getchar();}
  return x * f;
}
void psdn(int u, int cl, int cr){
  if (!f[u]) return;
  if (cl >= cr) return;
  t[u * 2] = mul(t[u * 2], lz[u]);
  t[u * 2 + 1] = mul(t[u * 2 + 1], lz[u]);
  if (cr - cl == 1) return lz[u] = ut, f[u] = 0, void();
  lz[u * 2] = lz[u * 2] * lz[u];
  lz[u * 2 + 1] = lz[u * 2 + 1] * lz[u];
  f[u * 2] = f[u * 2 + 1] = 1;
  lz[u] = ut, f[u] = 0;
}
void bld(int u, int cl, int cr){
  lz[u] = ut;
  if (cl >= cr){
    t[u] = a[cl];
    return;
  }
  bld(u * 2, cl, mid);
  bld(u * 2 + 1, mid + 1, cr);
  t[u] = t[u * 2] + t[u * 2 + 1];
}
void chg(int u, int cl, int cr, int l, int r, mat x){
  if inr{
    t[u] = mul(t[u], x); 
    lz[u] = lz[u] * x;
    f[u] = 1;
    return;
  }
  psdn(u, cl, cr);
  if (l <= mid) chg(u * 2, cl, mid, l, r, x);
  if (mid < r) chg(u * 2 + 1, mid + 1, cr, l, r, x);
  t[u] = t[u * 2] + t[u * 2 + 1];
}
mat qry(int u, int cl, int cr, int l, int r){
  if inr return t[u];
  psdn(u, cl, cr); mat a;
  if (l <= mid) a = a + qry(u * 2, cl, mid, l, r);
  if (mid < r) a = a + qry(u * 2 + 1, mid + 1, cr, l, r);
  return a;
}

int main(){
  ut.m[0][0] = ut.m[1][1] = ut.m[2][2] = ut.m[3][3] = 1;
  n = read();
  for (int i = 1; i <= n; i++) 
    a[i].m[0][0] = read(), a[i].m[0][1] = read(), a[i].m[0][2] = read(), a[i].m[0][3] = 1;
  bld(1, 1, n), q = read();
  r[0] = r[1] = r[2] = r[3] = r[4] = r[5] = ut;
  r[0].m[1][0] = r[1].m[2][1] = r[2].m[0][2] = 1, r[5].m[2][2] = 0;
  while (q--){
    int op = read(), x = read(), y = read();
    if (op <= 3) chg(1, 1, n, x, y, r[op - 1]);
    else if (op <= 6){
      r[3].m[3][0] = r[4].m[1][1] = r[5].m[3][2] = read();
      chg(1, 1, n, x, y, r[op - 1]);
    }
    else{
      mat k = qry(1, 1, n, x, y);
      printf("%d %d %d\n", k.m[0][0], k.m[0][1], k.m[0][2]);
    }
  }
  return 0;
}

