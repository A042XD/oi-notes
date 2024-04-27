#include <iostream>

using namespace std;
int t;
int gcd(int a, int b){return !b ? a : gcd(b, a % b);}

int main(){
  scanf("%d", &t);
  while (t--){
    int a, b; scanf("%d %d", &a, &b); 
    if (gcd(a, b) != a){puts("-1"); continue;}
    printf("%d %d\n", a, b);
  }
  return 0;
}
