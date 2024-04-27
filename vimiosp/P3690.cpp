#include <iostream>
#include <algorithm>

using namespace std;
const int N = 3e5 + 5;
int n, m, a[N], top, c[N][2], fa[N], xr[N], q[N], rev[N];
void psup(int x){xr[x] = xr[c[x][0]] ^ xr[c[x][1]] ^ a[x];}
bool isrt(int x){return c[fa[x]][0] != x && c[fa[x]][1] != x;}
void psdown(int x){
  if (!rev[x]) return;
  rev[c[x][0]] ^= 1, rev[c[x][1]] ^= 1;
  rev[x] ^= 1, swap(c[x][0], c[x][1]);
}
void rot(int x){
  int y = fa[x], z = fa[y], l, r;
  if (c[y][0] == x) l = 0; else l = 1; r = l ^ 1;
  if (!isrt(y)){if (c[z][0] == y) c[z][0] = x; else c[z][1] = x;}
  fa[x] = z, fa[y] = x, fa[c[x][r]] = y;
  c[y][l] = c[x][r]; c[x][r] = y;
  psup(y); psup(x);
}
void splay(int x){
  top = 1, q[top] = x;
  for (int i = x; !isrt(i); i = fa[i]) q[++top] = fa[i];
  for (int i = top; i; i--) psdown(q[i]);
  while (!isrt(x)){
    int y = fa[x], z = fa[y];
    if (!isrt(y)){
      if ((c[y][0] == x) ^ (c[z][0] == y)) rot(x);
      else rot(y);
    }
    rot(x);
  }
}
void access(int x){for (int t = 0; x; x = fa[t = x]) splay(x), c[x][1] = t, psup(x);}
void mkrt(int x){access(x); splay(x); rev[x] ^= 1; psdown(x);}
int find(int x){access(x); splay(x); while (c[x][0]) psdown(x), x = c[x][0]; splay(x); return x;}
void split(int x, int y){mkrt(x); access(y); splay(y);}
void cut(int x, int y){mkrt(x); if (find(y) == x && fa[y] == x && !c[y][0]) fa[y] = c[x][1] = 0, psup(x);}
void link(int x, int y){mkrt(x); fa[x] = y;}
int read(){
  int x = 0, f = 1; char c = getchar();
  while (c < '0' || c > '9'){if (c == '-') f = -1; c = getchar();}
  while (c >= '0' && c <= '9'){x = x * 10 + c - 48; c = getchar();}
  return x * f;
}

int main(){
  n = read(), m = read();
  for (int i = 1; i <= n; i++) a[i] = read(), xr[i] = a[i];
  for (int op, x, y; m--; ){
    op = read(), x = read(), y = read();
    if (op == 0) split(x, y), printf("%d\n", xr[y]);
    else if (op == 1){
      int xx = find(x), yy = find(y);
      if (xx != yy) link(x, y);
    }
    else if (op == 2){
      cut(x, y);
    }
    else{access(x); splay(x); a[x] = y; psup(x);}
  }
  return 0;
}

