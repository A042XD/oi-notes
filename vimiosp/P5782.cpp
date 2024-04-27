#include <iostream>
#include <algorithm>

using namespace std;
const int N = 2e4 + 5, M = 4e4 +5;
int n, m, dfx, tp, tot, s[N], b[N], dfn[N], low[N];
bool v[N];
struct gph{
  int to[M], nx[M], hd[N], t;
  void add(int u, int v){to[++t] = v, nx[t] = hd[u], hd[u] = t;}
}g;
int f(int x){return x & 1 ? x + 1 : x - 1;}
void trjn(int u){
  dfn[u] = low[u] = ++dfx, v[u] = 1, s[++tp] = u;
  for (int i = g.hd[u]; i; i = g.nx[i])
    if (!dfn[g.to[i]]) trjn(g.to[i]), low[u] = min(low[u], low[g.to[i]]);
    else if (v[g.to[i]]) low[u] = min(low[u], dfn[g.to[i]]);
  if (low[u] != dfn[u]) return;
  tot++;
  do v[u] = 0, b[u] = tot, u = s[tp--]; while(low[u] != dfn[u]);
}

int main(){
  scanf("%d %d", &n, &m);
  for (int i = 1, x, y; i <= m; i++){
    scanf("%d %d", &x, &y);
    g.add(x, f(y));
    g.add(y, f(x));
  }
  for (int i = 1; i <= 2 * n; i++) if (!dfn[i]) trjn(i);
  for (int i = 1; i <= 2 * n; i += 2)
    if (b[i] == b[i + 1]) puts("NIE"), exit(0);
  for (int i = 1; i <= 2 * n; i += 2)
    printf("%d\n", b[i] > b[i + 1] ? i + 1 : i); 
  return 0;
}
