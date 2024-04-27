#include <iostream>
#include <algorithm>

using namespace std;
char a[5];

int main(){
  cin >> a;
  reverse(a, a + 3);
  cout << a;
  return 0;
}
