#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
const int N = 3e5 + 5;
int n, m, p[N], ans;
char s[N], t[N];

int main(){
  while (scanf("%s", s) != EOF){ 
    t[0] = '!'; t[n = 1] = '@'; m = strlen(s);
    for (int i = 0; s[i]; i++) t[++n] = s[i], t[++n] = '@'; t[++n] = '#';
    for (int i = 1, r = 0, d = 0; t[i]; i++){
      if (i > r) p[i] = 1;
      else p[i] = min(p[2 * d - i], r - i + 1);
      while (t[i - p[i]] == t[i + p[i]]) p[i]++;
      if (i + p[i] - 1 > r) d = i, r = i + p[i] - 1;
    }
    for (int i = 1; t[i]; i++) if (i + p[i] - 1 == n - 1) ans = max(ans, p[i] - 1);
    printf("%s", s); for (int i = m - ans - 1; ~i; i--) printf("%c", s[i]);
    puts("");
    memset(s, 0, sizeof(s));
    memset(t, 0, sizeof(t));
    ans = n = m = 0;
  }
  return 0;
}
