#include <iostream>
#include <algorithm>
#define int long long

using namespace std;
const int N = 1e6 + 5;
int n, ans, dep[N], sz[N], dp[N];
struct gph{
  int to[N * 2], nx[N * 2], hd[N], tot;
  void add(int u, int v){to[++tot] = v, nx[tot] = hd[u], hd[u] = tot;}
}g;
void dfs1(int x, int f){
  sz[x] = 1, dep[x] = dep[f] + 1, dp[1] += dep[x];
  for (int i = g.hd[x]; i; i = g.nx[i])
    if (g.to[i] != f) dfs1(g.to[i], x), sz[x] += sz[g.to[i]];
}
void dfs2(int x, int f){
  for (int i = g.hd[x]; i; i = g.nx[i])
    if (g.to[i] != f) 
      dp[g.to[i]] = dp[x] - sz[g.to[i]] + n - sz[g.to[i]], dfs2(g.to[i], x);
}

signed main(){
  scanf("%lld", &n);
  for (int i = 1, u, v; i < n; i++) scanf("%lld %lld", &u, &v), g.add(u, v), g.add(v, u);
  dfs1(1, 1), dfs2(1, 1);
  for (int i = 1; i <= n; i++) if (dp[ans] < dp[i]) ans = i;
  printf("%lld", ans);
  return 0;
}
