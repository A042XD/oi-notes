#include <iostream>
#include <algorithm>

using namespace std;
const int N = 5e5 + 5;
int n, ans;
struct gph{
  int to[N * 2], nx[N * 2], w[N * 2], hd[N], tot;
  void add(int u, int v, int k){to[++tot] = v, nx[tot] = hd[u], hd[u] = tot, w[tot] = k;}
}g;
int dfs(int x, int f){
  int d1 = 0, d2 = 0;
  for (int i = g.hd[x], t; i; i = g.nx[i])
    if (g.to[i] != f){
      t = dfs(g.to[i], x) + g.w[i]; 
      if (t > d1) d2 = d1, d1 = t;
      else if (t > d2) d2 = t;
    }
  return ans = max(ans, d1 + d2), d1;
}

int main(){
  scanf("%d", &n);
  for (int i = 1, u, v, k; i < n; i++) 
    scanf("%d %d %d", &u, &v, &k), g.add(u, v, k), g.add(v, u, k);
  dfs(1, 1), printf("%d", ans);
  return 0;
}
