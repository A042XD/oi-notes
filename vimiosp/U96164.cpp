#include <iostream>
#include <algorithm>

using namespace std;
const int N = 20005;
int n, ans[N], sz[N], ctd[2];
struct gph{
  int to[N * 2], nx[N * 2], hd[N], tot;
  void add(int u, int v){to[++tot] = v, nx[tot] = hd[u], hd[u] = tot;}
}g;
void gtctd(int x, int f){
  int w = 0; sz[x] = 1;
  for (int i = g.hd[x]; i; i = g.nx[i])
    if (g.to[i] != f){
      gtctd(g.to[i], x), w = max(w, sz[g.to[i]]);
      ans[x] = max(ans[x], sz[g.to[i]]), sz[x] += sz[g.to[i]];
    }
  w = max(w, n - sz[x]), ans[x] = max(ans[x], n - sz[x]);
  if (w <= n / 2) ctd[ctd[0] != 0] = x;
}

int main(){
  scanf("%d", &n);
  for (int i = 1, u, v; i < n; i++) scanf("%d %d", &u, &v), g.add(u, v), g.add(v, u);
  gtctd(1, 1), printf("%d", max(ans[ctd[0]], ans[ctd[1]]));
  return 0;
}
