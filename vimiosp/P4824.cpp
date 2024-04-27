#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
const int N = 2e6 + 5;
int pi[N], tp;
string a, b, c;
char t[N];

int main(){
  cin >> a >> b; c = b + '#' + a; t[0] = c[0]; int m = b.size();
  for (int i = 1, j = 0; c[i]; i++){
    t[++tp] = c[i]; j = pi[tp - 1];
    while (j && t[tp] != t[j]) j = pi[j - 1];
    pi[tp] = (j += (t[tp] == t[j]));
    if (pi[tp] == m) tp -= m;
  }
  for (int i = m + 1; i <= tp; i++) printf("%c", t[i]);
  return 0;
}
