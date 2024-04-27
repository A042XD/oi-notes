#include <iostream>
#include <algorithm>
#include <queue>
#define pii pair<int, int>

using namespace std;
const int N = 2005;
int h, w, ch[N][26], lh, lw, cw[N][26];
char c[N][N];
bool eh[N], ew[N];

int main(){
  scanf("%d %d", &h, &w); lh = h; lw = w;
  for (int i = 1; i <= h; i++)
    scanf("%s", c[i] + 1);
  for (int i = 1; i <= h; i++)
    for (int j = 1; j <= w; j++)
      ch[i][c[i][j] - 'a']++, cw[j][c[i][j] - 'a']++;
  for (int i = 1; i <= h + w; i++){
    queue<pii> qh, qw;
    for (int j = 1; j <= h; j++)
      if (!eh[j])
        for (int k = 0; k < 26; k++) 
          if (ch[j][k] == lw && lw >= 2){
            qh.push(make_pair(j, k));
            break;
          }
    for (int j = 1; j <= w; j++)
      if (!ew[j])
        for (int k = 0; k < 26; k++) 
          if (cw[j][k] == lh && lh >= 2){
            qw.push(make_pair(j, k));
            break;
          }
    while (qh.size()){
      pii u = qh.front(); eh[u.first] = 1;
      for (int j = 1; j <= w; j++) cw[j][u.second]--;
      qh.pop(); lh--; 
    }
    while (qw.size()){
      pii u = qw.front(); ew[u.first] = 1;
      for (int j = 1; j <= h; j++) ch[j][u.second]--;
      qw.pop(); lw--;
    }
  }
  printf("%d", lh * lw);
  return 0;
}
