#include <iostream>
#include <algorithm>

using namespace std;
const int N = 105;
int n, m;

int main(){
  scanf("%d %d", &n, &m);
  if (n * 2 <= m) puts("0"), exit(0);
  else if (m == n + 1) printf("%d", n * 2 - 2);
  else{
    int ans = 0, k = 0;
    if (m & 1) ans = 2, k = 1;
    k += m / 2;
    ans += (n - k) * 4;
    printf("%d", ans);
  }
  return 0;
}
