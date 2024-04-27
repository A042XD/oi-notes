#include <iostream>
#include <algorithm>

using namespace std;
int a, b;
int abs(int a){return a < 0 ? -a : a;}

int main(){
  scanf("%d %d", &a, &b);
  int ans = abs(b - a);
  ans = ans + min(abs(a), abs(b));
  printf("%d", ans);
  return 0;
}
