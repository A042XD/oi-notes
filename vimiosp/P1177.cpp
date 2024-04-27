#include <iostream>
#include <algorithm>

using namespace std;
const int N = 1e5 + 5;
int n, a[N], b[N];
void mrgsrt(int l, int r){
  if (r <= l) return;
  int mid = (l + r) / 2, x = l, y = mid + 1;
  mrgsrt(l, mid), mrgsrt(mid + 1, r);
  for (int i = l; i <= r;){
    while (x <= mid && (y > r || a[x] <= a[y])) b[i++] = a[x++];
    while (y <= r && (x > mid || a[x] >= a[y])) b[i++] = a[y++];
  } 
  for (int i = l; i <= r; i++) a[i] = b[i];
}

int main(){
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  mrgsrt(1, n);
  for (int i = 1; i <= n; i++) printf("%d ", a[i]);
  return 0;
}
