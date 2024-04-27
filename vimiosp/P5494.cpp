#include <iostream>
#include <algorithm>
#define int long long
#define mid ((cl + cr) / 2)
#define inr (l <= cl && cr <= r)
#define outr (cr < l || r < cl)

using namespace std;
const int N = 3e5 + 5;
int n, m, cnt, seq = 1, tot, g[N * 5], c[N * 5][2], rt[N], val[N * 5];
int crt(){return cnt ? g[cnt--] : ++tot;}
void del(int u){c[u][0] = c[u][1] = val[u] = 0, g[++cnt] = u;}
void chg(int &u, int cl, int cr, int p, int v){
  if (!u){u = crt();}
  val[u] += v;
  if (cl >= cr) return;
  if (p <= mid) chg(c[u][0], cl, mid, p, v);
  else chg(c[u][1], mid + 1, cr, p, v);
}
int qry(int u, int cl, int cr, int l, int r){
  if inr return val[u];
  if outr return 0;
  return qry(c[u][0], cl, mid, l, r) + qry(c[u][1], mid + 1, cr, l, r);
}
int kth(int u, int cl, int cr, int k){
  if (cl >= cr) return cl;
  if (val[c[u][0]] >= k) return kth(c[u][0], cl, mid, k);
  return kth(c[u][1], mid + 1, cr, k - val[c[u][0]]);
}
int mrg(int x, int y){
  if (!x || !y) return x + y;
  val[x] += val[y];
  c[x][0] = mrg(c[x][0], c[y][0]);
  c[x][1] = mrg(c[x][1], c[y][1]);
  return del(y), x;
}
void split(int x, int &y, int k){
  if (!x) return;
  int v = val[c[x][0]]; y = crt();
  if (k > v) split(c[x][1], c[y][1], k - v);
  else swap(c[x][1], c[y][1]);
  if (k < v) split(c[x][0], c[y][0], k);
  val[y] = val[x] - k, val[x] = k;
}

signed main(){
  scanf("%lld %lld", &n, &m);
  for (int i = 1, x; i <= n; i++) scanf("%lld", &x), chg(rt[1], 1, n, i, x);
  for (int op, x, y, z, i = 1; i <= m; i++){
    scanf("%lld %lld %lld", &op, &x, &y);
    if (op == 0){
      scanf("%lld", &z);
      int k1 = qry(rt[x], 1, n, 1, z), k2 = qry(rt[x], 1, n, y, z), tmp = 0;
      split(rt[x], rt[++seq], k1 - k2);
      split(rt[seq], tmp, k2);
      rt[x] = mrg(rt[x], tmp);
    }
    else if (op == 1) rt[x] = mrg(rt[x], rt[y]);
    else if (op == 2) scanf("%lld", &z), chg(rt[x], 1, n, z, y);
    else if (op == 3) scanf("%lld", &z), printf("%lld\n", qry(rt[x], 1, n, y, z));
    else if (op == 4){
      if (val[rt[x]] < y){puts("-1"); continue;}
      printf("%lld\n", kth(rt[x], 1, n, y));
    }
  }
  return 0;
}
