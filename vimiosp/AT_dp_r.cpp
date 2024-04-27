#include <iostream>
#include <algorithm>
#include <cstring>
#define int long long

using namespace std;
const int N = 55;
int n, t, p = 1e9 + 7;
struct mat{
  int m[55][55]; 
  friend mat operator*(mat a, mat b){
    mat c; memset(c.m, 0, sizeof(c.m));
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++)
        for (int k = 1; k <= n; k++)
          c.m[i][j] = (c.m[i][j] + a.m[i][k] * b.m[k][j] % p) % p;
    return c;
  }
}d, ans;
void pow(int k){
  ans = d; k--;
  while (k){
    if (k & 1) ans = ans * d;
    d = d * d; k /= 2;
  }
}

signed main(){
  scanf("%lld %lld", &n, &t);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      scanf("%lld", &d.m[i][j]); 
  pow(t); int r = 0;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      r = (r + ans.m[i][j]) % p;
  printf("%lld", r);
  return 0;
}

