#include <iostream>
#include <algorithm>

using namespace std;
const int N = 2e5 + 5, Q = 5e5 + 5;
int n, m, q, k, r[N], c[N], t[Q];
long long ans;

int main(){
  scanf("%d %d %d %d", &n, &m, &q, &k);
  for (int x, y; q--; ){
    scanf("%d %d", &x, &y);
    if (x - 1) c[y] = (c[y] + 1) % k;
    else r[y] = (r[y] + 1) % k;
  }
  for (int i = 1; i <= n; i++) t[r[i]]++;
  for (int i = 1; i <= m; i++){
    if (c[i] == 0) ans += t[0];
    else ans += t[k - c[i]];
  } 
  printf("%lld", 1ll * n * m - ans);
  return 0;
}
