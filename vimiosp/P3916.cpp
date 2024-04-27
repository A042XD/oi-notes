#include <iostream>
#include <algorithm>

using namespace std;
const int N = 1e5 + 5;
int n, m, d[N];
struct gph{
  int to[N], nx[N], hd[N], tot;
  void add(int u, int v){to[++tot] = v, nx[tot] = hd[u], hd[u] = tot;}
}g;
void dfs(int x, int a){
  if (d[x]) return;
  d[x] = a;
  for (int i = g.hd[x]; i; i = g.nx[i])
    dfs(g.to[i], a);
}

int main(){
  scanf("%d %d", &n, &m);
  for (int i = 1, u, v; i <= m; i++) scanf("%d %d", &u, &v), g.add(v, u);
  for (int i = n; i; i--) dfs(i, i);
  for (int i = 1; i <= n; i++) printf("%d ", d[i]);
  return 0;
}
