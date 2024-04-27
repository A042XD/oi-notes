#include <iostream>
#include <algorithm>
#define mid ((cl + cr) / 2)
#define inRange (l <= cl && cr <= r)
#define outRange (cr < l || r < cl)

using namespace std;
const int N = 2e7 + 5;
int n, m, s, d[N * 4];
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
  z1=x; z2=(~x)^0x233333333U; z3=x^0x1234598766U; z4=(~x)+51;
}
int read(){
  using namespace GenHelper;
  int a=rand_()&32767;
  int b=rand_()&32767;
  return a*32768+b;
}
void pushup(int u){d[u] = max(d[u * 2], d[u * 2 + 1]);}
void build(int u, int cl, int cr){
  if (cl >= cr) return d[u] = read(), void();
  build(u * 2, cl, mid), build(u * 2 + 1, mid + 1, cr);
  pushup(u);
}
int query(int u, int cl, int cr, int l, int r){
  if (inRange) return d[u];
  if (outRange) return 0;
  return max(query(u * 2, cl, mid, l, r), query(u * 2 + 1, mid + 1, cr, l, r));
}

int main(){
  scanf("%d %d %d", &n, &m, &s), srand(s);
  build(1, 1, n);
  for (int i = 1, l, r; i <= m; i++){
    l = read() % n + 1, r = read() % n + 1;
    if (l > r) swap(l, r);
    ans += query(1, 1, n, l, r);
  }
  cout << ans;
  return 0;
}
