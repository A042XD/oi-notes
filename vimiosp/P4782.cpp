#include <iostream>
#include <algorithm>

using namespace std;
const int N = 2e6 + 5, M = N * 2;
int n, m, dfx, tp, tot, s[N], dfn[N], low[N], b[N];
bool v[N];
struct gph{
  int to[M], nx[M], hd[N], t;
  void add(int u, int v){to[++t] = v, nx[t] = hd[u], hd[u] = t;}
}g;
void trjn(int u){
  dfn[u] = low[u] = ++dfx, v[u] = 1, s[++tp] = u;
  for (int i = g.hd[u]; i; i = g.nx[i])
    if (!dfn[g.to[i]]) trjn(g.to[i]), low[u] = min(low[u], low[g.to[i]]);
    else if (v[g.to[i]]) low[u] = min(low[u], dfn[g.to[i]]);
  if (low[u] != dfn[u]) return;
  tot++;
  do b[u] = tot, v[u] = 0, u = s[tp--]; while (low[u] != dfn[u]);
}

int main(){
  scanf("%d %d", &n, &m);
  for (int i = 1, x, y, a, b; i <= m; i++){
    scanf("%d %d %d %d", &x, &a, &y, &b);
    g.add(x + (a & 1) * n, y + (b ^ 1) * n);
    g.add(y + (b & 1) * n, x + (a ^ 1) * n);
  }
  for (int i = 1; i <= 2 * n; i++) if (!dfn[i]) trjn(i);
  for (int i = 1; i <= n; i++)
    if (b[i] == b[i + n]) puts("IMPOSSIBLE"), exit(0);
  puts("POSSIBLE");
  for (int i = 1; i <= n; i++)
    printf("%d ", b[i] < b[i + n]);
  return 0;
}
