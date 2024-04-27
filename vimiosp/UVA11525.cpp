#include <iostream>
#include <algorithm>
#define mid ((cl + cr) / 2)

using namespace std;
const int N = 5e4 + 5;
int q, n, s[N], t[N * 4];
int find(int u, int cl, int cr, int k){
  if (cl >= cr) return cl;
  if (k <= mid - cl - t[u * 2] + 1) return find(u * 2, cl, mid, k);
  return find(u * 2 + 1, mid + 1, cr, k - mid + cl + t[u * 2] - 1);
}
void change(int u, int cl, int cr, int p, int x){
  t[u] += x;
  if (cl >= cr) return;
  if (p <= mid) change(u * 2, cl, mid, p, x);
  else change(u * 2 + 1, mid + 1, cr, p, x);
}

int main(){
  scanf("%d", &q);
  while (q--){
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &s[i]);
    for (int i = 1; i <= n * 4; i++) t[i] = 0;
    for (int i = 1, tmp; i <= n; i++)
      tmp = find(1, 1, n, s[i] + 1), printf("%d%c", tmp, i != n ? ' ' : '\n'), change(1, 1, n, tmp, 1);
  }
  return 0;
}
