#include <iostream>
#include <algorithm>

using namespace std;
int a, b;
void exgcd(int a, int b, int &x, int &y, int &d){
  if (!b) return x = 1, y = 0, d = a, void();
  exgcd(b, a % b, y, x, d), y -= a / b * x;
}

int main(){
  while (cin >> a >> b){
    int x, y, d; exgcd(a, b, x, y, d);
    printf("%d %d %d\n", x, y, d);
  }
  return 0;
}
