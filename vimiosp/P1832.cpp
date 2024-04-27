#include <iostream>
#include <algorithm>
#define int long long

using namespace std;
const int N = 1e3 + 5;
int n, cnt, p[N], dp[N];
bool v[N];

signed main(){
  scanf("%lld", &n), v[1] = 1;
  for (int i = 2; i <= n; i++){
    if (!v[i]) p[++cnt] = i;
    for (int j = 1; j <= cnt && i * p[j] <= n; j++){
      v[i * p[j]] = 1;
      if (i == p[j]) break;
    }
  }
  dp[0] = 1;
  for (int i = 2; i <= n; i++)
    if (!v[i])
      for (int j = i; j <= n; j++)
        dp[j] += dp[j - i];
  printf("%lld", dp[n]);
  return 0;
}
