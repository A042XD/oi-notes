#include <iostream>
#include <algorithm>

using namespace std;
int a, b;

int main(){
  scanf("%d %d", &a, &b); a = min(a, b); b = a;
  for (int i = 1; i < b; i++) a *= i;
  printf("%d", a);
  return 0;
}
