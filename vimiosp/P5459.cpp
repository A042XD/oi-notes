#include <iostream>
#include <algorithm>
#define int long long
#define mid ((cl + cr) / 2)
#define inr (l <= cl && cr <= r)
#define outr (cr < l || r < cl)

using namespace std;
const int N = 1e5 + 5, D = 2e7 + 5, K = 1e10;
int n, l, r, rt, ans, tot, p[N], a[N], ls[D], rs[D], t[D];
int crt(){return ls[++tot] = rs[tot] = t[tot] = 0, tot;}
void change(int u, int cl, int cr, int p, int v){
  if (cl >= cr) return t[u] += v, void();
  if (p <= mid) (ls[u] = ls[u] ? ls[u] : crt()), change(ls[u], cl, mid, p, v);
  else (rs[u] = rs[u] ? rs[u] : crt()), change(rs[u], mid + 1, cr, p, v);
  t[u] = t[ls[u]] + t[rs[u]];
}
int query(int u, int cl, int cr, int l, int r){
  if inr return t[u];
  if outr return 0;
  int ans = 0;
  if (cl <= mid) (ls[u] = ls[u] ? ls[u] : crt()), ans += query(ls[u], cl, mid, l, r);
  else (rs[u] = rs[u] ? rs[u] : crt()), ans += query(rs[u], mid + 1, cr, l, r);
  return ans;
}

signed main(){
  scanf("%lld %lld %lld", &n, &l, &r);
  rt = crt(), change(rt, -K, K, 0, 1);
  for (int i = 1; i <= n; i++) scanf("%lld", &a[i]), p[i] = p[i - 1] + a[i];
  for (int i = 1; i <= n; i++){
    ans += query(rt, -K, K, p[i] - r, p[i] - l);
    change(rt, -K, K, p[i], 1);
  }
  printf("%lld", ans);
  return 0;
}
