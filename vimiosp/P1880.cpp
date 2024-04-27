#include <iostream>
#include <cstring>

using namespace std;
const int N = 205;
int n, a[N], sum[N], dp[2][N][N], p[2][N][N];

int main(){
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]), a[i + n] = a[i];
  n *= 2;
  for (int i = 1; i <= n; i++) 
    sum[i] = sum[i - 1] + a[i], p[0][i][i] = i;
  for (int l = 2; l <= n; l++)
    for (int i = 1; i <= n - l + 1; i++){
      int j = i + l - 1;
      dp[0][i][j] = 2147483647;
      int v = dp[0][i][i + 1] + dp[0][i + 1][j] + sum[j] - sum[i - 1];
      if (v < dp[0][i][j]) dp[0][i][j] = v, p[0][i][j] = i + 1;
      printf("   debug: %d %d = %d\n", i, j, dp[0][i][j]);
    }

  int xa = 0;
  for (int i = 1; i <= n / 2; i++){
    xa = min(xa, dp[0][i][i + n - 1]);
  }
  printf("%d", xa);
  return 0;
}
