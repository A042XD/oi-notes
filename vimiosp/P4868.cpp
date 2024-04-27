#include <iostream>
#include <algorithm>
#define mid ((cl + cr) / 2)
#define inr (l <= cl && cr <= r)
#define outr (cr < l || r < cl)
#define int long long

using namespace std;
const int N = 1e5 + 5;
int n, m, c[N], a[N], t[4 * N], lz[4 * N];
char s[N];
void mktg(int u, int len, int x){lz[u] += x, t[u] += len * x;}
void psdn(int u, int cl, int cr){
  mktg(u * 2, mid - cl + 1, lz[u]);
  mktg(u * 2 + 1, cr - mid, lz[u]);
  lz[u] = 0;
}
void bld(int u, int cl, int cr){
  if (cl >= cr) return t[u] = c[cl], void();
  bld(u * 2, cl, mid), bld(u * 2 + 1, mid + 1, cr);
  t[u] = t[u * 2] + t[u * 2 + 1];
}
void chg(int u, int cl, int cr, int l, int r, int x){
  if inr return mktg(u, cr - cl + 1, x), void();
  if outr return void();
  psdn(u, cl, cr);
  chg(u * 2, cl, mid, l, r, x), chg(u * 2 + 1, mid + 1, cr, l, r, x);
  t[u] = t[u * 2] + t[u * 2 + 1];
}
int qry(int u, int cl, int cr, int l, int r){
  if inr return t[u];
  if outr return 0;
  psdn(u, cl, cr);
  return qry(u * 2, cl, mid, l, r) + qry(u * 2 + 1, mid + 1, cr, l, r);
}

signed main(){
  scanf("%lld %lld", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%lld", &a[i]), c[i] = a[i] + c[i - 1];
  bld(1, 1, n);
  for (int x, y; m--; ){
    scanf("%s %lld", s, &x);
    if (s[0] == 'Q') printf("%lld\n", qry(1, 1, n, 1, x));
    else{
      scanf("%lld", &y);
      chg(1, 1, n, x, n, y - a[x]);
      a[x] = y;
    }
  }
  return 0;
}
