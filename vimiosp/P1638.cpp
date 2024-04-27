#include <iostream>

using namespace std;
const int N = 1e6 + 5, M = 2e3 + 5;
int n, m, id, cl, cr, a[N], cnt, t[M];

int main(){
  scanf("%d %d", &n, &m), cnt = m, id = 2147483467;
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int l = 1, r = 0; r <= n && l <= n;){
    if (!t[a[++r]]) cnt--;
    t[a[r]]++;
    while (!cnt){
      t[a[++l]]--;
      if (!t[a[l]]) cnt++;
      else if (r - l + 1 < id) id = r - l + 1, cl = l, cr = r;
      printf("  %d\n", id, cnt);
    }
  }
  printf("%d %d\n", cl, cr);
  return 0;
}
