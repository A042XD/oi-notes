#include <iostream>
#include <cstring>
#define int long long

using namespace std;
int len, l, r, a[15], dp[15][15];
int dfs(int c, int p, int s, int l){
  if (c > len) return 1;
  if (!l && dp[c][p] != -1) return dp[c][p];
  int ans = 0, rs = l ? a[len - c + 1] : 9;
  for (int i = 0; i <= rs; i++){
    if (abs(i - p) < 2) continue;
    if (s && i == 0) ans += dfs(c + 1, -2, 1, l && i == rs);
    else ans += dfs(c + 1, i, 0, l && i == rs);
  }
  if (!l && !s) dp[c][p] = ans;
  return ans;
}
int get(int x){
  len = 0;
  while (x) a[++len] = x % 10, x /= 10;
  memset(dp, -1, sizeof(dp)); 
  return dfs(1, -2, 1, 1);
}

signed main(){ 
  scanf("%lld %lld", &l, &r);
  printf("%lld", get(r) - get(l - 1));
  return 0;
}
