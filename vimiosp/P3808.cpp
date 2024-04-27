#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;
const int N =1e6 + 5;
int n, tot, e[N], fl[N], c[N][26];
char s[N];
void ins(char s[], int p = 0){
  for (int i = 1; s[i]; p = c[p][s[i++] - 'a'])
    if (!c[p][s[i] - 'a']) c[p][s[i] - 'a'] = ++tot;
  e[p]++;
}
void bld(){
  queue<int> q;
  for (int i = 0; i < 26; i++) if (c[0][i]) q.push(c[0][i]);
  while (q.size()){
    int p = q.front(); q.pop();
    for (int i = 0; i < 26; i++)
      if (c[p][i]) fl[c[p][i]] = c[fl[p]][i], q.push(c[p][i]);
      else c[p][i] = c[fl[p]][i];
  }
}
int qry(char s[], int p = 0){
  int rs = 0;
  for (int i = 1; s[i]; i++){
    p = c[p][s[i] - 'a'];
    for (int j = p; j && e[j] != -1; j = fl[j]) rs += e[j], e[j] = -1;
  }
  return rs;
}

int main(){
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%s", s + 1), ins(s);
  scanf("%s", s + 1); bld(); printf("%d", qry(s));
  return 0;
}
