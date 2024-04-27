#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
const int N = 1e3 + 5;
int n, t, s, e, tot, r[N];
struct mat{
  int x, y, m[235][235]; 
  void sz(int a, int b){y = a, x = b;}
  friend mat operator*(mat a, mat b){
    mat c; c.sz(a.y, b.x); memset(c.m, 0x3f3f3f3f, sizeof(c.m));
    for (int i = 1; i <= a.y; i++)
      for (int j = 1; j <= b.x; j++)
        for (int k = 1; k <= a.x; k++)
          c.m[i][j] = min(c.m[i][j], a.m[i][k] + b.m[k][j]);
    return c;
  }
}d, ans;
void pow(int k){
  ans = d; k--;
  while (k){
    if (k & 1) ans = ans * d;
    d = d * d; k /= 2;
  }
}

int main(){
  scanf("%d %d %d %d", &n, &t, &s, &e);
  memset(d.m, 0x3f3f3f3f, sizeof(d.m));
  for (int i = 1, u, v, w; i <= t; i++){
    scanf("%d %d %d", &w, &u, &v);
    if (!r[u]) r[u] = ++tot;
    if (!r[v]) r[v] = ++tot;
    d.m[r[u]][r[v]] = d.m[r[v]][r[u]] = w;
  }
  d.sz(tot, tot); pow(n);
  printf("%d", ans.m[r[s]][r[e]]);
  return 0;
}
