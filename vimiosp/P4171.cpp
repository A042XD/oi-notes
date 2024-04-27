#include <iostream>
#include <algorithm>

using namespace std;
const int N = 205, M = 2005;
int t, n, m, dfx, tot, tp, s[N], b[N], dfn[N], low[N];
bool v[N];
struct gph{
  int to[M], nx[M], hd[N], t;
  void add(int u, int v){to[++t] = v, nx[t] = hd[u], hd[u] = t;}
}g;
void trjn(int u){
  dfn[u] = low[u] = ++dfx; s[++tp] = u, v[u] = 1;
  for (int i = g.hd[u]; i; i = g.nx[i])
    if (!dfn[g.to[i]]) trjn(g.to[i]), low[u] = min(low[u], low[g.to[i]]);
    else if (v[g.to[i]]) low[u] = min(low[u], dfn[g.to[i]]);
  if (low[u] != dfn[u]) return;
  tot++;
  do v[u] = 0, b[u] = tot, u = s[tp--]; while (low[u] != dfn[u]);
}

int main(){
  scanf("%d", &t);
  while (t--){
    scanf("%d %d", &n, &m); bool f = 1;
    for (int x, a, y, b, i = 1; i <= m; i++){
      x = y = a = b = 0;
      char s[5]; int l = 1; scanf("%s", s);
      if (s[0] == 'm') a = 1;
      while (s[l] != '\0') x = x * 10 + s[l] - 48, l++;
      l = 1, scanf("%s", s);
      if (s[0] == 'm') b = 1;
      while (s[l] != '\0') y = y * 10 + s[l] - 48, l++;
      g.add(x + (a & 1) * n, y + (b ^ 1) * n);
      g.add(y + (b & 1) * n, x + (a ^ 1) * n);
    }
    for (int i = 1; i <= n * 2; i++) if (!dfn[i]) trjn(i);
    for (int i = 1; i <= n; i++)
      if (b[i] == b[i + n]) f = 0;
    puts(f ? "GOOD" : "BAD");
    g.t = tot = tp = dfx = 0;
    for (int i = 1; i <= 200; i++) g.hd[i] = dfn[i] = low[i] = v[i] = 0;
  }
  return 0;
}
