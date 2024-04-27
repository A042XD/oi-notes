#include <iostream>
#include <algorithm>

using namespace std;
const int N = 10005, M = 50005;
int n, s, q, ans[N], sz[N];
struct gph{
  int to[M * 2], nx[M * 2], hd[N], tot;
  void add(int u, int v){to[++tot] = v, nx[tot] = hd[u], hd[u] = tot;}
}g;
void dfs(int u, int f){
  int sum = 0;
  for (int i = g.hd[u]; i; i = g.nx[i])
    if (g.to[i] != f){
      dfs(g.to[i], u);
      ans[u] += sz[u] * sz[g.to[i]] * 2, sz[u] += sz[g.to[i]];
    }
  ans[u] += 1 + sz[u] * 2, sz[u] += 1;
}

int main(){
  scanf("%d %d %d", &n, &s, &q);
  for (int i = 1, u, v; i < n; i++) scanf("%d %d", &u, &v), g.add(u, v), g.add(v, u);
  dfs(s, s);
  for (int x; q--;) scanf("%d", &x), printf("%d\n", ans[x]);
  return 0;
}
