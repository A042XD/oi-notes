#include <iostream>
#include <cstring>
#include <algorithm>
#define int long long

using namespace std;
const int N = 105, p = 1e9 + 7;
int n, k;
struct mat{
  int m[N][N];
  mat(){memset(m, 0, sizeof(m));}
  friend mat operator*(mat a, mat b){
    mat c; int r; 
    for (int i = 1; i <= n; i++)
      for (int k = 1; k <= n; k++){
        r = a.m[i][k];
        for (int j = 1; j <= n; j++)
          c.m[i][j] += b.m[k][j] * r, c.m[i][j] %= p;
      }
    return c;
  }
}a;
mat pow(mat a, int k){
  mat t = a; k--;
  while (k){
    if (k & 1) t = t * a;
    a = a * a, k /= 2;
  }
  return t;
}

signed main(){
  scanf("%lld %lld", &n, &k);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      scanf("%lld", &a.m[i][j]);
  a = pow(a, k);
  for (int i = 1; i <= n; i++, puts(""))
    for (int j = 1; j <= n; j++)
      printf("%lld ", a.m[i][j]);
  return 0;
}
