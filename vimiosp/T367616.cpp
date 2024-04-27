#include <iostream>
#include <algorithm>

using namespace std;
const int N = 2005, K = 15;
int n, m, a[N][N], t[K];
long long ans;
int f(int y, int x){
  int b = a[y][x], c = 0;
  c += (a[y - 1][x] == b);
  c += (a[y][x - 1] == b);
  return c;
}

int main(){
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      scanf("%d", &a[i][j]);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++){
      ans = ans + t[a[i][j]] - f(i, j);
      t[a[i][j]]++;
    }
  printf("%lld", ans * 2ll);
  return 0;
}
