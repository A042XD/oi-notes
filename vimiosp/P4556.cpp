#include <iostream>
#include <algorithm>
#define mid ((cl + cr) / 2)

using namespace std;
const int K = 17, N = 1e5 + 5, T = N * 60;
int n, m, dfx, dfn[N], ans[N], fa[N], dep[N], lg[N], st[N][K], tot, r[N], v[T], mx[T], c[T][0];
struct gph{
  int to[N * 2], nx[N * 2], hd[N], tot;
  void add(int u, int v){to[++tot] = v, nx[tot] = hd[u], hd[u] = tot;}
}g;
void dfs1(int x, int f){
  dep[x] = dep[fa[x] = f] + 1, st[dfn[x] = ++dfx][0] = x;
  for (int i = g.hd[x]; i; i = g.nx[i])
    if (g.to[i] != fa) dfs1(g.to[i], x);
}
int get(int x, int y){return dep[x] < dep[y] ? x : y;}
int lca(int x, int y){
  if (x == y) return x;
  if ((x = dfn[x]) > (y = dfn[y])) swap(x, y);
  int l = lg[y - (++x) + 1];
  return get(mi[x][l], mi[y - (1 << l) + 1][l]);
}
void push(int x){
  v[x] = max(v[c[x][0]], v[c[x][1]]);
  mx[x] = v[x] == v[c[x][0]] ? mx[c[x][0]] : mx[c[x][1]];
}
void chg(int &u, int cl, int cr, int p, int x){
  if (!x) x = ++tot;
  if (cl >= cr) return v[u] += x, mx[u] = p, void();
  if (p <= mid) chg(c[x][0], )
}
int mrg(int x, int y, int cl, int cr){
  if (!x || !y) return x + y;
  if (cl >= cr) return v[x] += v[y], mx[x] = l, x;
  c[x][0] = mrg(c[x][0], c[y][0], cl, mid), c[x][1] = mrg(c[x][1], c[y][1], mid + 1, cr);
  return push(x), x;
}
void dfs2(int x, int f){
  for (int i = g.hd[x]; i; i = g.nx[i])
    if (g.to[i] != f) dfs2(g.to[i], x), r[x] = mrg(1, N, )
}

int main(){
  scanf("%d %d", &n, &m);
  for (int i = 2; i <= n; i++) lg[i] = lg[i / 2] + 1;
  for (int i = 1, u, v; i < n; i++) scanf("%d %d", &u, &v), g.add(u, v), g.add(v, u);
  dfs1(1, 1);
  for (int p = 1; p <= lg[n]; p++)
    for (int i = 1; i <= n - (1 << p) + 1; i++)
      st[i][p] = get(st[i][p - 1], st[i + (1 << p - 1)][p - 1]);
  for (int i = 1; i <= m; i++){

  }
  dfs2(1, 0);
  for (int i = 1; i <= n; i++) printf("%d\n", ans[i]);
  return 0;
}
