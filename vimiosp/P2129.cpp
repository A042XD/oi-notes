#include <iostream>
#include <algorithm>

using namespace std;
const int N = 5e5 + 5;
int n, m, a, b, cx, cy, bx = 1, by = 1, x[N], y[N], u[N], v[N];
char c[N];

int main(){
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d %d", &x[i], &y[i]);
  for (int i = 1; i <= m; i++){
    cin >> c[i];
    if (c[i] == 'm') scanf("%d %d", &u[i], &v[i]);
  }
  for (int i = m; i >= 1; i--){
    if (c[i] == 'm') cx += u[i], cy += v[i];
    else if (c[i] == 'x') bx *= -1, cx *= -1;
    else by *= -1, cy *= -1;
  }
  for (int i = 1; i <= n; i++) 
    printf("%d %d\n", x[i] * bx + cx, y[i] * by + cy);
  return 0;
}
