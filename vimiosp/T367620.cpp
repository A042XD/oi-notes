#include <iostream>
#include <algorithm>

using namespace std;
int t;

int main(){
  scanf("%d", &t);
  for (int a1, b1, c1, a2, b2, c2; t--; ){
    scanf("%d %d %d %d %d %d", &a1, &b1, &c1, &a2, &b2, &c2);
    if (a1 > b2 || c1 > a2) {puts("C"); continue;}
    a2 -= c1, c1 = 0;
    if (b1 < a2 || a1 < c2) {puts("D"); continue;}
    puts("E");
  }
  return 0;
}
