#include <iostream>
#include <algorithm>
#define int long long

using namespace std;
int t, l, r;

signed main(){
  scanf("%lld", &t);
  while (t--){
    scanf("%lld %lld", &l, &r);
    if ((l + r) & 1) printf("%lld\n", ((l + r) % 9 * ((r - l + 1) / 2) % 9) % 9);
    else printf("%lld\n", (((l + r) / 2) % 9 * (r - l + 1) % 9) % 9);
  }
  return 0;
}
