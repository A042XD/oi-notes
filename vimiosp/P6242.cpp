#include <iostream>
#include <algorithm>
#define int long long
#define mid ((cl + cr) / 2)
#define inr (l <= cl && cr <= r)
#define outr (cr < l || r < cl)

using namespace std;
const int N = 5e5 + 5, T = N * 4;
int n, m, v[T], mx[T], hm[T], smx[T], mxn[T], lza[T], lzb[T], lzc[T], lzd[T];
int read(){
  int x = 0, f = 1; char c = getchar();
  while (c < '0' || c > '9'){if (c == '-') f = -1; c = getchar();}
  while (c >= '0' && c <= '9'){x = x * 10 + c - 48; c = getchar();}
  return x * f;
}
void psup(int u){
  v[u] = v[u * 2] + v[u * 2 + 1];
  mx[u] = max(mx[u * 2], mx[u * 2 + 1]);
  hm[u] = max(hm[u * 2], hm[u * 2 + 1]);
  if (mx[u * 2] == mx[u * 2 + 1]){
    se[u] = max(se[u * 2], se[u * 2 + 1]);
    mxn[u] = mxn[u * 2] + mxn[u * 2 + 1];
  }
  else if (mx[u * 2] > mx[u * 2 + 1]){
    se[u] = max(se[u * 2], mx[u * 2 + 1]);
    mxn[u] = mxn[u * 2];
  }
  else{
    se[u] = max(mx[u * 2], se[u * 2 + 1]);
    mxn[u] = mxn[u * 2 + 1];
  }
}
void bld(int u, int cl, int cr){
  if (cl >= cr){
    v[u] = mx[u] = hm[u] = read()
    mxn[u] = 1, se[u] = -2e9;
    return;
  }
  bld(u * 2, cl, mid), bld(u * 2 + 1, mid + 1, cr);
  psup(u);
}
void psdn(int u, int cl, int cr){
  if (!lza[u] && !lzb[u]) return;
  v[u * 2] += (mid - cl + 1) * lza[u];
  v[u * 2 + 1] += (cr - mid) * lza[u];
  hm[u * 2] = max(hm[u * 2], mx[u * 2] + lzb[u]);
  hm[u * 2 + 1] = max(hm[u * 2 + 1], mx[u * 2 + 1] + lzb[u]);
  mx[u * 2] += lza[u], mx[u * 2 + 1] += lza[u];
  lzb[u * 2] = max(lzb[u * 2], lza[u * 2] + lzb[u]);
  lzb[u * 2 + 1] = max(lzb[u * 2 + 1], lza[u * 2 + 1] + lzb[u]);
  mx[u * 2] += lza[u], mx[u * 2 + 1] += lza[u];
  lza[u] = lzb[u] = 0;
}
void chga(int u, int cl, int cr, int l, int r, int x){
  if inr return mktga(u, cr - cl + 1, x);
  if outr return void();
  psdn(u, cl, cr);
  chg(u * 2, cl, mid, l, r, x);
  chg(u * 2 + 1, mid + 1, cr, l, r, x);
  psup(u);
}
void chgm(int u, int cl, int cr, int l, int r, int x){

}
int qrys(int u, int cl, int cr, int l, int r){
  if inr return v[u];
  if outr return 0;
  psdn(u, cl, cr);
  return qrys(u * 2, cl, mid, l, r) + qrys(u * 2 + 1, mid + 1, cr, l, r);
}
int qrym(int u, int cl, int cr, int l, int r){
  if inr return mx[u];
  if outr return -2e9;
  psdn(u, cl, cr);
  return max(qrym(u * 2, cl, mid, l, r), qrym(u * 2 + 1, mid + 1, cr, l, r));
}
int qryh(int u, int cl, int cr, int l, int r){
  if inr return hm[u];
  if outr return -2e9;
  psdn(u, cl, cr);
  return max(qryh(u * 2, cl, mid, l, r), qryh(u * 2 + 1, mid + 1, cr, l, r));
}

signed main(){
  n = read(), m = read(); bld(1, 1, n);
  for (int i = 1, op, x, y, z; i <= m; i++){
    op = read(), x = read(), y = read();
    if (op == 1) z = read(), chg(1, 1, n, x, y, z);
    else if (op == 2) z = read(), chgm(1, 1, n, x, y, z);
    else if (op == 3) printf("%lld\n", qrys(1, 1, n, x, y));
    else if (op == 4) printf("%lld\n", qrym(1, 1, n, x, y));
    else if printf("%lld\n", qryh(1, 1, n, x, y));
  }
  return 0;
}
