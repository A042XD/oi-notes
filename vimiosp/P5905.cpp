#include <iostream>
#include <algorithm>
#include <queue>
#define int long long
#define pii pair<int, int>

using namespace std;
const int N = 3005, M = 6005;
int n, m, h[N], dis[N];
struct gph{
  int to[M], nx[M], w[M], hd[N], tot;
  void add(int u, int v, int k){to[++tot] = v, nx[tot] = hd[u], hd[u] = tot, w[tot] = k;}
}g;

signed main(){
  scanf("%lld %lld", &n, &m);
  for (int i = 1, u, v, w; i <= m; i++) scanf("%lld %lld %lld", &u, &v, &w), g.add(u, v, w);
  for (int i = 1; i <= n; i++){
    bool f = 0;
    for (int j = 1; j <= n; j++)
      for (int k = g.hd[j]; k; k = g.nx[k])
        if (h[g.to[k]] > h[j] + g.w[k])
          h[g.to[k]] = h[j] + g.w[k], f = 1;
    if (i == n && f) puts("-1"), exit(0);
  }
  for (int i = 1; i <= n; i++){
    for (int j = 1; j <= n; j++) dis[j] = 1e9;
    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.push(make_pair(dis[i] = 0, i));
    while (q.size()){
      int d = q.top().first, u = q.top().second;
      q.pop();
      if (d != dis[u]) continue;
      for (int j = g.hd[u]; j; j = g.nx[j]){
        int cd = d + g.w[j] + h[u] - h[g.to[j]];
        if (cd < dis[g.to[j]]) q.push(make_pair(dis[g.to[j]] = cd, g.to[j]));
      }
    }
    int ans = 0;
    for (int j = 1; j <= n; j++) ans += j * (dis[j] + (dis[j] < 1e9 ? h[j] - h[i] : 0));
    printf("%lld\n", ans);
  }
  return 0;
}
