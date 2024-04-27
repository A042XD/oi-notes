#include <iostream>
#include <algorithm>

using namespace std;
const int N = 4e4 + 5;
int n, x, dp[N][8];

int main(){
  scanf("%d", &n), dp[0][0] = 1; 
  for (int i = 1; i * i <= 32768; i++)
    for (int j = i * i; j <= 32768; j++) 
      for (int k = 1; k <= 4; k++) 
        dp[j][k] += dp[j - i * i][k - 1];
  while (n--) scanf("%d", &x), printf("%d\n", dp[x][1] + dp[x][2] + dp[x][3] + dp[x][4]);
  return 0;
}
