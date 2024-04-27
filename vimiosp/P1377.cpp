#include <iostream>
#include <algorithm>

using namespace std;
const int N = 1e5 + 5;
int n, tp, w[N], s[N], ls[N], rs[N];
void dfs(int x){
  if (!x) return;
  printf("%d ", x);
  dfs(ls[x]);
  dfs(rs[x]);
}

int main(){
  scanf("%d", &n);
  for (int i = 1, x; i <= n; i++) scanf("%d", &x), w[x] = i;
  for (int i = 1, k = 0; i <= n; i++){
    while (k && w[s[k]] > w[i]) k--;
    if (k) rs[s[k]] = i;
    if (k < tp) ls[i] = s[k + 1];
    s[tp = ++k] = i;
  }
  dfs(s[1]);
  return 0;
}
