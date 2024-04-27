#include <iostream>
#include <algorithm>
#include <cstring>
#define int long long

using namespace std;
const int N = 5005;
int n, v[N], s[N], dp[N][N];
//int abs(int a){return a < 0 ? -a : a;}

signed main(){
  scanf("%lld", &n);
  for (int i = 1; i <= n; i++) scanf("%lld", &v[i]);
  printf("0 "); memset(s, 0x3f, sizeof(s));
  for (int l = 2; l <= n; l++)
    for (int a = 1, b = l; a + l - 1 <= n; b = (++a) + l - 1)
      dp[a][b] = dp[a + 1][b - 1] + abs(v[a] - v[b]), s[l] = min(s[l], dp[a][b]);
  for (int i = 2; i <= n; i++) printf("%lld ", s[i]);
  return 0;
}
