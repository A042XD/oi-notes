#include <iostream>
#include <algorithm>
#include <cstring>
#define int long long

using namespace std;
const int N = 4e7 + 5;
char a[N], b[N];
int z[N], p[N], ansa, ansb;
void gtz(char a[]){
  z[0] = 0;
  while (a[z[0]] != '\0') z[0]++;
  for (int i = 1, l = 0, r = 0; i < z[0]; i++){
    if (i <= r && z[i - l] < r - i + 1) z[i] = z[i - l];
    else{
      z[i] = max(0ll, r - i + 1);
      while (i + z[i] < z[0] && a[z[i]] == a[i + z[i]]) z[i]++;
    }
    if (r < i + z[i] - 1) l = i, r = i + z[i] - 1;
  }
}
void xkmp(char a[], char b[]){
  int la = strlen(a), lb = strlen(b);
  while (a[p[0]] == b[p[0]]) p[0]++;
  for (int i = 1, l = 0, r = 0; i < la; i++){
    if (i <= r && z[i - l] < r - i + 1) p[i] = z[i - l];
    else{
      p[i] = max(0ll, r - i + 1);
      while (i + p[i] < la && p[i] < lb && b[p[i]] == a[p[i] + i]) p[i]++;
    }
    if (r < i + p[i] - 1) l = i, r = i + p[i] - 1;
  }
}

signed main(){
  scanf("%s %s", a, b);
  gtz(b), xkmp(a, b);
  for (int i = 0; b[i] != '\0'; i++) ansa ^= (i + 1ll) * (z[i] + 1);
  for (int i = 0; a[i] != '\0'; i++) ansb ^= (i + 1ll) * (p[i] + 1);
  printf("%lld\n%lld", ansa, ansb);
  return 0;
}
