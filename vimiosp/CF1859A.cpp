#include <iostream>
#include <algorithm>

using namespace std;
const int N = 105;
int t, n, a[N];

int main(){
  scanf("%d", &t);
  while (t--){
    scanf("%d", &n); int p = 1, y = 0; bool f = 1;
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 2; i <= n; i++){
      if (a[i] != a[i - 1]) f = 0;
      if (a[i] < a[p]) p = i;
    }
    for (int i = 1; i <= n; i++) y += (a[i] == a[p]);
    if (f == 1) printf("-1\n");
    else{
      printf("%d %d\n", y, n - y, a[p]);
      for (int i = 1; i <= y; i++) printf("%d ", a[p]);
      puts("");
      for (int i = 1; i <= n; i++) 
        if (a[i] != a[p]) printf("%d ", a[i]);
      puts("");
    }
  }
  return 0;
}
