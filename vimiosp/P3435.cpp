#include <iostream>
#include <algorithm>
#define int long long

using namespace std;
const int N = 1e6 + 5;
int n, ans, pi[N];
char s[N];

signed main(){
  scanf("%lld %s", &n, s);
  for (int i = 1; s[i] != '\0'; i++){
    int j = pi[i - 1];
    while (j && s[i] != s[j]) j = pi[j - 1];
    pi[i] = j + (s[i] == s[j]);
  }
  for (int i = 1; s[i]; i++){
    int j = i + 1;
    while (pi[j - 1]) j = pi[j - 1];
    if (pi[i]) pi[i] = j;
    ans += i + 1 - j;
  }
  printf("%lld", ans);
  return 0;
}
