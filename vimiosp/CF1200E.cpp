#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
const int N = 1e6 + 5;
int n, pi[N];
string ans; 

int main(){
  scanf("%d", &n);
  for (string a; n--;){
    cin >> a; int k = a.size(), len = min(k, (int)ans.size());
    string b = a + '#' + ans.substr(ans.size() - len, len);
    for (int i = 1; i < b.size(); i++){
      int j = pi[i - 1];
      while (j && b[i] != b[j]) j = pi[j - 1];
      if (b[i] == b[j]) j++;
      pi[i] = j;
    }
    int t = b.size() - 1;
    for (int i = pi[t]; i < k; i++) ans += a[i];
  }
  cout << ans;
  return 0;
}
