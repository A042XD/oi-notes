#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;
const int N = 205, S = 1e6 + 5;
int n, tot, t[S], m[N], in[S], fl[S], c[S][27];
char s[S];
void fail(){
  queue<int> q;
  for (int i = 0; i < 26; i++) if (c[0][i]) q.push(c[0][i]);
  while (q.size()){
    int p = q.front(); q.pop();
    for (int i = 0; i < 26; i++)
      if (c[p][i]) fl[c[p][i]] = c[fl[p]][i], in[fl[c[p][i]]]++, q.push(c[p][i]);
      else c[p][i] = c[fl[p]][i];
  }
}
void ins(char s[], int x){
  int p = 0;
  for (int i = 0; s[i]; i++){
    if (!c[p][s[i] - 'a']) c[p][s[i] - 'a'] = ++tot;
    t[p = c[p][s[i] - 'a']]++;
  }
  m[x] = p;
}
void topu(){
  queue<int> q;
  for (int i = 0; i <= tot; i++) if (!in[i]) q.push(i);
  while (q.size()){
    int p = q.front(); q.pop();
    t[fl[p]] += t[p];
    if (!(--in[fl[p]])) q.push(fl[p]);
  }
}

int main(){
  scanf("%d", &n);
  for (int i = 1; i <= n; i++){scanf("%s", s); ins(s, i);}
  fail(), topu();
  for (int i = 1; i <= n; i++) printf("%d\n", t[m[i]]);
  return 0;
}
