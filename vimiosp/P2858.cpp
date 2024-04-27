#include <iostream>
#include <algorithm>

using namespace std;
const int N = 2005;
int n, v[N], dp[N][N];

int main(){
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &v[i]);
  for (int l = 1; l <= n; l++)
    for (int i = 1; i + l - 1 <= n; i++){
      int a = i, b = i + l - 1;
      dp[a][b] = max(dp[a + 1][b] + v[a] * (n - l + 1), dp[a][b - 1] + v[b] * (n - l + 1));
    }
  printf("%d", dp[1][n]);
  return 0;
}
