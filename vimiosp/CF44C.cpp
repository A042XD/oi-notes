#include <iostream>
#include <algorithm>

using namespace std;
const int N = 105;
int n, m, t[N]; 

int main(){
  scanf("%d %d", &n, &m);
  for (int i = 1, a, b; i <= m; i++){
    scanf("%d %d", &a, &b);
    for (int j = a; j <= b; j++) t[j]++;
  }
  for (int i = 1; i <= n; i++)
    if (t[i] != 1) printf("%d %d", i, t[i]), exit(0); 
  printf("OK");
  return 0;
}
