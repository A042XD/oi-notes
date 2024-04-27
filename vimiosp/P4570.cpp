#include <iostream>
#include <algorithm>
#define int long long
#define f first
#define s second

using namespace std;
const int N = 1005, K = 70;
int n, ans, b[K];
pair<int, int> a[N];
bool ins(int x){
  for (int i = 60; ~i; i--)
    if (x >> i & 1)
      if (!b[i]) return b[i] = x, 1;
      else x ^= b[i];
  return 0;
}

signed main(){
  scanf("%lld", &n);
  for (int i = 1; i <= n; i++) scanf("%lld %lld", &a[i].s, &a[i].f);
  sort(a + 1, a + n + 1, greater<pair<int, int>>());
  for (int i = 1; i <= n; i++) if (ins(a[i].s)) ans += a[i].f;
  printf("%lld", ans);
  return 0;
}
