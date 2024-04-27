#include <iostream>
#include <algorithm>

using namespace std;
const int N = 1e5 + 5, M = 3e5 + 5;
int n, m, f[N];
struct rl{int a, b, x;}e[M];
struct gph{
  int to[M], nx[M], hd[N], tot;
  void add(int u, int v){to[++tot] = v, nx[tot] = hd[u], hd[u] = tot;} 
};
int fd(int x){return x == f[x] ? x : f[x] = fd(f[x]);}
void mrg(int x, int y){if ((x = fd(x)) != (y = fd(y))) f[x] = y;}

int main(){
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) f[i] = i;
  for (int i = 1; i <= m; i++) scanf("%d %d %d", &e[i].a, &e[i].b, &e[i].x);
  sort(e + 1, e + m + 1, [](rl a, rl b){return a.x < b.x;});
  for (int i = 1; i <= m; i++)
    if (fd(e[i].a) != fd(e[i].b)) mrg(e[i].a, e[i].b)
  return 0;
}
