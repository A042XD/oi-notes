#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
const int N = 1e5 + 5;
int n, m;
struct gph{
  int to[N * 2], nx[N * 2], hd[N * 2], tot;
  void add(int u, int v){to[++tot] = v, nx[tot] = hd[u], hd[u] = tot;}
}g;
void dfs1(int x, int f){
  
}
void dfs2(int x, int f){

}

int main(){
  scanf("%d %d", &n, &m);
  for (int i = 1, u, v, w; i <= n; i++)
    scanf("%d %d %d", &u, &v, &w), g.add(u, v, w), g.add(v, u, w);
  return 0;
}
