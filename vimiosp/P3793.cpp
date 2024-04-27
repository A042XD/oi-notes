#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;
const int N = 2e7 + 5;
int n, q, s, l, a[N], l2[N], suf[N], pre[N], b[N], m[1000005], st[1000005][25];
unsigned long long ans;

namespace GenHelper{
  unsigned z1,z2,z3,z4,b;
  unsigned rand_(){
    b=((z1<<6)^z1)>>13;
    z1=((z1&4294967294U)<<18)^b;
    b=((z2<<2)^z2)>>27;
    z2=((z2&4294967288U)<<2)^b;
    b=((z3<<13)^z3)>>21;
    z3=((z3&4294967280U)<<7)^b;
    b=((z4<<3)^z4)>>12;
    z4=((z4&4294967168U)<<13)^b;
    return (z1^z2^z3^z4);
  }
}
void srand(unsigned x){
  using namespace GenHelper;
  z1=x,z2=(~x)^0x233333333U,z3=x^0x1234598766U,z4=(~x)+51;
}
int read(){
  using namespace GenHelper;
  int a=rand_()&32767,b=rand_()&32767;
  return a*32768+b;
}
int stq(int l, int r){
  if (l > r) return 0;
  if (l == r) return st[l][0];
  int t = l2[r - l + 1];
  return max(st[l][t], st[r - (1 << t) + 1][t]);
}
int query(int l, int r){
  if (l > r) swap(l, r);
  if (b[l] == b[r]){
    int ans = 0;
    for (int i = l; i <= r; i++) ans = max(ans, a[i]);
    return ans;
  }
  return max(max(suf[l], pre[r]), stq(b[l] + 1, b[r] - 1));
}

int main(){
  scanf("%d %d %d", &n, &q, &s), srand(s);
  for (int i = 2; i <= n; i++) l2[i] = l2[i / 2] + 1;
  l = sqrt(n);
  for (int i = 1; i <= n; i++){
    a[i] = read();
    b[i] = (i - 1) / l + 1;
    st[b[i]][0] = m[b[i]] = max(m[b[i]], a[i]);
    pre[i] = (b[i - 1] == b[i] ? max(a[i], pre[i - 1]) : a[i]);
  }
  for (int i = n; i >= 1; i--) suf[i] = (b[i + 1] == b[i] ? max(a[i], suf[i + 1]) : a[i]);
  for (int p = 1; p <= l2[n / l]; p++)
    for (int i = 1; i <= n / l - (1 << p) + 1; i++)
      st[i][p] = max(st[i][p - 1], st[i + (1 << (p - 1))][p - 1]);
  for (int i = 1, l, r; i <= q; i++)
    l = read() % n + 1, r = read() % n + 1, ans += query(l, r);
  cout << ans;
  return 0;
}

