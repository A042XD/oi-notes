#include <iostream>
#include <algorithm>

using namespace std;
const int N = 5e4 + 5;
int n, m, dp[N];

int main(){
  scanf("%d %d", &n, &m);
  for (int i = 1, x; i <= m; i++){
    scanf("%d", &x);
    for (int j = n; j >= x; j--) dp[j] = max(dp[j], dp[j - x] + x);
  }
  printf("%d", dp[n]);
  return 0;
}
