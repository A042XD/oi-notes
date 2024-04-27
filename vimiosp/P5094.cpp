#include <iostream>
#include <algorithm>
#define int long long

using namespace std;
const int N = 6e4 + 5, nn = 5e4;
int n, ans, sm, t1[N], t2[N], p[N];
pair<int, int> a[N];
int qry1(int x){int c = 0; for (; x; x -= x & (-x)) c += t1[x]; return c;}
void upd1(int x, int v){for (; x <= nn; x += x & (-x)) t1[x] += v;}
int qry2(int x){int c = 0; for (; x; x -= x & (-x)) c += t2[x]; return c;}
void upd2(int x, int v){for (; x <= nn; x += x & (-x)) t2[x] += v;}

signed main(){
  scanf("%lld", &n);
  for (int i = 1; i <= n; i++) scanf("%lld %lld", &a[i].first, &a[i].second);
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; i++){
    int nu = qry1(a[i].second), su = qry2(a[i].second);
    ans += (nu * a[i].second - su) * a[i].first;
    ans += ((sm - su) - (i - nu - 1) * a[i].second) * a[i].first;
    upd1(a[i].second, 1), upd2(a[i].second, a[i].second), sm += a[i].second;
  }
  printf("%lld", ans);
  return 0;
}
