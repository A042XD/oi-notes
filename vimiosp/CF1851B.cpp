#include <iostream>
#include <algorithm>

using namespace std;
const int N = 2e5 + 5;
int n, t, b[N];
pair<int, int> a[N];

int main(){
  scanf("%d", &t);
  while (t--){
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) 
      scanf("%d", &a[i].first), a[i].second = i, b[i] = a[i].first;
    sort(a + 1, a + n + 1); bool f = 0;
    for (int i = 1; i <= n; i++) 
      if (i != a[i].second && b[i] % 2 != a[i].first % 2) f |= 1;
    puts(f ? "NO" : "YES");
  }
  return 0;
}
