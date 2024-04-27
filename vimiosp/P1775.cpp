#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
const int N = 305;
int n, dp[N][N], m[N][N], s[N];

int main(){
  scanf("%d", &n); memset(dp, 0x3f, sizeof(dp));
  for (int i = 1; i <= n; i++) scanf("%d", &s[i]), s[i] += s[i - 1], dp[i][i] = 0, m[i][i] = i;
  for (int l = 2; l <= n; l++)
    for (int j = 1; j + l - 1 <= n; j++){
      int a = j, b = j + l - 1;
      for (int k = m[a][b - 1]; k <= m[a + 1][b]; k++){
        int t = dp[a][k] + dp[k + 1][b] + s[b] - s[a - 1];
        if (dp[a][b] > t){
          dp[a][b] = t;
          m[a][b] = k;
        }
      }
    }
  printf("%d", dp[1][n]);
  return 0;
}
