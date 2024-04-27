#include <iostream>
#define int long long

using namespace std;
const int N = 3e6 + 5;
int n, m, p[N];

signed main(){
  scanf("%lld %lld", &n, &m), p[1] = 1;
  for (int i = 2; i <= n; i++) p[i] = (m - m / i) * p[m % i] % m;
  for (int i = 1; i <= n; i++) printf("%lld\n", p[i]);
  return 0;
}
