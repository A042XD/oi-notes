#include <iostream>
#include <algorithm>

using namespace std;
const int N = 1e5 + 5;
int n, m;
struct gph{
  int to[N * 2], nx[N * 2], hd[N], tot;
  void add(int u, int v){to[++tot] = v, nx[tot] = hd[u], hd[u] = tot;}
}g;


int main(){
  scanf("%d", &n);
  for (int i = 1, u, v; i < n; i++) scanf("%d %d", &u, &v), g.add(u, v), g.add(v, u);
  scanf("%d", &m);
  for (int i = 1, x; i <= n; i++){
    scanf("%d", &x);
    for (int j = 1; j <= n; j++);
  }
  return 0;
}
