#include <iostream>
#include <algorithm>

using namespace std;
const int N = 6005;
int n, rt, a[N], in[N], dp[N][2];
struct gph{
  int to[N], nx[N], hd[N], tot;
  void add(int u, int v){to[++tot] = v, nx[tot] = hd[u], hd[u] = tot;}
}g;
void dfs(int x, int f){
  dp[x][1] = a[x];
  for (int i = g.hd[x]; i; i = g.nx[i])
    if (g.to[i] != f){
      dfs(g.to[i], x);
      dp[x][1] += dp[g.to[i]][0], dp[x][0] += max(dp[g.to[i]][1], dp[g.to[i]][0]);
    }
}

int main(){
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1, u, v; i < n; i++) scanf("%d %d", &u, &v), g.add(v, u), in[u]++;
  for (int i = 1; i <= n; i++) rt = !in[i] ? i : rt;
  dfs(rt, rt);
  printf("%d", max(dp[rt][0], dp[rt][1]));
  return 0;
}
