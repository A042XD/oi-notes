#include <iostream>

using namespace std;
int x, y, z;

int main(){
  scanf("%d %d %d", &x, &y, &z);
  if (x + y > z && x + z > y && y + z > x) puts("1");
  else puts("0");
  return 0;
}
