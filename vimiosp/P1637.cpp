#include <iostream>
#include <algorithm>
#define int long long

using namespace std;
const int N = 3e4 + 5, M = 1e5 + 5;
int n, ans, a[N], t1[M], t2[M];
int qry1(int x){int c = 0; for (; x; x -= x & -x) c += t1[x]; return c;}
void upd1(int x, int v){for (; x <= 1e5; x += x & -x) t1[x] += v;}
int qry2(int x){int c = 0; for (; x; x -= x & -x) c += t2[x]; return c;}
void upd2(int x, int v){for (; x <= 1e5; x += x & -x) t2[x] += v;}

signed main(){
  scanf("%lld", &n);
  for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
  for (int i = 1, x, y; i <= n; i++){
    x = qry1(a[i] - 1), ans += qry2(a[i] - 1);
    upd2(a[i], x), upd1(a[i], 1);
  }
  printf("%lld", ans);
  return 0;
}
