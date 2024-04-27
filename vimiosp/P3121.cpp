#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;
const int N = 1e5 + 5;
int n, tot, tp, rc[N], d[N], fl[N], c[N][26];
char s[N], a[N], st[N];
void fail(){
  queue<int> q;
  for (int i = 0; i < 26; i++) if (c[0][i]) q.push(c[0][i]);
  while (q.size()){
    int p = q.front(); q.pop();
    for (int i = 0; i < 26; i++)
      if (c[p][i]) fl[c[p][i]] = c[fl[p]][i], q.push(c[p][i]);
      else c[p][i] = c[fl[p]][i];
  }
}
void ins(char s[]){
  int p = 0, i;
  for (i = 0; s[i]; i++){
    if (!c[p][s[i] - 'a']) c[p][s[i] - 'a'] = ++tot;
    p = c[p][s[i] - 'a'];
  }
  d[p] = i;
}
void qry(char s[]){
  int p = 0;
  for (int i = 0; s[i]; i++){
    st[++tp] = s[i], rc[tp] = (p = c[p][st[tp] - 'a']);
    if (d[p]) tp -= d[p], p = rc[tp];
  }
}

int main(){
  scanf("%s %d", s, &n);
  for (int i = 1; i <= n; i++) scanf("%s", a), ins(a);
  fail(); qry(s);
  for (int i = 1; i <= tp; i++) printf("%c", st[i]);
  return 0;
}
