#include <iostream>
#include <algorithm>

using namespace std;
int t, a, b, c;

int main(){
  scanf("%d", &t);
  while (t--){
    scanf("%d %d %d", &a, &b, &c);
    if (c % 2) puts(a >= b ? "First" : "Second");
    else puts(a > b ? "First" : "Second");
  }
  return 0;
}
