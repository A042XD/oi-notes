#include <iostream>

using namespace std;
const int N = 1e3 + 5;
int n, x;
long long dp[N];

int main(){
  scanf("%d %d", &n, &x);
  for (int i = 1, w, l, v; i <= n; i++){
    scanf("%d %d %d", &l, &w, &v);
    for (int j = x; j >= 0; j--)
      if (j >= v) dp[j] = max(dp[j] + l, dp[j - v] + w);
      else dp[j] = dp[j] + l;
  }
  printf("%lld", 5 * dp[x]);
  return 0;
}
