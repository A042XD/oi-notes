#include <iostream>
#include <algorithm>

using namespace std;
const int N = 1005;
int n, a[N], b[N], c[N], ans;

int main(){
  scanf("%d", &n);
  for (int i = 1; i <= n; i++){
    scanf("%d %d %d", &a[i], &b[i], &c[i]);
    for (int j = 1; j < i; j++)
      ans += (abs(a[j] - a[i]) < 6 && abs(b[j] - b[i]) < 6 && abs(c[j] - c[i]) < 6 && abs((a[i] + b[i] + c[i]) - (a[j] + b[j] + c[j])) < 11);
  }
  printf("%d", ans);
  return 0;
}
