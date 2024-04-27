#include <iostream>
#include <algorithm>

using namespace std;
const int N = 3e5 + 5;
int n, h, ans, s[N];
pair<int, int> a[N];
bool cmp(pair<int, int> a, pair<int, int> b){
  if (a.first == b.first) return a.second < b.second;
  return a.first < b.first;
}

int main(){
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) 
    scanf("%d %d", &a[i].first, &a[i].second), s[a[i].first]++;
  sort(a + 1, a + n + 1, cmp);
  for (int i = 1; i <= n; i++)
    if (a[i].first != a[i + 1].first){
      ans = max(ans, a[i].second + h);
      if (s[a[i].first] > 1) ans = max(ans, a[i].second + a[i - 1].second / 2);
      h = max(h, a[i].second);
    }
  printf("%d", ans);
  return 0;
}
