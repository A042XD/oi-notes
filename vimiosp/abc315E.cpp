#include <iostream>
#include <algorithm>

using namespace std;
const int N = 2e5 + 5;
int n;
bool v[N];
struct graph{
  int to[N * 20], nx[N * 20], hd[N], tot;
  void add(int u, int v){to[++tot] = v, nx[tot] = hd[u], hd[u] = tot;}
}g;
void dfs(int x){
  if (v[x]) return;
  for (int i = g.hd[x]; i; i = g.nx[i])
    dfs(g.to[i]);
  if (!v[x] && x != 1) printf("%d ", x);
  v[x] = 1;
}

int main(){
  scanf("%d", &n);
  for (int i = 1, c; i <= n; i++){
    scanf("%d", &c);
    for (int j = 1, v; j <= c; j++) scanf("%d", &v), g.add(i, v);
  }
  dfs(1);
  return 0;
}
