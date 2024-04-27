#include <iostream>
#include <algorithm>

using namespace std;
int t, b, c, h;

int main(){
  scanf("%d", &t);
  while (t--){
    scanf("%d %d %d", &b, &c, &h), c += h;
    if (b > c) printf("%d\n", c * 2 + 1);
    else printf("%d\n", b * 2 - 1);
  }
  return 0;
}
