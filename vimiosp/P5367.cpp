#include <iostream>
#include <algorithm>
#define int long long

using namespace std;
const int N = 1e6 + 5, p = 998244353;
int n, ans, c[N], a[N], t[N];
int qry(int x){int c = 0; for (; x; x -= x & -x) c += t[x]; return c;}
void upd(int x, int v){for (; x <= n; x += x & -x) t[x] += v;}

signed main(){
  scanf("%lld", &n), c[1] = c[0] = 1;
  for (int i = 1; i <= n; i++) scanf("%lld", &a[i]), c[i] = i * c[i - 1] % p, upd(i, 1);
  for (int i = 1; i <= n; i++) 
    ans = (ans + (qry(a[i] - 1) * c[n - i]) % p) % p, upd(a[i], -1);
  printf("%lld", ans + 1);
  return 0;
}
