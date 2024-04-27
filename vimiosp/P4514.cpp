#include <iostream>
#include <algorithm>

using namespace std;
const int N = 2056;
int n, m, c1[N][N], c2[N][N], c3[N][N], c4[N][N];
char s;
void upd(int x, int y, int v){
  int v2 = x * v, v3 = y * v, v4 = x * y * v;
  for (int i = x; i <= n; i += i & -i)
    for (int j = y; j <= n; j += j & -j)
      c1[i][j] += v, c2[i][j] += v2, c3[i][j] += v3, c4[i][j] += v4;
}
int qry(int x, int y){
  int s1 = 0, s2 = 0, s3 = 0, s4 = 0;
  for (int i = x; i; i -= i & -i)
    for (int j = y; j; j -= j & -j)
      s1 += c1[i][j], s2 += c2[i][j], s3 += c3[i][j], s4 += c4[i][j];
  return (x + 1) * (y + 1) * s1 - (y + 1) * s2 - (x + 1) * s3 + s4;
}

int main(){
  scanf("%c %d %d", &s, &n, &m);
  while (cin >> s){
    int a, b, c, d, e;
    if (s == 'L'){
      scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
      upd(a, b, e), upd(c + 1, b, -e), upd(a, d + 1, -e), upd(c + 1, d + 1, e);
    }
    else{
      scanf("%d %d %d %d", &a, &b, &c, &d);
      printf("%d\n", qry(c, d) + qry(a - 1, b - 1) - qry(a - 1, d) - qry(c, b - 1));
    }
  }
  return 0;
}
