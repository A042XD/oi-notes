#include <iostream>
#include <algorithm>

using namespace std;
const int N = 105;
int n, q, dp[N][N], sz[N], w[N];
struct gph{
  int to[N * 2], nx[N * 2], w[N * 2], hd[N], tot;
  void add(int u, int v, int k){to[++tot] = v, nx[tot] = hd[u], hd[u] = tot, w[tot] = k;}
}g;
void dfs(int x, int f){
  sz[x] = 1;
  for (int i = g.hd[x]; i; i = g.nx[i])
    if (g.to[i] != f){
      dfs(g.to[i], x), sz[x] += sz[g.to[i]];
      for (int j = min(sz[x], q); j; j--)
        for (int k = min(sz[g.to[i]], j - 1); ~k; k--)
          dp[x][j] = max(dp[x][j], dp[x][j - k - 1] + dp[g.to[i]][k] + g.w[i]);
    }
}

int main(){
  scanf("%d %d", &n, &q);
  for (int i = 1, u, v, k; i < n; i++)
    scanf("%d %d %d", &u, &v, &k), g.add(u, v, k), g.add(v, u, k);
  dfs(1, 1);
  printf("%d", dp[1][q]);
  return 0;
}
