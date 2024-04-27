#include <iostream>

using namespace std;
const int N = 500;
int n, ans, a[N], t[N], c[N];
int qry(int x){int c = 0; for (; x; x -= x & -x) c += t[x]; return c;}
void upd(int x, int v){for (; x <= n; x += x & -x) t[x] += v;}

int main(){
  scanf("%d", &n), c[0] = 1;
  for (int i = 1; i <= n; i++){
    char x; 
    cin >> x, a[i] = x - '0';
    c[i] = i * c[i - 1], upd(i, 1);
  }
  for (int i = 1; i <= n; i++) ans += qry(a[i] - 1) * c[n - i], upd(a[i], -1);
  printf("%d", ans + 1);
  return 0;
}
