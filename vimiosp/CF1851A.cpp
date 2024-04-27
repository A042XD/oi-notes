#include <iostream>
#include <algorithm>

using namespace std;
int t, ans, n, m, k, h;

int main(){
  scanf("%d", &t);
  while (t--){
    scanf("%d %d %d %d", &n, &m, &k, &h), ans = 0, m--;
    for (int i = 1, x; i <= n; i++)
      scanf("%d", &x), ans += (x != h && (abs(x - h) <= m * k) && (abs(x - h) % k == 0));
    printf("%d\n", ans);
  }
  return 0;
}
