#include <iostream>
#include <algorithm>

using namespace std;
int n;

int main(){
  scanf("%d", &n); int t = 1;
  for (int i = 1; i <= n; i++, puts(""))
    for (int j = 1; j <= n; j++) 
      if (t <= 9) printf("0%d", t++);
      else printf("%d", t++);
  puts(""); t = 1;
  for (int i = 1; i <= n; i++, puts("")){
    for (int j = 1; j <= n - i; j++) printf("  ");
    for (int j = 1; j <= i; j++) 
      if (t <= 9) printf("0%d", t++);
      else printf("%d", t++);
  }
  return 0;
}
