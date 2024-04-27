#include <iostream>
#include <algorithm>
#define int long long
#define mid ((cl + cr) / 2)

using namespace std;
const int N = 25;
int n, m, x, a[N], p[N], t[N], s[N * 4];
char c;
int qry(int x){int c = 0; for (; x; x -= x & -x) c += t[x]; return c;}
void upd(int x, int v){for (; x <= n; x += x & -x) t[x] += v;}
int find(int u, int cl, int cr, int k){
  if (cl >= cr) return cl;
  if (k <= mid - cl - s[u * 2] + 1) return find(u * 2, cl, mid, k);
  return find(u * 2 + 1, mid + 1, cr, k - mid + cl + s[u * 2] - 1);
}
void chg(int u, int cl, int cr, int p, int k){
  s[u] += 1;
  if (cl >= cr) return;
  if (p <= mid) chg(u * 2, cl, mid, p, x);
  else chg(u * 2 + 1, mid + 1, cr, p, x);
}

signed main(){
  scanf("%d %d", &n, &m), p[0] = 1;
  for (int i = 1; i <= n; i++) p[i] = p[i - 1] * i;
  for (; m--;){
    cin >> c;
    if (c == 'P'){
      scanf("%lld", &x), x--;
      for (int i = 1; i <= 4 * n; i++) s[i] = 0;
      for (int i = 1; i <= n; i++){
        int k = find(1, 1, n, x / p[n - i] + 1);
        printf("%lld ", k), chg(1, 1, n, k, 1), x %= p[n - i];
      }
      puts("");
    }
    else{
      int ans = 0;
      for (int i = 1; i <= n; i++) t[i] = 0;
      for (int i = 1; i <= n; i++) scanf("%lld", &a[i]), upd(i, 1);
      for (int i = 1; i <= n; i++) ans += qry(a[i] - 1) * p[n - i], upd(a[i], -1);
      printf("%lld\n", ans + 1);
    }
  }
  return 0;
}
