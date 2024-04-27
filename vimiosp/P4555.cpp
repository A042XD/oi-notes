#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
const int N = 2e5 + 5;
int n, m, ans, ll[N], rr[N], p[N];
char s[N], t[N];

int main(){
  scanf("%s", s + 1); n = strlen(s + 1); t[0] = '#', t[m = 1] = '@';
  for (int i = 1; i <= n; i++) t[++m] = s[i], t[++m] = '@'; t[++m] = '!';
  for (int i = 1, r = 0, d = 0; i <= m; i++){
    if (i > r) p[i] = 1;
    else p[i] = min(p[2 * d - i], r - i + 1);
    while (t[i + p[i]] == t[i - p[i]]) p[i]++;
    if (i + p[i] - 1 > r) d = i, r = i + p[i] - 1;
    ll[i - p[i] + 1] = max(ll[i - p[i] + 1], p[i] - 1);
    rr[i + p[i] - 1] = max(rr[i + p[i] - 1], p[i] - 1);
  }
  for (int i = 1; i <= m; i += 2) ll[i] = max(ll[i], ll[i - 2] - 2);
  for (int i = m; i >= 1; i -= 2) rr[i] = max(rr[i], rr[i + 2] - 2);
  for (int i = 1; i <= m; i += 2) if (ll[i] && rr[i]) ans = max(ans, ll[i] + rr[i]);
  printf("%d", ans);
  return 0;
}
