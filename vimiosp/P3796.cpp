#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;
const int N = 155, T = 1e6 + 5;
int n, m, tot, t[N], e[T], g[T], fl[T], c[T][28];
char s[N][75], a[T];
void fail(){
  queue<int> q;
  for (int i = 0; i < 26; i++) if (c[0][i]) q.push(c[0][i]);
  while (q.size()){
    int p = q.front(); q.pop();
    for (int i = 0; i < 26; i++)
      if (c[p][i]){
        fl[c[p][i]] = c[fl[p]][i], q.push(c[p][i]);
        g[c[p][i]] = e[fl[c[p][i]]] ? fl[c[p][i]] : g[fl[c[p][i]]];
      }
      else c[p][i] = c[fl[p]][i];
  }
}
void ins(char s[], int x){
  int p = 0;
  for (int i = 0; s[i]; i++){
    if (!c[p][s[i] - 'a']) c[p][s[i] - 'a'] = ++tot;
    p = c[p][s[i] - 'a'];
  }
  e[p] = x;
}
void qry(char s[]){
  int p = 0;
  for (int i = 0; s[i]; i++){
    p = c[p][s[i] - 'a'];
    for (int j = p; j; j = g[j]) t[e[j]]++;
  }
}

int main(){
  while (scanf("%d", &n), n != 0){
    tot = m = 0;
    memset(t, 0, sizeof(t)), memset(e, 0, sizeof(e));
    memset(fl, 0, sizeof(fl)), memset(c, 0, sizeof(c));
    for (int i = 1; i <= n; i++){cin >> s[i]; ins(s[i], i);}
    fail(); cin >> a; qry(a);
    for (int i = 1; i <= n; i++) m = max(m, t[i]);
    printf("%d\n", m);
    for (int i = 1; i <= n; i++) if (t[i] == m) cout << s[i] << endl;
  }
  return 0;
}
