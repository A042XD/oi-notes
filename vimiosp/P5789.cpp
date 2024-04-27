#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
const int N = 105, p = 2017;
int n, m, t;
struct mat{
  int m[N][N];
  mat(){memset(m, 0, sizeof(m));}
  friend mat operator*(mat a, mat b){
    mat c;
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++)
        for (int k = 1; k <= n; k++)
          c.m[i][j] = (c.m[i][j] + a.m[i][k] * b.m[k][j] % p) % p;
    return c;
  }
}d, r;
mat pow(mat a, int k){
  mat t = a; k--;
  while (k){
    if (k & 1) t = t * a;
    a = a * a, k /= 2;
  }
  return t;
}

int main(){
  scanf("%d %d", &n, &m); n++;
  for (int i = 1, u, v; i <= m; i++)
    scanf("%d %d", &u, &v), d.m[u][v] = d.m[v][u] = 1;
  for (int i = 1; i <= n; i++) d.m[i][i] = d.m[i][n] = 1;
  r.m[1][1] = 1;
  scanf("%d", &t), d = r * pow(d, t); int ans = 0;
  for (int i = 1; i <= n; i++) ans = (ans + d.m[1][i]) % p;
  printf("%d", ans);
  return 0;
}
