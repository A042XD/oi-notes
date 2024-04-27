#include <iostream>
#include <algorithm>
#include <cmath>
#define int long long

using namespace std;
const int N = 50005;
int n, m, len, sum, cnt[N], c[N], ans1[N], ans2[N];
struct qry{int l, r, id;} a[N];
bool cmp(qry a, qry b){
  if (a.l / len != b.l / len) return a.l < b.l;
  return (a.l / len) & 1 ? a.r < b.r : a.r > b.r;
}
void add(int x){sum += cnt[x], cnt[x]++;}
void del(int x){cnt[x]--, sum -= cnt[x];}
int gcd(int a, int b){return !b ? a : gcd(b, a % b);}

signed main(){
  scanf("%lld %lld", &n, &m);
  len = sqrt(n);
  for (int i = 1; i <= n; i++) scanf("%lld", &c[i]);
  for (int i = 1; i <= m; i++) scanf("%lld %lld", &a[i].l, &a[i].r), a[i].id = i;
  sort(a + 1, a + m + 1, cmp);
  for (int i = 1, l = 1, r = 0; i <= m; i++){
    if (a[i].l == a[i].r){
      ans1[a[i].id] = 0, ans2[a[i].id] = 1;
      continue;
    }
    while (l > a[i].l) add(c[--l]);
    while (r < a[i].r) add(c[++r]);
    while (l < a[i].l) del(c[l++]);
    while (r > a[i].r) del(c[r--]);
    ans1[a[i].id] = sum;
    ans2[a[i].id] = (r - l + 1) * (r - l) / 2;
  }
  for (int i = 1, t; i <= m; i++){
    if (ans1[i] != 0) t = gcd(ans1[i], ans2[i]), ans1[i] /= t, ans2[i] /= t;
    else ans2[i] = 1;
    printf("%lld/%lld\n", ans1[i], ans2[i]);
  }
  return 0;
}
