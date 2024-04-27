#include <iostream>
#include <algorithm>
#define int long long
#define mid ((cl + cr) / 2)
#define inRange (l <= cl && cr <= r)
#define outRange (cr < l || r < cl)

using namespace std;
const int N = 1e6 + 5;
int n, m, a[N], d[N * 4], lz[N * 4], ls[N * 4];
bool ks[N * 4];

void pushup(int u){d[u] = max(d[u * 2], d[u * 2 + 1]);}
void build(int u, int cl, int cr){
  if (cl >= cr) return d[u] = a[cl], void();
  build(u * 2, cl, mid), build(u * 2 + 1, mid + 1, cr);
  pushup(u);
}
void tags(int u, int x){
  ks[u] = 1, lz[u] = 0;
  ls[u] = x, d[u] = x;
}
void taga(int u, int x){
  lz[u] += x, d[u] += x;
}
void pushDown(int u){
  if (ks[u]) tags(u * 2, ls[u]), tags(u * 2 + 1, ls[u]), ls[u] = ks[u] = 0;
  taga(u * 2, lz[u]), taga(u * 2 + 1, lz[u]), lz[u] = 0;
}
void set(int u, int cl, int cr, int l, int r, int x){
  if (inRange) return tags(u, x), void();
  if (outRange) return;
  pushDown(u);
  set(u * 2, cl, mid, l, r, x), set(u * 2 + 1, mid + 1, cr, l, r, x);
  pushup(u);
}
void add(int u, int cl, int cr, int l, int r, int x){
  if (inRange) return taga(u, x), void();
  if (outRange) return;
  pushDown(u);
  add(u * 2, cl, mid, l, r, x), add(u * 2 + 1, mid + 1, cr, l, r, x);
  pushup(u);
}
int query(int u, int cl, int cr, int l, int r){
  if (inRange) return d[u];
  if (outRange) return -1e18;
  pushDown(u);
  return max(query(u * 2, cl, mid, l, r), query(u * 2 + 1, mid + 1, cr, l, r));
}
signed main(){
  scanf("%lld %lld", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
  build(1, 1, n);
  for (int i = 1, op, l, r, x; i <= m; i++){
    scanf("%lld %lld %lld", &op, &l, &r);
    if (op == 3) printf("%lld\n", query(1, 1, n, l, r));
    else{
      scanf("%lld", &x);
      if (op == 1) set(1, 1, n, l, r, x);
      else add(1, 1, n, l, r, x);
    }
  }
  return 0;
}
