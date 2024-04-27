#include <iostream>

using namespace std;
const int N = 1e5 + 5;
int n, ans, a[N], low[N];

int main(){
  while (cin >> a[++n]); n--;
  low[0] = 2147483647;
  for (int i = 1; i <= n; i++)
    if (low[ans] >= a[i]) low[++ans] = a[i];
    else{
      int l = 1, r = ans;
      while (l < r){
        int mid = (l + r) / 2;
        if (low[mid] >= a[i]) l = mid + 1;
        else r = mid;
      }
      low[l] = a[i];
    }
  printf("%d", ans);
  low[0] = ans = 0;
  for (int i = 1; i <= n; i++)
    if (low[ans] < a[i]) low[++ans] = a[i];
    else{
      int l = 1, r = ans;
      while (l < r){
        int mid = (l + r) / 2;
        if (low[mid] < a[i]) l = mid + 1;
        else r = mid;
      }
      low[l] = a[i];
    }
  printf("\n%d", ans); 
  return 0;
}
