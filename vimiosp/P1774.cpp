#include <iostream>
#include <algorithm>
#define int long long

using namespace std;
const int N = 5e5 + 5;
int n, ans, a[N], b[N], t[N];
int qry(int x){int c = 0; for (; x; x -= x & -x) c += t[x]; return c;}
void upd(int x, int v){for (; x <= n; x += x & -x) t[x] += v;}

signed main(){
  scanf("%lld", &n);
  for (int i = 1; i <= n; i++) scanf("%lld", &a[i]), b[i] = a[i];
  stable_sort(b + 1, b + n + 1); // Discretization
  int l = unique(b + 1, b + n + 1) - b - 1;
  for (int i = 1; i <= n; i++)
    a[i] = lower_bound(b + 1, b + l + 1, a[i]) - b;
  for (int i = 1; i <= n; i++)
    ans += qry(l - a[i]), upd(l - a[i] + 1, 1);
  printf("%lld", ans);
  return 0;
}
