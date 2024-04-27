#include <iostream>

using namespace std;
const int M = 105;
int d[M], q[M], r, m, s;

int main(){
  scanf("%d", &m);
  for (int i = 1; i <= m; i++) scanf("%d", &d[i]), s += d[i];
  s = s / 2 + 1;
  for (int i = 1; i <= m; i++)
    if (s > d[i]) s -= d[i];
    else{
      printf("%d %d", i, s);
      exit(0);
    }
  return 0;
}
