#include <iostream>
#include <algorithm>

using namespace std;
const int N = 5e6 + 5;
int n, m, ans = 2147483647, a[N];

int main(){
  scanf("%d %d", &n, &m);
  for (int i = 1, x; i <= n; i++) scanf("%d", &x), a[i] += x, a[i + 1] -= x;
  for (int i = 1, l, r, x; i <= m; i++) 
    scanf("%d %d %d", &l, &r, &x), a[l] += x, a[r + 1] -= x;
  for (int i = 1, c = 0; i <= n; i++)
    c += a[i], ans = min(ans, c);
  printf("%d", ans);
  return 0;
}
