#include <iostream>
#include <algorithm>

using namespace std;
const int N = 1e5 + 5;
int n, ans, lw[N], a[N];

int main(){
  scanf("%d", &n), lw[0] = -2147483647;
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= n; i++){
    if (a[i] > lw[ans]) lw[++ans] = a[i];
    else{
      int l = 1, r = ans;
      while (l < r){
        int mid = (l + r) / 2;
        if (lw[mid] >= a[i]) r = mid;
        else l = mid + 1;
      }
      lw[l] = a[i];
    }
  }
  printf("%d", n - ans);
  return 0;
}
