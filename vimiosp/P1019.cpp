#include <iostream>
#include <algorithm>

using namespace std;
const int N = 25;
int n, c[N][N], l[N];
char s[N][50], t;
int gt(int a, int b){
  for (int i = min(1, l[a] - l[b] + 1); i < l[a]; i++){
    bool f = 0;
    for (int j = 0; j < l[b]; j++)
      if (s[b][j] != s[a][i + j]){
        f = 1;
        break;
      }
    if (!f) return l[b] + i - l[a];
  }
  return 0;
}
void dfs(int ){
  
}

int main(){
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%s", s[i]);
  scanf("%s", t);
  for (int i = 1; i <= n; i++)
    while (s[i][l[i]] != '\0') l[i]++;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      c[i][j] = gt(i, j);
  
  return 0;
}
