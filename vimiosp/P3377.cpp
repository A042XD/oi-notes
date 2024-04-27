#include <iostream>
#include <algorithm>

using namespace std;
const int N = 1e5 + 5;
int n, m, tot, l[N], r[N], v[N], id[N], dis[N], f[N];
bool d[N];
bool cmp(int x, int y){return v[x] != v[y] ? v[x] < v[y] : id[x] < id[y];}
int find(int x){return f[x] == x ? x : f[x] = find(f[x]);}
void crt(int x, int p){v[++tot] = x, id[tot] = p, dis[tot] = 1, f[tot] = tot;}
int merge(int x, int y){
  if (!x || !y) return x + y;
  if (cmp(y, x)) swap(x, y);
  r[x] = merge(r[x], y);
  if (dis[r[x]] > dis[l[x]]) swap(r[x], l[x]);
  dis[x] = dis[r[x]] + 1;
  return x;
}
void del(int x){
  if (d[x]) return;
  f[l[x]] = f[r[x]] = f[x] = merge(l[x], r[x]);
  l[x] = r[x] = dis[x] = 0, d[x] = 1;
}

int main(){
  scanf("%d %d", &n, &m), dis[0] = -1;
  for (int i = 1, x; i <= n; i++) scanf("%d", &x), crt(x, i);
  for (int i = 1, op, x, y; i <= m; i++){
    scanf("%d %d", &op, &x);
    if (op == 1){
      scanf("%d", &y);
      if (d[x] || d[y]) continue;
      if ((x = find(x)) != (y = find(y))) f[x] = f[y] = merge(x, y);
    }
    else{
      if (d[x]){ puts("-1"); continue;}
      x = find(x), printf("%d\n", v[x]), del(x);
    }
  }
  return 0;
}
